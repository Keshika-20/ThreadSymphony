$threads = @(2,4,8,16,32)
$modes = @(0,1)

# Ensure results directories exist
if (!(Test-Path "results")) { New-Item -ItemType Directory -Path "results" | Out-Null }
if (!(Test-Path "results\logs")) { New-Item -ItemType Directory -Path "results\logs" | Out-Null }
if (!(Test-Path "results\graphs")) { New-Item -ItemType Directory -Path "results\graphs" | Out-Null }

# Initialize CSV with UTF-8 encoding using Set-Content (Out-File is UTF-16 by default)
Set-Content -Path results\metrics.csv -Value "threads,mode,execution_time,throughput" -Encoding UTF8

foreach ($m in $modes) {
    foreach ($t in $threads) {
        $logFile = "results\logs\run_${t}_${m}.txt"
        Write-Host "Running experiment with $t threads, mode=$m..."

        # Run program and capture output
        .\main.exe $t $m | Tee-Object -FilePath $logFile

        # Parse metrics safely
        $execLine = Select-String -Path $logFile -Pattern "Execution Time" -ErrorAction SilentlyContinue
        $thrLine  = Select-String -Path $logFile -Pattern "Throughput" -ErrorAction SilentlyContinue

        if ($execLine -and $thrLine) {
            $exec_time = $execLine.Line.Split()[2]
            $throughput = $thrLine.Line.Split()[1]
            Add-Content -Path results\metrics.csv -Value "$t,$m,$exec_time,$throughput" -Encoding UTF8
        } else {
            Write-Host "⚠️ Metrics not found for $t threads, mode=$m"
        }
    }
}

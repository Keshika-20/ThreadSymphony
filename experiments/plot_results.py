import pandas as pd
import matplotlib.pyplot as plt

# Read CSV with UTF-8 encoding
df = pd.read_csv("results/metrics.csv", encoding="utf-8")

plt.figure(figsize=(10,6))
for mode in [0,1]:
    subset = df[df['mode']==mode]
    plt.plot(subset['threads'], subset['throughput'], marker='o',
             label=f"Throughput (mode={mode})")
    plt.plot(subset['threads'], subset['execution_time'], marker='s',
             label=f"Execution Time (mode={mode})")

plt.xlabel("Number of Threads")
plt.ylabel("Performance Metrics")
plt.title("User-Level Scheduling Efficiency")
plt.legend()
plt.grid(True)
plt.savefig("results/graphs/performance.png")

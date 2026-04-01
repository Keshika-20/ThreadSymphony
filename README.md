# 🎼 ThreadSymphony

### User-Level Thread Scheduling in Oversubscribed Systems

---

## 📌 Overview

In modern systems, applications often create more threads than available CPU cores (**oversubscription**). Traditional OS schedulers rely on **preemption and context switching**, which can degrade performance.

**ThreadSymphony** is a user-level scheduling framework that explores how **custom scheduling strategies** can improve efficiency by reducing unnecessary thread interference.

---

## 🧠 Key Idea

We implement and compare two scheduling strategies:

* 🔹 **Cooperative Scheduling (mode = 0)**
  Threads voluntarily yield CPU → fewer context switches → higher efficiency

* 🔹 **Round-Robin Scheduling (mode = 1)**
  Threads are preempted cyclically → fair but introduces overhead

---

## 📂 Project Structure

```id="struct01"
ThreadSymphony/
│── src/                  # Core implementation
│   ├── main.c            # Entry point
│   ├── scheduler.c       # Scheduling logic
│   ├── workload.c        # CPU & I/O simulations
│   ├── sync.c            # Synchronization primitives
│   ├── metrics.c         # Performance measurement
│   ├── usf.c             # Utility functions
│   ├── *.h               # Header files
│
│── experiments/          # Experiment automation
│   ├── run_experiments.ps1   # Runs multiple test cases
│   ├── plot_results.py       # Generates graphs
│
│── results/
│   ├── metrics.csv       # Collected performance data
│   ├── logs/             # Execution logs
│   ├── graphs/
│       ├── performance.png   # Throughput/Time comparison
│
│── buildandrun.bat       # Quick compile + run script
│── main.exe              # Compiled executable
│── requirements.txt      # Python dependencies (for plots)
│── README.md
```

---

## ⚙️ System Design

The system simulates:

* CPU-bound workloads ⚡
* I/O-bound workloads 🌐
* Thread synchronization using:

  * Mutex locks
  * Semaphores
  * Barriers

A **custom user-level scheduler** controls execution and collects performance metrics.

---

## 🛠️ Technologies Used

* **Language:** C
* **Concepts:**

  * Operating Systems
  * Multithreading
  * Scheduling Algorithms
* **Tools:**

  * GCC
  * Python (for visualization)

---

## ▶️ How to Run

### Step 1: Compile

```id="run01"
gcc -Wall src/main.c src/scheduler.c src/usf.c src/workload.c src/sync.c src/metrics.c -o main.exe -lwinpthread
```

### Step 2: Execute

```id="run02"
./main.exe <num_threads> <mode>
```

### Example:

```id="run03"
./main.exe 16 0   # Cooperative
./main.exe 16 1   # Round Robin
```

---

## 🧪 Running Experiments

Automate testing:

```id="run04"
cd experiments
./run_experiments.ps1
```

---

## 📊 Visualizing Results

Generate graphs:

```id="run05"
python plot_results.py
```

Output:

* 📈 `results/graphs/performance.png`

---

## 📈 Performance Metrics

* ⏱️ Execution Time
* 📊 Throughput (tasks/sec)

---

## 📊 Results

* Cooperative scheduling achieves:

  * Higher throughput
  * Lower execution time

* Round-robin scheduling:

  * Introduces preemption overhead
  * Slightly reduces efficiency

📌 Graph available in:
`results/graphs/performance.png`

---

## 🔬 Research Connection

This project is inspired by a user-space scheduling framework that reduces interference in oversubscribed systems.

Key insight:

> Minimizing unnecessary preemptions improves system performance in multi-threaded workloads 

---

## 🎯 Learning Outcomes

* Understanding oversubscription
* Implementing a scheduler from scratch
* Comparing scheduling strategies
* Analyzing real performance metrics

---

## 👩‍💻 Author

* **Keshika N M (24PW20)**
---

## 📜 Conclusion

This project demonstrates that **user-level scheduling can outperform traditional OS scheduling** in oversubscribed environments by:

* Reducing context switching
* Improving CPU utilization
* Increasing throughput

---

## 🔗 Reference

Research Paper:
https://arxiv.org/pdf/2601.20435

---

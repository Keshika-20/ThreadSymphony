# 🎼 ThreadSymphony

### Improving Thread Scheduling Efficiency in Oversubscribed Environments

---

## 📌 Overview

Modern applications often create more threads than available CPU cores, leading to **thread oversubscription**. In such scenarios, traditional OS schedulers rely on frequent **preemption and context switching**, which introduces overhead and reduces performance.

**ThreadSymphony** is a user-level thread scheduling framework developed as part of the *UNIX System Programming Lab (24XW47)*.
It explores how **user-space scheduling strategies** can improve performance by reducing unnecessary thread interference.

This project is inspired by and partially replicates findings from the research paper:
**“Rethinking Thread Scheduling under Oversubscription: A User-Space Framework”**

---

## 🧠 Core Idea

Instead of relying entirely on OS-level scheduling, this project implements a **user-level scheduler** that controls how threads are executed.

Two scheduling strategies are compared:

* 🔹 **Cooperative Scheduling (mode = 0)**
  Threads voluntarily yield control → minimal context switching

* 🔹 **Round-Robin Scheduling (mode = 1)**
  Threads are preempted cyclically → higher fairness but more overhead

---

## ⚙️ System Design

The system simulates a multithreaded environment with:

* CPU-bound workloads ⚡
* I/O-bound workloads 🌐
* Synchronization mechanisms (mutex, semaphores, barriers)

A custom scheduler manages thread execution and collects performance metrics.

---

## 📂 Project Structure

```
ThreadSymphony/
│── src/
│   ├── main.c          # Entry point (arguments, execution, output)
│   ├── scheduler.c     # Core scheduling logic
│   ├── workload.c      # CPU & I/O workload simulation
│   ├── sync.c          # Synchronization primitives
│   ├── metrics.c       # Performance measurement
│   ├── usf.c           # Utility support functions
│   ├── *.h             # Header files
```

---

## 🛠️ Technologies Used

* **Language:** C
* **Concepts:**

  * Operating Systems
  * Multithreading
  * Thread Scheduling
* **Libraries:**

  * pthread (Windows: `winpthread`)

---

## ▶️ Compilation

From inside the `src` folder:

```
gcc -Wall main.c scheduler.c usf.c workload.c sync.c metrics.c -o ../main.exe -lwinpthread
```

---

## ▶️ Execution

Run from project root:

```
./main.exe <num_threads> <mode>
```

### Parameters:

* `<num_threads>` → number of threads (16, 32, 64, etc.)
* `<mode>`

  * `0` → Cooperative Scheduling
  * `1` → Round-Robin Scheduling

### Example:

```
./main.exe 16 0
./main.exe 16 1
```

---

## 📊 Performance Metrics

The system evaluates scheduling strategies using:

* ⏱️ **Execution Time** → total completion time
* 📈 **Throughput** → tasks per second

---

## 📈 Results & Analysis

* Cooperative scheduling shows **higher throughput**
* Round-robin introduces **preemption overhead**
* Execution time is consistently lower in cooperative mode

These results align with the research findings that:

> Reducing unnecessary preemptions improves performance in oversubscribed systems 

---

## 🔬 Research Connection

This project is inspired by a user-space scheduling framework that:

* Minimizes thread preemption
* Reduces interference between threads
* Improves system efficiency in oversubscribed environments

The research demonstrates improvements of up to **2.4× throughput** in real workloads 

---

## 🎯 Learning Outcomes

* Understanding **thread oversubscription**
* Comparing **preemptive vs cooperative scheduling**
* Implementing a **custom scheduler in user space**
* Measuring real-world performance trade-offs

---

## 👩‍💻 Authors

* **Keshika N M (24PW20)**
---

## 📜 Conclusion

This project demonstrates that **user-level scheduling** can significantly improve performance in oversubscribed environments by:

* Reducing context switching
* Improving CPU utilization
* Increasing throughput

It highlights the importance of **application-aware scheduling strategies** in modern concurrent systems.

---

## 🔗 Reference

Research Paper:
https://arxiv.org/pdf/2601.20435

---

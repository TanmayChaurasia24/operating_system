# Process Schedulers in Operating Systems

Process schedulers are essential components of an operating system responsible for determining the order in which processes are executed by the CPU.

---

## Categories of Scheduling:

- **Non-Preemptive:** In this scheduling type, once a process is given resources, it retains them until the process finishes its execution.
- **Preemptive:** In preemptive scheduling, the operating system assigns resources to a process for a predetermined period and can interrupt or remove the process before it finishes execution.

---

## Types of Process Schedulers:

### 1. Long-Term or Job Scheduler:
- Responsible for bringing new processes to the **Ready State**.
- Controls the degree of multiprogramming by determining how many processes should be present in the ready queue.

### 2. Short-Term or CPU Scheduler:
- Selects one process from the ready state for scheduling onto the running state. 
- This is where all **scheduling algorithms** (such as Round Robin, SJF, etc.) are applied.
- Ensures no **starvation** of processes with a high burst time.
- **Dispatcher:** The dispatcher is responsible for loading the process selected by the short-term scheduler onto the CPU (i.e., moving it from **Ready** to **Running**). It handles **context switching**.

### 3. Medium-Term Scheduler:
- Responsible for **suspending** and **resuming** processes.
- Primarily manages **swapping**, which involves moving processes in and out of memory to improve utilization.

### 4. I/O Schedulers:
- Manages the execution of I/O operations, such as reading and writing to disks or networks.
- Uses algorithms like **FCFS (First-Come, First-Served)** and **Round Robin (RR)** to determine the order of I/O execution.

### 5. Real-Time Schedulers:
- Found in **real-time systems**, ensuring that critical tasks meet their deadlines.
- Can prioritize and schedule tasks using algorithms like **EDF (Earliest Deadline First)** and **RM (Rate Monotonic)**.

---

## Two-State Process Model (Short-Term Scheduling):

The **two-state process model** consists of two states: **Running** and **Not Running**.

- **Running:** A newly created process enters the system in a running state when it is selected for execution.
  
- **Not Running:** Processes that are not currently executing are kept in a **queue** and await their turn for execution. Each entry in the queue contains a pointer to a specific process. **Linked lists** are typically used to implement the queue system.

---

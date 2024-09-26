# Preemptive vs Non-Preemptive Scheduling

## What is Preemptive Scheduling?

Preemptive scheduling is used when a process switches from the running state to the ready state or from the waiting state to the ready state. The resources (mainly CPU cycles) are allocated to the process for a limited amount of time and then taken away. The process is placed back in the ready queue if it still has CPU burst time remaining. It stays in the ready queue until it gets its next chance to execute.

Algorithms based on preemptive scheduling include:
- Round Robin (RR)
- Shortest Remaining Time First (SRTF)
- Priority (preemptive version)

## What is Non-Preemptive Scheduling?

Non-preemptive scheduling is used when a process terminates or switches from running to the waiting state. In this type of scheduling, once the resources (CPU cycles) are allocated to a process, the process holds the CPU until it terminates or reaches a waiting state. Non-preemptive scheduling does not interrupt a process running on the CPU during execution. The CPU is only allocated to another process once the current one completes its CPU burst time.

Algorithms based on non-preemptive scheduling include:
- Shortest Job First (SJF)
- Priority (non-preemptive version)

---

## Key Differences Between Preemptive and Non-Preemptive Scheduling

1. **CPU Allocation**:
   - **Preemptive Scheduling**: The CPU is allocated to processes for a limited time.
   - **Non-Preemptive Scheduling**: The CPU is allocated until the process terminates or switches to the waiting state.

2. **Interrupting Execution**:
   - **Preemptive Scheduling**: The executing process is interrupted in the middle of execution if a higher priority process arrives.
   - **Non-Preemptive Scheduling**: The executing process is not interrupted and runs until it completes its execution.

3. **Overhead**:
   - **Preemptive Scheduling**: There is overhead involved in switching the process from the ready state to the running state and vice versa, as well as maintaining the ready queue.
   - **Non-Preemptive Scheduling**: No overhead is involved in switching the process from the running state to the ready state.

4. **Shared Data Integrity**:
   - **Preemptive Scheduling**: Has to maintain the integrity of shared data, which is cost associative.
   - **Non-Preemptive Scheduling**: There is no such cost for maintaining shared data integrity.

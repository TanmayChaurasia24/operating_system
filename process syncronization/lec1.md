# Process Synchronization

The main objective of process synchronization is to ensure that multiple processes access shared resources without interfering with each other and to prevent inconsistent data due to concurrent access. To achieve this, various synchronization techniques such as semaphores, monitors, and critical sections are used.

## What is a Process?

A process is a program that is currently running or a program under execution. It can be categorized as follows:

### Types of Processes

**On the basis of synchronization**, processes are classified into two types:

- **Independent Process**: The execution of one process does not affect the execution of other processes.
- **Cooperative Process**: A process that can affect or be affected by other processes executing in the system.

## What is a Race Condition?

A **Race Condition** occurs when multiple processes execute the same code or access the same memory or shared variable simultaneously. In this case, there is a possibility that the output or the value of the shared variable could be incorrect. All processes may compete to achieve the correct output, which leads to the race condition.

## Critical Section Problem

A **Critical Section** is a segment of code that can be accessed by only one process at a time. It contains shared variables that must be synchronized to maintain the consistency of data.

The **Critical Section Problem** is about designing a method for cooperative processes to access shared resources without causing inconsistencies in data.

### Requirements for Solving the Critical Section Problem

Any solution to the critical section problem must satisfy the following three requirements:

1. **Mutual Exclusion**: If one process is executing in its critical section, no other process is allowed to execute in the critical section.
   
2. **Progress**: If no process is in the critical section and processes are waiting, then only the processes not executing in their remainder section can participate in deciding which process will enter the critical section next. The decision cannot be postponed indefinitely.

3. **Bounded Waiting**: A bound must exist on the number of times other processes are allowed to enter their critical sections after a process has made a request to enter its critical section, ensuring that the request is eventually granted.

## Peterson’s Solution

**Peterson’s Solution** is a classical software-based approach to solving the critical section problem. It uses two shared variables:

- `boolean flag[i]`: Initialized to `FALSE`. It indicates that no process is initially interested in entering the critical section.
- `int turn`: Indicates which process's turn it is to enter the critical section.

### Working of Peterson’s Solution

Peterson's solution meets all three requirements:

- **Mutual Exclusion**: Only one process can access the critical section at any time.
- **Progress**: A process outside the critical section does not block other processes from entering.
- **Bounded Waiting**: Every process gets a fair chance to enter the critical section.

### Disadvantages of Peterson’s Solution

- **Busy Waiting**: The solution involves busy waiting, which wastes CPU cycles that could be used for other tasks. The line `while(flag[j] && turn == j);` is responsible for this issue.
- **Limited to 2 Processes**: Peterson’s solution works only for two processes.
- **Not Suitable for Modern Architectures**: The solution cannot be used on modern CPU architectures.

---

*This document provides an introduction to process synchronization concepts and solutions. Peterson’s Solution, although classical, has its limitations in modern computing environments.*

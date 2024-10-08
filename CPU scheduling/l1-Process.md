# Process Management

## What is a Process?

A process is a program in execution. For example, when we write a program in C or C++ and compile it, the compiler creates binary code. When we run the binary code, it becomes a process.

## What is Process Management?

Process management controls how processes are carried out and how your computer runs by handling the active processes. Efficient resource allocation, conflict-free process execution, and optimal system performance are all guaranteed by competent process management.

## How Does a Process Look Like in Memory?

- **Text Section**: Includes the current activity represented by the value of the Program Counter.
- **Stack**: Contains temporary data, such as function parameters, return addresses, and local variables.
- **Data Section**: Contains global variables.
- **Heap Section**: Dynamically allocated memory for the process during its runtime.

## Characteristics of a Process:

- **Process ID**: A unique identifier assigned by the operating system.
- **Process State**: Can be ready, running, etc.
- **CPU Registers**: Includes the Program Counter, and CPU registers must be saved and restored when a process is swapped in and out of the CPU.
- **Accounts Information**: Amount of CPU used for process execution, time limits, execution ID, etc.
- **I/O Status Information**: Devices allocated to the process, open files, etc.
- **CPU Scheduling Information**: Priority (e.g., in shortest job first scheduling, a shorter process might have high priority).

All of these attributes of a process are known as the **context of the process**. Each process has its own Process Control Block (PCB), which contains all these attributes.

## States of a Process:

- **New**: A newly created or being-created process.
- **Ready**: After creation, the process moves to the ready state, i.e., ready for execution.
- **Running**: The process currently running on the CPU. Only one process can execute at a time in a single processor.
- **Wait (or Blocked)**: A process waiting for I/O access.
- **Complete (or Terminated)**: The process has finished its execution.
- **Suspended Ready**: If the ready queue is full, some processes are moved to a suspended ready state.
- **Suspended Block**: When the waiting queue is full.

## Context Switching of Process:

The process of saving the context of one process and loading the context of another is called **context switching**. This happens when a process is moved from the running state to the ready state and vice versa.

### When Does Context Switching Happen?

- When a high-priority process comes to the ready state (higher priority than the running process).
- An interrupt occurs.
- User and kernel mode switch (though not necessary).
- Preemptive CPU scheduling is used.

## CPU-Bound vs I/O-Bound Processes:

- **CPU-bound process**: Requires more CPU time and spends more time in the running state.
- **I/O-bound process**: Requires more I/O time and less CPU time, spending more time in the waiting state.

## Process Scheduling Algorithms:

- **First-Come, First-Served (FCFS)**: The simplest scheduling algorithm where processes are executed on a first-come, first-served basis. It is non-preemptive, meaning the process continues until it is finished or waiting for I/O.
  
- **Shortest Job First (SJF)**: A proactive scheduling algorithm that selects the process with the shortest burst time (time to complete execution). It minimizes the average waiting time.
  
- **Round Robin (RR)**: A proactive scheduling algorithm that allocates a fixed amount of time (quantum) for each process. If the process doesn't finish within the quantum, it is blocked and moved to the back of the queue. RR ensures fair distribution of CPU time.
  
- **Priority Scheduling**: Processes are executed based on their priority. Processes with higher priority are executed first. Priorities may depend on process type, importance, or resource requirements.
  
- **Multilevel Queue**: The ready queue is divided into several separate queues, each with different priorities. Processes are assigned to queues based on their priority, and each queue can use its own scheduling algorithm.

## Advantages of Process Management:

- **Running Multiple Programs**: Allows running multiple applications simultaneously, e.g., listening to music while browsing the web.
- **Process Isolation**: Ensures that different programs don’t interfere with each other, preventing one program from crashing another.
- **Fair Resource Use**: Ensures fair sharing of resources like CPU time and memory among all programs.
- **Smooth Switching**: Efficiently switches between programs by saving and loading their states quickly to maintain system responsiveness.

## Disadvantages of Process Management:

- **Overhead**: Managing processes requires system resources (CPU time and memory) which can impact system performance.
- **Complexity**: Designing and maintaining an OS is complicated due to the need for complex scheduling algorithms and resource allocation methods.
- **Deadlocks**: Processes may get stuck in a deadlock, waiting indefinitely for each other when using mechanisms like semaphores and mutex locks.
- **Increased Context Switching**: Frequent context switching in multitasking systems can consume time and computational resources, slowing down the system.

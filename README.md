A process is a program in execution. For example, when we write a program in C or C++ and compile it, the compiler creates binary code.we actually run the binary code, it becomes a process.

What is Process Management?

 It controls how processes are carried out, and controls how your computer runs by handling the active processes.

Efficient resource allocation, conflict-free process execution, and optimal system performance are all guaranteed by competent process management.


How Does a Process Look Like in Memory? 

Text Section: includes the current activity represented by the value of the Program Counter. 

Stack: The stack contains temporary data, such as function parameters, returns addresses, and local variables. 

Data Section: Contains the global variable. 

Heap Section: Dynamically memory allocated to process during its run time. 

Characteristics of a Process

Process Id: A unique identifier assigned by the operating system.
Process State: Can be ready, running, etc.
CPU Registers: Like the Program Counter (CPU registers must be saved and restored when a process is swapped in and out of the CPU)
Accounts Information: Amount of CPU used for process execution, time limits, execution ID, etc
I/O Status Information: For example, devices allocated to the process, open files, etc
CPU Scheduling Information: For example, Priority (Different processes may have different priorities, for example, a shorter process assigned high priority in the shortest job first scheduling)

All of the above attributes of a process are also known as the context of the process. Every process has its own process control block(PCB), i.e. each process will have a unique PCB. All of the above attributes are part of the PCB. 

States of Process

New: Newly Created Process (or) being-created process.
Ready: After the creation process moves to the Ready state, i.e. the process is ready for execution.
Running: Currently running process in CPU (only one process at a time can be under execution in a single processor).
Wait (or Block): When a process requests I/O access.
Complete (or Terminated): The process completed its execution.
Suspended Ready: When the ready queue becomes full, some processes are moved to a suspended ready state
Suspended Block: When the waiting queue becomes full.

Context Switching of Process

The process of saving the context of one process and loading the context of another process is known as Context Switching. loading and unloading the process from the running state to the ready state. 

When Does Context Switching Happen? 

When a high-priority process comes to a ready state (i.e. with higher priority than the running process). 
An Interrupt occurs.
User and kernel-mode switch (It is not necessary though) 
Preemptive CPU scheduling is used. 

CPU-Bound vs I/O-Bound Processes
A CPU-bound process requires more CPU time or spends more time in the running state. An I/O-bound process requires more I/O time and less CPU time. An I/O-bound process spends more time in the waiting state. 







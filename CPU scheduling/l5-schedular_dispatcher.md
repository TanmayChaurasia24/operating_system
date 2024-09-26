# What is a Scheduler?

Schedulers are a special type of operating system software that manage process scheduling in various ways. Their main function is to:

- Select the jobs that are to be submitted to the system.
- Decide which process will run.

## Types of Schedulers

There are three types of schedulers, which are as follows:

### 1. Long-Term (Job) Scheduler

Due to the small size of the main memory, initially all the programs are stored in secondary memory. When they are loaded or stored in main memory, they are known as processes. The long-term scheduler decides how many processes will remain in the ready queue.

### 2. Medium-Term Scheduler

Often, a running process needs an I/O operation that does not require CPU time. When a process needs I/O operation during its execution, the operating system sends that process to a blocked queue. Once the process completes its I/O operation, it is shifted back to the ready queue. These decisions are made by the medium-term scheduler. Medium-term scheduling is part of **swapping**.

### 3. Short-Term (CPU) Scheduler

When there are many processes in the main memory, all are present in the ready queue. Out of all these processes, only one is selected for execution. This decision is made by the short-term scheduler or CPU scheduler.

---

# What is a Dispatcher?

A dispatcher is a special type of program that takes over after the scheduler has completed its task of selecting a process. The dispatcher moves the selected process to the queue it needs to go to.

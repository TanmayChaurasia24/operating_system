# FIFO and Pipes in Operating System

## What are Pipes?
Pipes are a way of connecting two processes where the output of one process serves as the input to another. Pipes are used for **inter-process communication (IPC)**, allowing data to flow from one process to another.

### Types of Pipes
There are two main types of pipes:
1. **Anonymous Pipes (Unnamed Pipes)**:
   - These pipes exist only for the duration of the process and are used for communication between **parent and child processes**.
   - They are unidirectional, meaning data flows only in one direction.
   - Example: `pipe(fd)` creates an anonymous pipe.

2. **Named Pipes (FIFO - First In First Out)**:
   - Named pipes are persistent and can be accessed by unrelated processes.
   - They are also called **FIFO (First In First Out)** because data written first will be read first.
   - Named pipes are identified by a **name in the file system**, which makes them more flexible for inter-process communication.
   - Example: `mknod("myfifo", S_IFIFO | 0666, 0)` creates a FIFO.

## FIFO (First In First Out)
FIFO stands for **First In, First Out**, and it is a type of pipe where the first data written is the first data read, similar to a queue. It is typically used for **communication between unrelated processes**.

### Characteristics of FIFO:
- **Bidirectional**: Data can flow in both directions, but reading and writing require separate processes.
- **Persistence**: Named FIFOs (created using `mknod`) persist in the file system, unlike anonymous pipes.
- **IPC**: FIFOs are used to communicate between processes that may not have a parent-child relationship.

### Example:
```c
mknod("myfifo", S_IFIFO | 0666, 0);

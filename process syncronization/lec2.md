# Inter-Process Communication (IPC)

Inter-Process Communication (IPC) is a method used by processes to coordinate and interact with one another. It allows processes to communicate with each other through different methods.

## Methods of IPC

Processes can communicate with each other using two main methods:

1. **Shared Memory**
2. **Message Passing**

Both methods can be implemented by an operating system, and each serves a different purpose in terms of how processes share information.

### Shared Memory Method

In the **Shared Memory** method, processes communicate by sharing variables. The method relies on the programmer to implement the communication mechanism. Shared memory allows multiple processes to access the same block of memory.

#### Example: Producer-Consumer Problem

In this classic example, two processes — a **Producer** and a **Consumer** — share a common memory space called a buffer.

- The **Producer** produces items and places them in the buffer.
- The **Consumer** takes items from the buffer when needed.

There are two variations of the problem:

- **Unbounded Buffer Problem**: The Producer can keep producing items indefinitely without any restrictions on buffer size.
- **Bounded Buffer Problem**: The buffer has a finite size, and the Producer must wait if the buffer is full before producing more items.

In the **Bounded Buffer Problem**, the processes work as follows:

1. The Producer and Consumer share a common memory buffer.
2. The Producer produces items and stores them in the buffer.
3. If the buffer is full, the Producer waits for the Consumer to consume some items.
4. The Consumer checks if there are any items in the buffer.
5. If the buffer is empty, the Consumer waits for the Producer to produce items.
6. If there are items available, the Consumer consumes them.

This form of communication is efficient for fast data exchange but requires careful synchronization to avoid issues like race conditions.

### Message Passing Method

In the **Message Passing** method, processes communicate with each other by sending and receiving messages without sharing any memory. Processes can exchange information even if they reside on different systems.

#### Steps in Message Passing

1. **Establish a Communication Link**: A link between the processes is established, and if it already exists, the processes can directly start communicating.
2. **Exchange Messages**: Processes exchange messages using basic operations.

At least two primitives are required for message passing:
- `send(message, destination)` or `send(message)`
- `receive(message, host)` or `receive(message)`

A standard message contains:
- **Header**: Contains the message type, destination ID, source ID, message length, and control information. The control information may include buffer handling rules, sequence numbers, and priority.
- **Body**: Contains the actual content of the message.

Messages are typically sent in **FIFO (First In, First Out)** order, ensuring that messages are processed in the order they were sent.

#### Message Passing Through Communication Link

A communication link has a certain capacity that determines how many messages can be held in it at any given time.

There are two types of communication links:

1. **Direct Communication**: Processes use a specific process identifier for communication. For example, a print server receiving messages directly from clients. However, identifying the sender process ahead of time can be difficult in some cases.

2. **Indirect Communication**: This type uses a shared mailbox (or port) that acts as a queue for messages. The sender puts a message in the mailbox, and the receiver retrieves it later. This is useful when multiple processes need to communicate indirectly.

---

*This document provides an overview of Inter-Process Communication (IPC) methods, including Shared Memory and Message Passing. These methods enable efficient communication and synchronization between processes.*

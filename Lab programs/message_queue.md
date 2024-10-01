# Message Queues in Operating Systems

## What is a Message Queue?

A **Message Queue** is a method used for **inter-process communication (IPC)** that allows different processes to send and receive messages. The messages are stored in a queue until the receiving process retrieves them. Message queues are widely used to enable communication between processes that are decoupled, meaning the sender and receiver don’t need to communicate directly at the same time.

Message queues provide:

- **Asynchronous communication**: Processes don't have to wait for each other.
- **Reliability**: Messages can be stored until they are successfully processed.
- **Decoupling**: Sender and receiver processes don’t have to interact directly.

---

## Components of a Message Queue

1. **Message**: The unit of data sent from one process to another.
2. **Queue**: A storage system that holds the messages until they are retrieved.
3. **Sender Process**: The process that sends the message.
4. **Receiver Process**: The process that reads the message from the queue.

---

## How Message Queues Work

### Sending a Message

A process that wants to communicate sends a message to the message queue. This message is placed into the queue until it is read by the receiving process.


### Receiving a Message

The receiving process fetches the message from the queue. After being read, the message is removed from the queue.


### Message Ordering

Message queues generally follow a **FIFO (First In, First Out)** order, ensuring that the first message to enter the queue is the first message retrieved by the receiver.

---

## Types of Message Queues

1. **System V Message Queues**:
   - Used in Unix-like systems.
   - One of the older methods for IPC.
   
2. **POSIX Message Queues**:
   - A modern implementation that is faster and offers more flexibility compared to System V.
   - Used in POSIX-compliant operating systems.

---

## Advantages of Message Queues

1. **Asynchronous Communication**: The sender and receiver can work independently, without waiting for each other.
2. **Message Decoupling**: Sender and receiver do not need to communicate directly or run at the same time.
3. **Reliability**: Messages are stored in the queue until successfully received.
4. **FIFO Order**: Messages are retrieved in the same order they were sent.
5. **Load Balancing**: Multiple receivers can read from the same queue, distributing the workload evenly.

---

## Message Queue System Calls

In message queues, several system calls allow processes to send and receive messages.

### Common System Calls

1. **msgget()**: Creates a new message queue or accesses an existing one.
2. **msgsnd()**: Sends a message to a queue.
3. **msgrcv()**: Receives a message from the queue.
4. **msgctl()**: Performs various operations on a queue (e.g., removing the queue).

### Example of System Calls

#### msgget()

```c
int msgget(key_t key, int msgflg);

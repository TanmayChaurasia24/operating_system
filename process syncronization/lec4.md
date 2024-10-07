# Semaphores

## Definition

Semaphores are synchronization primitives used to coordinate the activities of multiple processes in a computer system. They are crucial for enforcing mutual exclusion, avoiding race conditions, and implementing synchronization between processes. The operations associated with semaphores are:

- **Wait (P)**: This operation decrements the value of the semaphore.
- **Signal (V)**: This operation increments the value of the semaphore.

When the value of a semaphore is zero, any process that attempts to perform a wait operation will be blocked until another process performs a signal operation.

## Types of Semaphores

There are two primary types of semaphores:

1. **Binary Semaphore**: Also known as a mutex lock, a binary semaphore can hold only two values: 0 and 1. It is initialized to 1 and is used to manage access to a critical section by multiple processes.

2. **Counting Semaphore**: This type of semaphore can have a value that ranges over an unrestricted domain. It is used to control access to resources that have multiple instances.

## Implementation of Binary Semaphores

```c
struct semaphore {
    enum value(0, 1); // Semaphore value

    // Queue containing all Process Control Blocks (PCBs)
    // corresponding to processes that got blocked
    // while performing the down operation.
    Queue<process> q;
};

void P(semaphore s) {
    if (s.value == 1) {
        s.value = 0; // Acquire the semaphore
    } else {
        // Add the process to the waiting queue
        q.push(P);
        sleep(); // Block the process
    }
}

void V(semaphore s) {
    if (s.q is empty) {
        s.value = 1; // Release the semaphore
    } else {
        // Select a process from the waiting queue
        Process p = q.front();
        // Remove the process from waiting as it has been
        // sent for critical section
        q.pop();
        wakeup(p); // Wake up the process
    }
}

## Implementation of Counting Semaphores

```c
struct Semaphore {
    int value; // Semaphore value

    // Queue containing all Process Control Blocks (PCBs)
    // corresponding to processes that got blocked
    // while performing the down operation.
    Queue<process> q;
};

void P(Semaphore s) {
    s.value = s.value - 1; // Decrement semaphore value
    if (s.value < 0) {
        // Add process to queue
        // Here p is a process which is currently executing
        q.push(p);
        block(); // Block the process
    } else {
        return; // Semaphore acquired successfully
    }
}

void V(Semaphore s) {
    s.value = s.value + 1; // Increment semaphore value
    if (s.value <= 0) {
        // Remove process p from queue
        Process p = q.pop();
        wakeup(p); // Wake up the process
    } else {
        return; // Semaphore released successfully
    }
}


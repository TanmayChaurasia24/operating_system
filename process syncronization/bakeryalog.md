# Bakery Algorithm

## What is the Bakery Algorithm?

The **Bakery Algorithm**, developed by **Leslie Lamport**, is a solution to the critical section problem that ensures **mutual exclusion**, **fairness**, and **bounded waiting** when multiple processes want to access a shared resource. The algorithm mimics the way customers in a bakery take numbered tickets and wait their turn to be served.

## Components of the Bakery Algorithm

The Bakery Algorithm uses two key components:

1. **number[]**: 
   - Each process has a "ticket" or number, stored in this array. The lower the number, the sooner the process can enter the critical section.

2. **choosing[]**: 
   - This boolean array helps prevent conflicts when processes are picking numbers. It indicates whether a process is currently choosing a number.

## How the Bakery Algorithm Works

### Step-by-Step Explanation:

1. **Process Chooses a Number**:
   - When a process wants to enter the critical section, it sets `choosing[i] = true` to indicate that it is choosing a number.
   - It looks at the numbers of all other processes and assigns itself a number that is **one greater than the largest number** currently assigned to any other process.
   - It then sets `choosing[i] = false` to indicate that it has finished choosing a number.

2. **Waiting for Turn**:
   - Before entering the critical section, the process checks if there are any other processes with:
     - A **smaller number**.
     - The **same number but a lower process ID** (for tie-breaking).
   - If such a process exists, it waits until it's the process's turn.

3. **Entering the Critical Section**:
   - Once it's the process's turn (i.e., it has the smallest number), it enters the critical section and performs its tasks.

4. **Finishing**:
   - After completing its work, the process sets `number[i] = 0`, indicating that it is no longer in the critical section and does not need to enter again until the next request.

### Example Scenario:

- **Process 1** wants to enter the critical section:
  - It sets `choosing[1] = true`, chooses the next available number (e.g., `number[1] = 5`), then sets `choosing[1] = false`.
  - **Process 2** also wants to enter the critical section but picks a higher number (e.g., `number[2] = 6`), so it waits until **Process 1** finishes.

- When **Process 1** is done, it sets `number[1] = 0`, allowing **Process 2** to proceed next.

## Code Example

Here is a basic implementation of the Bakery Algorithm for two processes.

```c
#define N 2  // Number of processes

int number[N];  // Array to store the ticket number for each process
int choosing[N];  // Array to indicate if a process is choosing a number

void lock(int i) {
    choosing[i] = 1;  // Process i is choosing a number
    number[i] = 1 + max(number[0], number[1]);  // Choose the maximum number + 1
    choosing[i] = 0;  // Done choosing

    for (int j = 0; j < N; j++) {
        // Wait until process j finishes choosing its number
        while (choosing[j]);
        // Wait if process j has a smaller number or the same number but a smaller ID
        while (number[j] != 0 && (number[j] < number[i] || (number[j] == number[i] && j < i)));
    }
}

void unlock(int i) {
    number[i] = 0;  // Process i is done and leaves the critical section
}

void critical_section() {
    // Code for the critical section goes here
}

void process(int i) {
    while (true) {
        lock(i);  // Acquire the lock (entering critical section)
        critical_section();  // Critical section
        unlock(i);  // Release the lock (exiting critical section)
    }
}

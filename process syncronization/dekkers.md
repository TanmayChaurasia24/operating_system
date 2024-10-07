# Dekker's Solution

## What is Dekker's Solution?

Dekker's Solution is an algorithm designed to solve the **critical section problem** for two processes. The critical section problem is when two or more processes need to access shared resources but must do so without interfering with each other. Dekker's solution ensures that:

- Only one process is allowed to enter the critical section at a time (Mutual Exclusion).
- The processes take turns fairly.
- No process gets stuck waiting forever (Bounded Waiting).

## Components of Dekker's Solution

1. **Flags**: 
   - Each process has a flag that indicates whether it wants to enter the critical section.
   - For example, `flag[0]` for Process 1 and `flag[1]` for Process 2.

2. **Turn Variable**: 
   - A shared variable, `turn`, determines whose turn it is to try entering the critical section. If `turn` is 0, Process 1 has the priority. If `turn` is 1, Process 2 has the priority.

## How Dekker's Solution Works

### Step-by-Step Explanation:

1. **Process 1** sets its flag (`flag[0]`) to indicate it wants to enter the critical section.

2. **Process 1** then checks if **Process 2** also wants to enter:
   - If **Process 2** does **not** want to enter, **Process 1** can proceed and enter the critical section.
   - If **Process 2** also wants to enter and it’s **Process 2's turn**, then **Process 1** waits until **Process 2** is done.

3. If **Process 1** enters the critical section, it completes its work and then:
   - Resets its flag (`flag[0] = false`) to indicate it no longer needs to be in the critical section.
   - Sets the turn to **Process 2** (`turn = 1`) so **Process 2** can take its turn.

4. **Process 2** follows the same logic using its own flag (`flag[1]`).

### Example Walkthrough:

- **Process 1** wants to enter its critical section:
  - It sets `flag[0] = true` to show it wants access.
  - If **Process 2** also wants access but it's **Process 1's turn**, **Process 1** will enter.
  - If it's **Process 2's turn**, **Process 1** will wait.

- Once **Process 1** finishes, it will reset its flag and change the turn to **Process 2**, allowing it to enter.

## Summary of Key Points:

- **Mutual Exclusion**: Only one process can enter the critical section at a time.
- **Turn-taking**: Processes take turns entering the critical section, ensuring fairness.
- **Bounded Waiting**: No process is forced to wait forever.

## Code Example

```c
int flag[2] = {0, 0};  // Flags for process 1 and process 2
int turn = 0;          // Shared variable to indicate whose turn it is

// Process 1
void process1() {
    flag[0] = 1;  // Process 1 wants to enter critical section
    while (flag[1]) {  // Check if Process 2 wants to enter
        if (turn == 1) {
            flag[0] = 0;  // Give up and wait
            while (turn == 1);  // Wait for Process 2 to finish
            flag[0] = 1;  // Retry to enter critical section
        }
    }
    // Critical Section
    // Do work here...

    turn = 1;  // Give the turn to Process 2
    flag[0] = 0;  // Process 1 leaves critical section
}

// Process 2
void process2() {
    flag[1] = 1;  // Process 2 wants to enter critical section
    while (flag[0]) {  // Check if Process 1 wants to enter
        if (turn == 0) {
            flag[1] = 0;  // Give up and wait
            while (turn == 0);  // Wait for Process 1 to finish
            flag[1] = 1;  // Retry to enter critical section
        }
    }
    // Critical Section
    // Do work here...

    turn = 0;  // Give the turn to Process 1
    flag[1] = 0;  // Process 2 leaves critical section
}

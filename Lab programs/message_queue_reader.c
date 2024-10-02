#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Define the structure for the message queue
struct mesg_buffer {
    long mesg_type;       // This is used to identify the type of message. It must be of type 'long'.
    char mesg_text[100];  // This array holds the actual message data to be received from the message queue.
} message;  // Creating an instance of the structure 'mesg_buffer' called 'message'.

int main() {
    key_t key;  // 'key_t' is a data type used to store the key that uniquely identifies the message queue.
    int msgid;  // 'msgid' will hold the identifier for the message queue created or accessed by the system.

    // Step 1: Generate a unique key using the 'ftok' function.
    // 'ftok' generates a unique key for the message queue using the file path ("progfile") and a number (65).
    // This key is used to uniquely identify the message queue in the system.
    key = ftok("progfile", 65);

    // Step 2: Get the message queue ID.
    // 'msgget' either creates a new message queue or accesses an existing one based on the key generated.
    // The '0666' is the permission (read & write for everyone), and 'IPC_CREAT' creates the queue if it doesn't exist.
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Step 3: Receive the message from the message queue.
    // 'msgrcv' is used to receive a message from the message queue.
    // - The first argument is the message queue ID (msgid).
    // - The second argument is the address of the message buffer where the received message will be stored (&message).
    // - The third argument is the size of the message buffer (sizeof(message)).
    // - The fourth argument is the message type (1, meaning we are fetching messages of type 1).
    // - The fifth argument is a flag (0 means no special flags, and the function will wait if no messages are available).
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    // Step 4: Print the message received.
    // After the message is received from the queue, it's stored in the 'mesg_text' field.
    // This line prints the message that was received from the message queue.
    printf("Data received is: %s\n", message.mesg_text);

    // Step 5: Remove the message queue from the system.
    // 'msgctl' is used to control message queues. Here, 'IPC_RMID' removes (deletes) the message queue.
    // This operation ensures that the message queue is cleaned up after receiving the message.
    // The third argument is set to 'NULL' because we don't need to pass any additional parameters for removal.
    msgctl(msgid, IPC_RMID, NULL);

    return 0;  // Exiting the program successfully.
}

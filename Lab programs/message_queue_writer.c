#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 10  // Defining a constant MAX to limit the size of input data to 10 characters.

// Structure for message queue
struct mesg_buffer {
    long mesg_type;     // This field is used to identify the type of message. It must be of type 'long'.
    char mesg_text[100]; // This array will hold the actual message data that we want to send.
} message;  // Creating an instance of the structure 'mesg_buffer' called 'message'.

int main() {
    key_t key;  // 'key_t' is a data type used to store the key that uniquely identifies the message queue.
    int msgid;  // 'msgid' will hold the identifier for the message queue created by the system.

    // Step 1: Generating a unique key for the message queue using the 'ftok' function.
    // The first argument is the name of a file (here, "progfile") and the second is an arbitrary number (65).
    // 'ftok' generates a unique key based on the file path and the number, used to identify the message queue.
    key = ftok("progfile", 65);

    // Step 2: Creating a message queue or accessing it if it already exists.
    // 'msgget' takes the generated key and permission flags. 
    // '0666' is the permission flag (read & write permissions for everyone), and 'IPC_CREAT' creates the queue if it doesn't exist.
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Step 3: Setting the message type. 
    // 'mesg_type' is set to 1 to identify this message as type 1 (you can use different numbers for different message types).
    message.mesg_type = 1;

    // Step 4: Taking input from the user.
    // 'fgets' reads the input from the user (stdin) and stores it in 'mesg_text'.
    // The input will be limited to 'MAX' characters (10 in this case).
    printf("Write data: ");
    fgets(message.mesg_text, MAX, stdin);

    // Step 5: Sending the message to the message queue.
    // 'msgsnd' is used to send a message to the message queue.
    // - The first argument is the message queue identifier (msgid).
    // - The second argument is the address of the message to be sent (&message).
    // - The third argument is the size of the message structure.
    // - The fourth argument is a flag (0 means no special flags).
    msgsnd(msgid, &message, sizeof(message), 0);

    // Step 6: Printing the message that was sent.
    // After the message is sent, we print the data stored in 'mesg_text'.
    printf("Data sent is: %s\n", message.mesg_text);

    return 0;  // Exiting the program successfully.
}

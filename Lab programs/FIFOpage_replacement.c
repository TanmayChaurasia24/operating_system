#include <stdio.h>
#include <stdlib.h>

// Function to implement FIFO page replacement algorithm
void fifoPageReplacement(int pages[], int n, int frames) {
    int *frame = malloc(frames * sizeof(int)); // Array to represent frames in memory
    int front = 0; // Points to the oldest page in the frame (FIFO queue)
    int pageFaults = 0, pageHits = 0;

    // Initialize all frames to -1 to indicate they are empty
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    printf("\nPage Reference \t Frames \t Status\n");

    // Process each page in the page reference string
    for (int i = 0; i < n; i++) {
        int flag = 0; // Flag to check if a page hit occurs

        // Check if the page is already in one of the frames (Page Hit)
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                flag = 1; // Page hit found
                pageHits++; // Increment page hit count
                break;
            }
        }

        // If the page is not found in the frame (Page Fault occurs)
        if (flag == 0) {
            frame[front] = pages[i]; // Replace the oldest page (FIFO principle)
            front = (front + 1) % frames; // Update the front pointer (circular queue)
            pageFaults++; // Increment page fault count
        }

        // Print the current page and frame contents
        printf("%d \t\t\t", pages[i]);
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1) {
                printf("%d ", frame[j]); // Print occupied frame
            } else {
                printf("- "); // Print empty frame
            }
        }
        // Print whether it's a hit or miss
        if (flag)
            printf("\t Hit\n");
        else
            printf("\t Miss\n");
    }

    // Summary of page faults, hits, and rates
    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);
    printf("Page Fault Rate: %.2f%%\n", ((float)pageFaults / n) * 100);
    printf("Page Hit Rate: %.2f%%\n", ((float)pageHits / n) * 100);

    free(frame); // Free the allocated memory for frames
}

int main() {
    int n, frames;

    // Input number of pages in the reference string
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]); // Read each page in the reference string
    }

    // Input the number of frames in memory
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    // Call the FIFO page replacement function
    fifoPageReplacement(pages, n, frames);

    return 0;
}

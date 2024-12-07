#include <stdio.h>
#include <stdlib.h>

// Function to find the position of the least recently used page
int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

// Function to implement the LRU page replacement algorithm
void lruPageReplacement(int pages[], int n, int frames) {
    int *frame = malloc(frames * sizeof(int)); // Stores pages in memory frames
    int *time = malloc(frames * sizeof(int));  // Tracks last used time of each frame
    int count = 0, pageFaults = 0, pageHits = 0;

    // Initialize frames to -1 to indicate they are empty
    for (int i = 0; i < frames; ++i) {
        frame[i] = -1;
    }

    printf("\nPage Reference \t Frames \t Status\n");

    for (int i = 0; i < n; ++i) {
        int flag1 = 0, flag2 = 0;

        // Check if the page is already in one of the frames (Page Hit)
        for (int j = 0; j < frames; ++j) {
            if (frame[j] == pages[i]) {
                flag1 = flag2 = 1;
                time[j] = ++count; // Update the last used time
                pageHits++;
                break;
            }
        }

        // Page Fault occurs if the page is not in any frame
        if (flag1 == 0) {
            for (int j = 0; j < frames; ++j) {
                if (frame[j] == -1) { // Empty frame found
                    frame[j] = pages[i];
                    time[j] = ++count; // Update the last used time
                    pageFaults++;
                    flag2 = 1;
                    break;
                }
            }
        }

        // Replace the least recently used page if no empty frame is available
        if (flag2 == 0) {
            int pos = findLRU(time, frames);
            frame[pos] = pages[i];
            time[pos] = ++count;
            pageFaults++;
        }

        // Display the current state of frames
        printf("%d \t\t\t", pages[i]);
        for (int j = 0; j < frames; ++j) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        if (flag1)
            printf("\t Hit\n");
        else
            printf("\t Miss\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);
    printf("Page Fault Rate: %.2f%%\n", ((float)pageFaults / n) * 100);
    printf("Page Hit Rate: %.2f%%\n", ((float)pageHits / n) * 100);

    free(frame);
    free(time);
}

int main() {
    int n, frames;

    // Input number of pages and frames
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    lruPageReplacement(pages, n, frames);

    return 0;
}

// input
Enter the number of pages: 9
Enter the page reference string: 1 3 0 3 5 6 3 3 1
Enter the number of frames: 3

// output
Page Reference     Frames          Status
1                  1 - -          Miss
3                  1 3 -          Miss
0                  1 3 0          Miss
3                  1 3 0          Hit
5                  5 3 0          Miss
6                  5 6 0          Miss
3                  3 6 0          Miss
3                  3 6 0          Hit
1                  1 6 0          Miss

Total Page Faults: 6
Total Page Hits: 3
Page Fault Rate: 66.67%
Page Hit Rate: 33.33%

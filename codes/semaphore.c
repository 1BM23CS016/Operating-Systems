#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 3  // Maximum buffer size

int mutex = 1;  // Binary semaphore (1 = unlocked, 0 = locked)
int full = 0;   // Number of full slots
int empty = BUFFER_SIZE;  // Number of empty slots
int x = 0;  // Shared resource (number of items in buffer)

void wait(int *S) {
    while (*S <= 0);  // Busy wait (Not recommended for real OS)
    (*S)--;
}

void signal(int *S) {
    (*S)++;
}

void producer() {
    wait(&mutex);  // Lock critical section
    wait(&empty);  // Check for available buffer space

    x++;
    printf("Producer has produced: Item %d\n", x);

    signal(&full);  // Increase full slots
    signal(&mutex); // Unlock critical section
}

void consumer() {
    wait(&mutex);  // Lock critical section
    wait(&full);  // Check if buffer has items

    printf("Consumer has consumed: Item %d\n", x);
    x--;

    signal(&empty);  // Increase empty slots
    signal(&mutex); // Unlock critical section
}

int main() {
    int choice;

    printf("\nEnter 1.Producer 2.Consumer 3.Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (empty > 0)
                    producer();
                else
                    printf("Buffer is full!\n");
                break;
            case 2:
                if (full > 0)
                    consumer();
                else
                    printf("Buffer is empty!\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

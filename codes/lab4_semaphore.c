#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 3

int mutex = 1; //0:lock 1:unlock
int full = 0;
int empty = BUFFER_SIZE;
int x = 0; //produced items

void wait(int S) {
    while (S <= 0);
    (S)--;
}
void signal(int S) {
    (S)++;
}
void producer() {
    wait(mutex);
    wait(empty);
    x++;
    printf("Producer has produced: Item %d\n", x);
    signal(full);
    signal(mutex);
}

void consumer() {
    wait(mutex);
    wait(full);
    printf("Consumer has consumed: Item %d\n", x);
    x--;
    signal(empty);
    signal(mutex);
}
int main() {
    int choice;
    printf("\nEnter 1.Producer 2.Consumer 3.Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: if (empty > 0){
                    producer();
                    }
                else{
                    printf("Buffer is full!\n");
                    }
                     break;
            case 2: if (full > 0){
                    consumer();
                    }
                else{
                    printf("Buffer is empty!\n");
                    }
                    break;
            case 3: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}


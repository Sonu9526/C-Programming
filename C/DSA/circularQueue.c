#include <stdio.h>

void insert();
void delete();
void display();
int item, q[50], front = -1, rear = -1, max;

int main() {
    int n;
    
    printf("Enter the maximum size: \n");
    scanf("%d", &max);

    while (1) {
        printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &n);

        switch (n) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void insert() {
    if ((front == 0 && rear == max - 1) || (rear + 1) % max == front) {
        printf("Overflow\n");
    } else {
        if (front == -1) {  // Initial condition, queue is empty
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % max;  // Circular increment
        }
        printf("Enter the element to be inserted:\n");
        scanf("%d", &item);
        q[rear] = item;
    }
}

void delete() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        item = q[front];
        printf("The deleted element is %d\n", item);
        if (front == rear) {  // Queue becomes empty after deletion
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % max;  // Circular increment
        }
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        if (rear >= front) {
            for (i = front; i <= rear; i++) {
                printf("%d ", q[i]);
            }
        } else {  // Circular queue condition
            for (i = front; i < max; i++) {
                printf("%d ", q[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d ", q[i]);
            }
        }
        printf("\n");
    }
}

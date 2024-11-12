// #include<stdio.h>
// #include<stdlib.h>
// // Define the node structure
// struct Node {
//     int data;
//     struct Node* next;
// };
// // Initialize the top pointer as NULL, meaning an empty stack
// struct Node* top = NULL;
// // Check if the stack is empty
// int isEmpty() {
//     return top == NULL;
// }
// // Push an element onto the stack
// void push() {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
//     int value;
//     printf("Enter the value you want to push: ");
//     scanf("%d", &value);

//     newNode->data = value;
//     newNode->next = top;  // New node points to the current top
//     top = newNode;        // Update top to be the new node
//     printf("%d is pushed to the stack\n", value);
// }
// // Pop an element from the stack
// void pop() {
//     if (isEmpty()) {
//         printf("Stack underflow\n");
//         return;
//     }
//     struct Node* temp = top;
//     int poppedValue = temp->data;
//     top = top->next;  // Move the top to the next node
//     free(temp);       // Free the memory of the popped node
//     printf("%d is popped out from the stack\n", poppedValue);
// }
// // Display the stack elements
// void display() {
//     if (isEmpty()) {
//         printf("Stack is empty\n");
//         return;
//     }
//     struct Node* temp = top;
//     printf("Stack elements are:\n");
//     while (temp != NULL) {
//         printf("%d->", temp->data);
//         temp = temp->next;
//     }

// }
// int main() {
//     int choice;

//     while (1) {
//         printf("\nStack Operations:\n");
//         printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 push();
//                 break;

//             case 2:
//                 pop();
//                 break;

//             case 3:
//                 display();
//                 break;

//             case 4:
//                 return 0;

//             default:
//                 printf("Please choose a valid option\n");
//                 break;
//         }
//     }

//     return 0;
// }








#include<stdio.h>
#include<stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Initialize the top pointer as NULL, meaning an empty stack
struct Node* top = NULL;

// Check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Push an element onto the stack
void push() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    int value;
    printf("Enter the value you want to push: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = top;  // New node points to the current top
    top = newNode;        // Update top to be the new node
    printf("%d is pushed to the stack\n", value);
}

// Pop an element from the stack
void pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return;
    }
    struct Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;  // Move the top to the next node
    free(temp);       // Free the memory of the popped node
    printf("%d is popped out from the stack\n", poppedValue);
}

// Display the stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); // End of the stack display
}

// Search for an element in the stack
void search() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    int target, position = 1;
    printf("Enter the value you want to search: ");
    scanf("%d", &target);

    struct Node* temp = top;
    while (temp != NULL) {
        if (temp->data == target) {
            printf("Value %d found at position %d from top\n", target, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Value %d not found in the stack\n", target);
}

int main() {
    int choice;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                search();
                break;

            case 5:
                return 0;

            default:
                printf("Please choose a valid option\n");
                break;
        }
    }

    return 0;
}

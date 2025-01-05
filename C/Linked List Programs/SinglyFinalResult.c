#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
    int data;
    struct node *link;
};
struct node *head = NULL;
int count = 0;

void insertAtBeginning() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the new node: ");
    scanf("%d", &newNode->data);
    newNode->link = head;
    head = newNode;
    count++;
}

void insertAtEnd() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the new node: ");
    scanf("%d", &newNode->data);
    newNode->link = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
    count++;
}

void insertAfterGivenLocation() {
    int i = 1;
    int pos;
    struct node *temp = head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count) {
        printf("Invalid Position\n");
        return;
    }

    printf("Enter the data for the new node: ");
    scanf("%d", &newNode->data);

    while (i < pos) {
        temp = temp->link;
        i++;
    }

    newNode->link = temp->link;
    temp->link = newNode;
    count++;
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    head = head->link;
    free(temp);
    count--;
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->link == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        while (temp->link->link != NULL) {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
    count--;
}

void deleteFromPosition() {
    int pos, i = 1;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count) {
        printf("Invalid Position\n");
        return;
    }

    struct node *temp = head, *prev;
    if (pos == 1) {
        head = head->link;
        free(temp);
    } else {
        while (i < pos) {
            prev = temp;
            temp = temp->link;
            i++;
        }
        prev->link = temp->link;
        free(temp);
    }
    count--;
}

void displayList() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Current List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void main() {
    int choice;
    clrscr();
    while (1) {
        printf("\nMenu:\n1. Insert at Beginning\n2. Insert at End\n3. Insert After Given Location\n4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n7. Display List\n8. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAfterGivenLocation();
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                deleteFromPosition();
                break;
            case 7:
                displayList();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    getch();
}

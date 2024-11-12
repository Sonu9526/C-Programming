#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 32  

void displaySet(int set) {
    printf("{ ");
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        if (set & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int addElement(int set, int element) {
    if (element >= 0 && element < MAX_SIZE) {
        set = set | (1 << element); 
    }
    return set;
}

int unionSet(int set1, int set2) {
    return set1 | set2;  
    
}

int intersectionSet(int set1, int set2) {
    return set1 & set2;  
}


int differenceSet(int set1, int set2) {
    return set1 & ~set2; 
}

int main() {
    int set1 = 0, set2 = 0;
    int choice, element;

    printf("Set Operations using Bit Strings\n");

    while (1) {
        printf("\n1. Add Element to Set 1\n");
        printf("2. Add Element to Set 2\n");
        printf("3. Union of Set 1 and Set 2\n");
        printf("4. Intersection of Set 1 and Set 2\n");
        printf("5. Difference of Set 1 and Set 2 (Set 1 - Set 2)\n");
        printf("6. Display Set 1\n");
        printf("7. Display Set 2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add to Set 1: ");
                scanf("%d", &element);
                set1 = addElement(set1, element);
                break;
            case 2:
                printf("Enter element to add to Set 2: ");
                scanf("%d", &element);
                set2 = addElement(set2, element);
                break;
            case 3:
                printf("Union of Set 1 and Set 2: ");
                displaySet(unionSet(set1, set2));
                break;
            case 4:
                printf("Intersection of Set 1 and Set 2: ");
                displaySet(intersectionSet(set1, set2));
                break;
            case 5:
                printf("Difference of Set 1 and Set 2 (Set 1 - Set 2): ");
                displaySet(differenceSet(set1, set2));
                break;
            case 6:
                printf("Set 1: ");
                displaySet(set1);
                break;
            case 7:
                printf("Set 2: ");
                displaySet(set2);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

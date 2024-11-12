#include <stdio.h>
#include <stdlib.h>

// Structure to represent a disjoint set
struct DisjointSet {
    int *parent;
    int *rank;
    int n;
};

// Function to create disjoint sets with `n` elements (0 to n-1)
void createSet(struct DisjointSet *ds, int n) {
    ds->n = n;
    ds->parent = (int *)malloc(n * sizeof(int));
    ds->rank = (int *)malloc(n * sizeof(int));
    // Initially, all elements are in their own set
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;  // Each element is its own parent
        ds->rank[i] = 0;    // Rank is initially 0
    }
}

// Function to add a new element to the disjoint set
void addElement(struct DisjointSet *ds, int newElement) {
    ds->n++;
    ds->parent = (int *)realloc(ds->parent, ds->n * sizeof(int));
    ds->rank = (int *)realloc(ds->rank, ds->n * sizeof(int));
    ds->parent[newElement] = newElement;
    ds->rank[newElement] = 0;
}

// Function to find the representative (root) of the set containing element `x`
// Path compression is used here for optimization
int findSet(struct DisjointSet *ds, int x) {
    if (ds->parent[x] != x) {
        // Recursively find the root and compress the path
        ds->parent[x] = findSet(ds, ds->parent[x]);
    }
    return ds->parent[x];
}

// Function to perform the union of two sets
// Union by rank is used here for optimization
void unionSets(struct DisjointSet *ds, int x, int y) {
    int rootX = findSet(ds, x);
    int rootY = findSet(ds, y);
    // If they are already in the same set, no need to union
    if (rootX == rootY)
        return;
    // Union by rank
    if (ds->rank[rootX] < ds->rank[rootY]) {
        ds->parent[rootX] = rootY;  // Attach smaller tree under the root of the bigger tree
    } else if (ds->rank[rootX] > ds->rank[rootY]) {
        ds->parent[rootY] = rootX;
    } else {
        ds->parent[rootY] = rootX;
        ds->rank[rootX]++;  // If ranks are the same, increment the rank
    }
}

// Function to display the disjoint sets
void displaySets(struct DisjointSet *ds) {
    printf("Element: ");
    for (int i = 0; i < ds->n; i++) {
        printf("%d ", i);
    }
    printf("\nParent:  ");
    for (int i = 0; i < ds->n; i++) {
        printf("%d ", ds->parent[i]);
    }
    printf("\n");
}

int main() {
    int n, choice, x, y, newElement;
    struct DisjointSet ds;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    // Create `n` disjoint sets
    createSet(&ds, n);
    while (1) {
        printf("\n1. Find Set\n");
        printf("2. Union Sets\n");
        printf("3. Add Element\n");
        printf("4. Display Sets\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to find its set: ");
                scanf("%d", &x);
                printf("Set representative for element %d is: %d\n", x, findSet(&ds, x));
                break;
            case 2:
                printf("Enter two elements to perform union: ");
                scanf("%d %d", &x, &y);
                unionSets(&ds, x, y);
                printf("Union performed for elements %d and %d\n", x, y);
                break;
            case 3:
                printf("Enter new element to add: ");
                scanf("%d", &newElement);
                addElement(&ds, newElement);
                printf("Element %d added to the set\n", newElement);
                break;
            case 4:
                displaySets(&ds);
                break;
            case 5:
                free(ds.parent);
                free(ds.rank);
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

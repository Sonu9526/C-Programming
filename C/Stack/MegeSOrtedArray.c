#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr1[50], arr2[50], s1, s2;
    int i = 0, j = 0;
    int k = 0;

    
    printf("Enter the size of array 1: ");  
    scanf("%d", &s1);
    printf("Enter Sorted values in array 1: ");
    for (i = 0; i < s1; i++) {
        scanf("%d", &arr1[i]);
    }

    
    printf("Enter the size of array 2: ");
    scanf("%d", &s2);
    printf("Enter Sorted values in array 2: ");  
    for (i = 0; i < s2; i++) {
        scanf("%d", &arr2[i]);
    }

    
    int *res = (int *)malloc((s1 + s2) * sizeof(int));
    if (res == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    i = 0;  
    
    while (i < s1 && j < s2) {
        if (arr1[i] < arr2[j]) {
            res[k++] = arr1[i++];
        } else {
            res[k++] = arr2[j++];
        }
    }

    
    while (i < s1) {
        res[k++] = arr1[i++];
    }

    
    while (j < s2) {
        res[k++] = arr2[j++];
    }

 
    printf("After merging sorted Array1 and Array2: ");
    for (i = 0; i < s1 + s2; i++) {
        printf("%d\t", res[i]);
    }

    
    free(res);

    return 0;
}

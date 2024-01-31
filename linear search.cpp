#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; 
}

int main() {
    int n, key;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements in the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    start = clock(); 

    int position = linearSearch(arr, n, key);

    end = clock(); 
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    if (position != -1) {
        printf("Element found at position %d.\n", position);
    } else {
        printf("Element not found in the array.\n");
    }

    printf("Time taken for completion: %f seconds\n", cpu_time_used);

    free(arr);

    return 0;
}


#include <stdio.h>

#define MAX_SIZE 10

int count = 0;

// Function to print subsets
void printSubset(int subset[], int size) {
    printf("Subset %d: {", ++count);
    for (int i = 0; i < size; i++) {
        printf("%d", subset[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("}\n");
}

// Function to find subsets recursively
void findSubsets(int arr[], int subset[], int n, int subSize, int total, int nodeCount, int sum) {
    if (total == sum) {
        printSubset(subset, subSize);
        findSubsets(arr, subset, n, subSize - 1, total - arr[nodeCount], nodeCount + 1, sum);
        return;
    } else {
        for (int i = nodeCount; i < n; i++) {
            subset[subSize] = arr[i];
            findSubsets(arr, subset, n, subSize + 1, total + arr[i], i + 1, sum);
        }
    }
}

// Function to initialize the subset search
void subsetSum(int arr[], int n, int sum) {
    int subset[MAX_SIZE];
    findSubsets(arr, subset, n, 0, 0, 0, sum);
}

int main() {
    int arr[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 35;
    
    subsetSum(arr, n, sum);
    
    return 0;
}


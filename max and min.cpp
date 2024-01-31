#include <stdio.h>
#include <limits.h>
#include <time.h>

struct Pair {
    int min;
    int max;
};

struct Pair findMinMax(int arr[], int left, int right, int *comparison_count) {
    struct Pair minMax, leftMinMax, rightMinMax;
    int mid;
    if (left == right) {
        minMax.min = arr[left];
        minMax.max = arr[left];
        return minMax;
    }

    if (right == left + 1) {
        *comparison_count += 1;
        if (arr[left] < arr[right]) {
            minMax.min = arr[left];
            minMax.max = arr[right];
        } else {
            minMax.min = arr[right];
            minMax.max = arr[left];
        }
        return minMax;
    }
    mid = (left + right) / 2;
    leftMinMax = findMinMax(arr, left, mid, comparison_count);
    rightMinMax = findMinMax(arr, mid + 1, right, comparison_count);

    *comparison_count += 1;
    if (leftMinMax.min < rightMinMax.min)
        minMax.min = leftMinMax.min;
    else
        minMax.min = rightMinMax.min;

    *comparison_count += 1;
    if (leftMinMax.max > rightMinMax.max)
        minMax.max = leftMinMax.max;
    else
        minMax.max = rightMinMax.max;

    return minMax;
}

int main() {
    int size;
    int comparison_count = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start_time = clock();
    struct Pair result = findMinMax(arr, 0, size - 1, &comparison_count);

    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    
    printf("Minimum value: %d\n", result.min);
    printf("Maximum value: %d\n", result.max);
    printf("Number of comparisons: %d\n", comparison_count);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}


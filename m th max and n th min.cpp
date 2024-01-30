#include <stdio.h>
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void findMthMaxAndNthMin(int arr[], int n, int m, int nth, int *mth_max, int *nth_min) {
    bubbleSort(arr, n);
    
    *mth_max = arr[n - m];
    
    *nth_min = arr[nth - 1];
}

int main() {
    int arr[] = {16, 16, 16, 16, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 3; 
    int nth = 2; 
    
    int mth_max, nth_min;
    findMthMaxAndNthMin(arr, n, m, nth, &mth_max, &nth_min);
    
    printf("M-th maximum number: %d\n", mth_max);
    printf("N-th minimum number: %d\n", nth_min);
    
    int sum = mth_max + nth_min;
    int diff = mth_max - nth_min;
    
    printf("Sum of M-th maximum and N-th minimum: %d\n", sum);
    printf("Difference of M-th maximum and N-th minimum: %d\n", diff);
    
    return 0;
}


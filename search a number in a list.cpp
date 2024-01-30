#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        
        if (arr[mid] < target)
            left = mid + 1;
        
        else
            right = mid - 1;
    }
    
    
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    
    int index = binarySearch(arr, n, target);
    if (index != -1)
        printf("Target found at index %d.\n", index);
    else
        printf("Target not found in the array.\n");
    
    return 0;
}


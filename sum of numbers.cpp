#include <stdio.h>

int sum_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int max_sum_of_digits(int nums[], int length) {
    int digit_sums[1000] = {0}; // Assuming the maximum sum of digits won't exceed 1000
    int max_sum = -1;

    for (int i = 0; i < length; i++) {
        int num = nums[i];
        int digit_sum = sum_of_digits(num);
        if (digit_sums[digit_sum] != 0) {
            max_sum = (max_sum > digit_sums[digit_sum] + num) ? max_sum : digit_sums[digit_sum] + num;
        }
        if (num > digit_sums[digit_sum]) {
            digit_sums[digit_sum] = num;
        }
    }

    return max_sum;
}

int main() {
    int nums[100];
    int length;

    printf("Enter the length of the array: ");
    scanf("%d", &length);

    printf("Enter %d positive integers:\n", length);
    for (int i = 0; i < length; i++) {
        scanf("%d", &nums[i]);
    }

    int result = max_sum_of_digits(nums, length);
    printf("Maximum sum of two numbers with equal digit sums: %d\n", result);

    return 0;
}

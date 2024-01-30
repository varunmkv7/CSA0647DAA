#include <stdio.h>

// Function to reverse a given number
int reverseNumber(int num) {
    int reverse = 0;
    while (num != 0) {
        int digit = num % 10;
        reverse = reverse * 10 + digit;
        num /= 10;
    }
    return reverse;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    int reversedNum = reverseNumber(num);
    printf("Reverse of %d is %d.\n", num, reversedNum);
    
    return 0;
}


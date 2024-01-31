#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int n;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }
    
    unsigned long long fact = factorial(n);
    printf("Factorial of %d is: %llu\n", n, fact);
    
    printf("Time complexity estimation: O(n)\n");
    
    return 0;
}


#include <stdio.h>
#include <time.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    clock_t start_time = clock();
    int result = gcd(num1, num2);

    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("The GCD of %d and %d is: %d\n", num1, num2, result);
    printf("Time taken for the calculation: %f seconds\n", time_taken);

    return 0;
}


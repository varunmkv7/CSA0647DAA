#include <stdio.h>

// Function to compute the binomial coefficient (n choose k) using dynamic programming
int binomialCoefficient(int n, int k) {
    int C[n + 1][k + 1];
    int i, j;
    
    // Calculate binomial coefficients using dynamic programming
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k && j <= i; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

int main() {
    int n = 8, k = 8;
    printf("Binomial coefficient C(%d, %d) = %d\n", n, k, binomialCoefficient(n, k));
    return 0;
}


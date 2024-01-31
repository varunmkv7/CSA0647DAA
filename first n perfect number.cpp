#include <stdio.h>
#include<stdlib.h>
int isPerfect(int num)
{
    int sum = 1;  
    for (int i = 2; i * i <= num; i++){
        if (num % i == 0){
            sum += i;
            if(i != num / i){
                sum += num / i;
            }
        }
    }
    return (sum == num);
}
int main()
{
    int n;
    printf("Enter the value of n: ");
    if(scanf("%d", &n)!= 1)
	{
    printf("Invalid input. Please enter a valid integer.\n");
    exit(1);  
    }  
    printf("First %d perfect numbers:\n", n);
    int count = 0;
    int num = 2;  
    while (count < n)
	{
        if (isPerfect(num))
		{
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
    return 0;
}

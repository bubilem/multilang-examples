#include <stdlib.h>
#include <stdio.h>

int factorial(int n)
{
    int factorial = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int n_over_k(int n, int k)
{
    if (k == 0 || n == k)
    {
        return 1;
    }
    return factorial(n) / (factorial(n - k) * factorial(k));
}

void pascals_triangle(int height)
{
    for (int row = 0; row < height; row++)
    {
        for (int i = 0; i < height - 1 - row; i++)
        {
            printf("  ");
        }
        for (int i = 0; i <= row; i++)
        {
            printf("%4d", n_over_k(row, i));
        }
        printf("\n");
    }
}
int main()
{
    pascals_triangle(13);
    return 0;
}
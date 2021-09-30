#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //quadratic equation ax2 + bx + c = 0
    double a = 2;
    double b = 0;
    double c = 1;
    double x1, x2;

    double D = (b * b) - (4 * a * c);
    if (D < 0)
    {
        puts("No solution in R");
    }
    else if (D > 0)
    {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        printf("Two solution: x1 = %.2f, x2 = %.2f\n", x1, x2);
    }
    else
    {
        x1 = (-b) / (2 * a);
        printf("One solution: x = %.2f\n", x1);
    }
    return 0;
}
/* 
 algebrogram: ABCD*D = DCBA 
 brute force solution
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int left, right, r[4] = {-1};
    for (int a = 0; a <= 9; a++)
    {
        for (int b = 0; b <= 9; b++)
        {
            if (b == a)
            {
                continue;
            }
            for (int c = 0; c <= 9; c++)
            {
                if (c == b || c == a)
                {
                    continue;
                }
                for (int d = 0; d <= 9; d++)
                {
                    if (d == c || d == b || d == a)
                    {
                        continue;
                    }
                    left = (a * 1000 + b * 100 + c * 10 + d) * d;
                    right = d * 1000 + c * 100 + b * 10 + a;
                    if (left == right)
                    {
                        r[0] = a;
                        r[1] = b;
                        r[2] = c;
                        r[3] = d;
                        break;
                    }
                }
            }
        }
    }
    if (r[0] != -1)
    {
        printf("abcd*d = dcba\n");
        printf("%d%d%d%d*%d = %d%d%d%d\n", r[0], r[1], r[2], r[3], r[3], r[3], r[2], r[1], r[0]);
    }
    else
    {
        printf("No success\n");
    }
    return 0;
}
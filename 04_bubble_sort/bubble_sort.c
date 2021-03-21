#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int data[10] = {};

    //generate
    srand(time(NULL));
    for (int i = 0; i < sizeof(data) / 4; i++)
    {
        data[i] = rand() % 100;
    }

    //optimized bubble-sort
    int tmp, swap;
    for (int j = 0; j < sizeof(data) / 4 - 1; j++)
    {
        swap = 0;
        for (int i = 0; i < sizeof(data) / 4 - 1 - j; i++)
        {
            if (data[i] > data[i + 1])
            {
                tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
                swap++;
            }
        }
        if (!swap)
        {
            break;
        }
    }

    //show
    for (int i = 0; i < sizeof(data) / 4; i++)
    {
        printf("%i ", data[i]);
    }
    return 0;
}
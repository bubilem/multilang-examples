#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const int WIDTH = 20;
const int HEIGHT = 10;
const int MINES = 30;

void init(int minefield[WIDTH][HEIGHT])
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            minefield[x][y] = 0;
        }
    }
}

void generateMines(int minefield[WIDTH][HEIGHT], int count)
{
    if (count > WIDTH * HEIGHT)
    {
        return;
    }
    int x, y;
    for (int i = 0; i < count; i++)
    {
        do
        {
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        } while (minefield[x][y] == 9);
        minefield[x][y] = 9;
    }
}

void evaluate(int minefield[WIDTH][HEIGHT])
{
    int neighbors[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    int nx, ny;
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (minefield[x][y] != 9)
            {
                continue;
            }
            for (int k = 0; k < 8; k++)
            {
                nx = x + neighbors[k][0];
                ny = y + neighbors[k][1];
                if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && minefield[nx][ny] != 9)
                {
                    minefield[nx][ny]++;
                }
            }
        }
    }
}

void show(int minefield[WIDTH][HEIGHT])
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            switch (minefield[x][y])
            {
            case 9:
                printf("* ");
                break;
            case 0:
                printf("  ");
                break;
            default:
                printf("%d ", minefield[x][y]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int minefield[WIDTH][HEIGHT];
    srand(time(NULL));
    init(minefield);
    generateMines(minefield, MINES);
    evaluate(minefield);
    show(minefield);
    return 0;
}
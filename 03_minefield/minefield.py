from random import randint


def init(width, height):
    return [[0 for col in range(height)] for row in range(width)]


def generateMines(count):
    if count > len(minefield) * len(minefield[0]):
        return
    while True:
        x = randint(0, len(minefield) - 1)
        y = randint(0, len(minefield[0]) - 1)
        if minefield[x][y] == 0:
            minefield[x][y] = 9
            count -= 1
            if not count:
                break


def evaluate():
    neighbors = (
        (-1, -1),
        (0, -1),
        (1, -1),
        (-1, 0),
        (1, 0),
        (-1, 1),
        (0, 1),
        (1, 1),
    )
    for y in range(len(minefield[0])):
        for x in range(len(minefield)):
            if minefield[x][y] != 9:
                continue
            for neighbor in neighbors:
                nx = x + neighbor[0]
                ny = y + neighbor[1]
                if (
                    nx >= 0
                    and nx < len(minefield)
                    and ny >= 0
                    and ny < len(minefield[0])
                    and minefield[nx][ny] != 9
                ):
                    minefield[nx][ny] += 1


def show():
    for y in range(len(minefield[0])):
        for x in range(len(minefield)):
            if minefield[x][y] == 9:
                print("*", end=" ")
            elif minefield[x][y] == 0:
                print(" ", end=" ")
            else:
                print(minefield[x][y], end=" ")
        print()


minefield = init(20, 10)
generateMines(30)
evaluate()
show()

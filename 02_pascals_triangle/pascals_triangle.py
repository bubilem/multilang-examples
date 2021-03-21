def factorial(n):
    return 1 if n <= 1 else factorial(n - 1) * n


def n_over_k(n, k):
    if k == 0 or n == k:
        return 1
    return (int)(factorial(n) / (factorial(n - k) * factorial(k)))


def pascals_triangle(height):
    for row in range(height):
        print("  " * (height - 1 - row), end="")
        for i in range(row + 1):
            print("{0:3d} ".format(n_over_k(row, i)), end="")
        print()


pascals_triangle(13)

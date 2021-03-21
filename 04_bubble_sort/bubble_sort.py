from numpy import random

# generate
data = random.randint(99, size=(10))

# optimized bubble-sort
for j in range(len(data) - 1):
    swap = False
    for i in range(len(data) - 1 - j):
        if data[i] > data[i + 1]:
            data[i], data[i + 1] = data[i + 1], data[i]
            swap = True
    if not swap:
        break

# show
print(*data, sep=" ")

from math import sqrt
# quadratic equation ax2 + bx + c = 0
a = 2
b = 0
c = -2

D = (b * b) - (4 * a * c)
if D < 0:
    print("No solution in R")
elif D > 0:
    x1 = (-b + sqrt(D)) / (2 * a)
    x2 = (-b - sqrt(D)) / (2 * a)
    print("Two solution: x1 = {:.2}, x2 = {:.2}".format(x1, x2))
else:
    print("One solution: x = {:.2}".format((-b) / (2 * a)))

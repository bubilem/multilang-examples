# algebrogram: ABCD*D = DCBA
# brute force solution
for a in range(10):
    for b in range(10):
        if b == a:
            continue
        for c in range(10):
            if c == b or c == a:
                continue
            for d in range(10):
                if d == c or d == b or d == a:
                    continue
                left = (a * 1000 + b * 100 + c * 10 + d) * d
                right = d * 1000 + c * 100 + b * 10 + a
                if left == right:
                    r = a, b, c, d
                    break
if r:
    print("abcd*d = dcba")
    print(
        str(r[0])
        + str(r[1])
        + str(r[2])
        + str(r[3])
        + "*"
        + str(r[3])
        + " = "
        + str(r[3])
        + str(r[2])
        + str(r[1])
        + str(r[0])
    )
else:
    print("none")

import time
def fragment3(n):
    sum = 0
    for i in range(n):
        for j in range(i*i):
            for k in range(j):
                sum += 1
    return sum

# Test running times
for n in [10, 30, 50]:  # n>7 grows extremely fast
    start = time.time()
    fragment3(n)
    end = time.time()
    print(f"n={n}, time={(end-start):.6f} sec")


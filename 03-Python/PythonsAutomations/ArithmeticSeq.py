digit_sum = []

def sum_of_nth(n):
    if n > 0:
        digit_sum.append(n)
        print(f"{n} ", end="+ " if n > 1 else "= ")
        return n + sum_of_nth(n - 1)
    else:
        return 0

print(f"Sum of first {x} natural numbers: ", end="")
print(f"{sum_of_nth(x)}")

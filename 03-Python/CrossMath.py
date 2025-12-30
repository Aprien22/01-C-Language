from itertools import permutations

def check_equation(p):
    return ((((((((p[0] + 13) * p[1]) / p[2]) + p[3]) + 12) * p[4]) - p[5] - 11 + p[6]) * p[7]) / p[8] == 76

def main():
    numbers = [1,2,3,4,5,6,7,8,9]
    for perm in permutations(numbers):
        if check_equation(perm):
            print(f"Solution found: {perm}")

if __name__ == "__main__":
    main()

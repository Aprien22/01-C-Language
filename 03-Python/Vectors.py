import numpy as np

A = np.array([-2, -1, 4, 5])
B = np.array([3, 1, -5, 7])
C = np.array([-6, 2, 1, 1])

scalar = np.dot(A, B)         # Step 1: dot product
scaled_C = scalar * C         # Step 2: scalar × vector
result_vector = A + scaled_C  # Step 3: add to A
norm_result = np.linalg.norm(result_vector)  # Step 4: norm

print(f"||A + (A·B)·C|| = {norm_result}")

scalar2 = np.dot(B, C)
scaled_C = scalar2 * C
normed_A = np.linalg.norm(A)**2
scaled_B = normed_A * B
result_vector2 = scaled_C + scaled_B

print(f"(B·C)·C + ||A||²·B = {result_vector2}")

addition = np.add(A, B)
normed_Addition = np.linalg.norm(addition)
result3 = normed_Addition + C


# Practices
X = np.array([[34, 45], [52, 67], [93, 78]])
Y = np.array([[40, 70, 60], [36, 63, 54]])

W = (1 / np.sqrt(2)) * np.array([[1, -1], [1, 1]])
W = np.linalg.matrix_power(W, 4)
clean = np.round(W, decimals=10)

print(f"W^4 = {clean}")


P = np.array([[1,2], [3,4]])
print(f"AI2 = {np.dot(P, np.eye(2))}")
print(f"I3 = {np.eye(3)}")

R = np.array([[1, 2, -1, 2], [0, -3, 1, 3]])
S = np.array([[-1, 4, 0, 1], [2, -5, 3, 2]])

first = np.dot(S, np.transpose(R))
second = np.dot(R, np.transpose(S))
RS_matrix = first + second
result = np.transpose(RS_matrix)

print(f"(R·Sᵀ + S·Rᵀ)ᵀ = {result}")

Z = np.array([[1, 2], [0, 3]])
powee = np.linalg.matrix_power(Z, 2)
print(f"Z² = {powee}")

print(f"X·Y = {np.dot(Y, X)}")


def gauss_jordan(A):
    rows, cols = A.shape
    for i in range(rows):
        # Make the diagonal element 1
        A[i] = A[i] / A[i, i]
        for j in range(rows):
            if i != j:
                A[j] = A[j] - A[j, i] * A[i]
    return A

T = np.array([
    [1, 2, -2, 3],
    [2, 4, -4, 6],
    [3, 6, -6, 9]
], dtype=float)

result = gauss_jordan(T.copy())
solution = result[:, -1]  # Last column contains the solution
print("Solution:", solution)

print(f"Rank: {np.linalg.matrix_rank(T)}")

I = np.array([[1, 3], [1, 4]])

print(f"Inverse: {np.linalg.inv(I)}")

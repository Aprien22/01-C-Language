import numpy as np

A = np.array([[4, 1, 0], [1, 3, 0], [0, 0, 2]])

eigval, eigvec = np.linalg.eigh(A)
print(f"Eigenvalue:\n{eigval}")
print(f"Eigenvector:\n{eigvec}")
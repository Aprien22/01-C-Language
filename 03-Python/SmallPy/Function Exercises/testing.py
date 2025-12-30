import numpy as np


mat = np.array([[0.70, .30], [0.20, .80]])
coke = np.array([1, 0])
pepsi = np.array([0, 1])

def markov_step(current_state, transition_matrix):
    """Performs a single Markov process step.

    Args:
        current_state: The current state vector.
        transition_matrix: The state transition matrix.

    Returns:
        The next state vector after applying the transition matrix.
    """
    next_state = np.dot(current_state, transition_matrix)
    return next_state


print("Initial state (Coke):", coke)
phase = 3
for i in range(phase):
    coke = markov_step(coke, mat)
    print(f"After step {i + 1}: {coke}")

for i in range(phase):
    pepsi = markov_step(pepsi, mat)
    print(f"After step {i + 1}: {pepsi}")

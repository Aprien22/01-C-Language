import random
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Generate random data
data = [random.randint(1, 100) for _ in range(30)]

fig, ax = plt.subplots()
bars = ax.bar(range(len(data)), data)
ax.set_title("Bubble Sort Animation")

def bubble_sort_steps(arr):
    a = arr[:]
    steps = []
    n = len(a)

    for i in range(n):
        for j in range(0, n - i - 1):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
            steps.append(a[:])  # save state after each step
    return steps

steps = bubble_sort_steps(data)

def update(frame):
    for bar, height in zip(bars, steps[frame]):
        bar.set_height(height)

ani = FuncAnimation(
    fig,
    update,
    frames=len(steps),
    interval=50,
    repeat=False
)

plt.show()

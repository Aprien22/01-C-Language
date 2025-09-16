import pygame
import sys
import random

# --- Configuration ---
SCREEN_WIDTH, SCREEN_HEIGHT = 800, 600
CELL_SIZE = 10
FPS = 10

# --- Grid Setup ---
NUM_COLS = SCREEN_WIDTH // CELL_SIZE
NUM_ROWS = SCREEN_HEIGHT // CELL_SIZE

# 0 = dead, 1 = alive
cell_grid = [[random.choice([0, 1]) for _ in range(NUM_COLS)] for _ in range(NUM_ROWS)]
cell_age_grid = [[0 for _ in range(NUM_COLS)] for _ in range(NUM_ROWS)]  # Tracks age of each cell

# --- Pygame Setup ---
pygame.init()
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
clock = pygame.time.Clock()

def count_alive_neighbors(grid, col, row):
    """Count alive neighbors for a cell at (col, row) with toroidal wrapping."""
    count = 0
    for d_row in range(-1, 2):
        for d_col in range(-1, 2):
            if d_row == 0 and d_col == 0:
                continue  # Skip self
            neighbor_col = (col + d_col) % NUM_COLS
            neighbor_row = (row + d_row) % NUM_ROWS
            count += grid[neighbor_row][neighbor_col]
    return count

while True:
    # --- Event Handling ---
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # --- Prepare Next Generation ---
    next_cell_grid = [[0 for _ in range(NUM_COLS)] for _ in range(NUM_ROWS)]
    next_age_grid = [[0 for _ in range(NUM_COLS)] for _ in range(NUM_ROWS)]

    for row in range(NUM_ROWS):
        for col in range(NUM_COLS):
            alive_neighbors = count_alive_neighbors(cell_grid, col, row)
            if cell_grid[row][col] == 1:
                # Cell is alive
                if alive_neighbors == 2 or alive_neighbors == 3:
                    next_cell_grid[row][col] = 1  # Survives
                    next_age_grid[row][col] = cell_age_grid[row][col] + 1  # Increase age
                else:
                    next_cell_grid[row][col] = 0  # Dies
                    next_age_grid[row][col] = 0
            else:
                # Cell is dead
                if alive_neighbors == 3:
                    next_cell_grid[row][col] = 1  # New cell born
                    next_age_grid[row][col] = 1
                else:
                    next_age_grid[row][col] = 0

    cell_grid = next_cell_grid
    cell_age_grid = next_age_grid

    # --- Drawing ---
    screen.fill((10, 10, 10))
    for row in range(NUM_ROWS):
        for col in range(NUM_COLS):
            if cell_grid[row][col] == 1:
                age = cell_age_grid[row][col]
                # Color by age: young=green, older=yellow, old=orange
                if age < 5:
                    color = (0, 255, 0)
                elif age < 15:
                    color = (255, 255, 0)
                else:
                    color = (255, 100, 0)
                rect = pygame.Rect(col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE - 1, CELL_SIZE - 1)
                pygame.draw.rect(screen, color, rect)

    pygame.display.flip()
    clock.tick(FPS)

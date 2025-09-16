import pygame
import sys
import math
import random

pygame.init()
screen = pygame.display.set_mode((800, 600))
clock = pygame.time.Clock()

NUM_BALLS = 20
DIST = 10  # Distance between balls
SPEED = 2.5  # Pixels per frame for head

# Initialize positions
balls = [{'x': 400, 'y': 300} for _ in range(NUM_BALLS)]

# Sizes: head bigger, tail smaller
max_size = 20
min_size = 5

sizes = [
    int(max_size - (max_size - min_size) * (i / (NUM_BALLS - 1)))
    for i in range(NUM_BALLS)
]

# Head's velocity and direction
angle = random.uniform(0, 2 * math.pi)
vx = math.cos(angle) * SPEED
vy = math.sin(angle) * SPEED

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # Randomly change direction a little
    angle += random.uniform(-0.1, 0.1)
    vx = math.cos(angle) * SPEED
    vy = math.sin(angle) * SPEED

    # Move head
    head = balls[0]
    head['x'] += vx
    head['y'] += vy

    # Bounce off walls
    if head['x'] < sizes[0] or head['x'] > 800 - sizes[0]:
        angle = math.pi - angle
        head['x'] = max(sizes[0], min(800 - sizes[0], head['x']))
    if head['y'] < sizes[0] or head['y'] > 600 - sizes[0]:
        angle = -angle
        head['y'] = max(sizes[0], min(600 - sizes[0], head['y']))

    # Update positions with distance constraint
    for i in range(1, NUM_BALLS):
        prev = balls[i - 1]
        curr = balls[i]

        dx = prev['x'] - curr['x']
        dy = prev['y'] - curr['y']
        dist = math.hypot(dx, dy)

        if dist > 0:
            offset_x = dx / dist * DIST
            offset_y = dy / dist * DIST
            curr['x'] = prev['x'] - offset_x
            curr['y'] = prev['y'] - offset_y

    # Draw
    screen.fill((30, 30, 30))
    for i, b in enumerate(balls):
        color = (0, int(255 * (1 - i / NUM_BALLS)), int(255 * (1 - i / NUM_BALLS)))
        pygame.draw.circle(screen, color, (int(b['x']), int(b['y'])), sizes[i])

    pygame.display.flip()
    clock.tick(60)

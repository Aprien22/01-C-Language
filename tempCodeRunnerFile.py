import pygame
import math

pygame.init()
screen = pygame.display.set_mode((500, 500))
clock = pygame.time.Clock()

x_base = 250
y = 250
time_passed = 0

running = True
while running:
    screen.fill((0, 0, 0))

    # Compute x using a sine functiona
    x = x_base + 100 * math.sin(time_passed)

    # Draw circle
    pygame.draw.circle(screen, (255, 0, 0), (int(x), y), 20)

    pygame.display.flip()
    time_passed += 0.05

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    clock.tick(60)

pygame.quit()

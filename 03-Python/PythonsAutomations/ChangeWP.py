import ctypes
import time
import datetime

WALLPAPERS = {
    "morning": r"C:\Users\PC\Pictures\Wallpaper\July Morning - 2025.png",
    "afternoon": r"C:\Users\PC\Pictures\Wallpaper\July Afternoon - 2025.png",
    "night": r"C:\Users\PC\Pictures\Wallpaper\July Evening - 2025.png"
}

def set_wallpaper(path):
    ctypes.windll.user32.SystemParametersInfoW(20, 0, path, 3)

while True:
    hour = datetime.datetime.now().hour
    if 6 <= hour < 12:
        wallpaper = WALLPAPERS["morning"]
    elif 12 <= hour < 18:
        wallpaper = WALLPAPERS["afternoon"]
    else:
        wallpaper = WALLPAPERS["night"]
    set_wallpaper(wallpaper)
    print(f"Wallpaper set to: {wallpaper}")
    with open(r"C:\Users\PC\Pictures\Wallpaper\wallpaper_log.txt", "a") as log:
        log.write(f"Wallpaper set to: {wallpaper} at {datetime.datetime.now()}\n")
    time.sleep(60 * 30)  # Check every 30 minutes
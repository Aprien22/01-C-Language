import requests
import random

bot_token = '7585108535:AAEZkyA3FaDCjdsePVt8IyNS7BVhbHM908A'
chat_id = '6473793835'

def get_nasa_apod():
    api_key = "HcZ67V06Abc4IAClQDd5XFoU6hmuYdgzYb4YC34q"  # Replace with your NASA API key if you have one
    resp = requests.get(f"https://api.nasa.gov/planetary/apod?api_key={api_key}")
    if resp.ok:
        data = resp.json()
        if data.get('media_type') == 'image':
            return data['url'], ""  # No caption, just the image
    return None, "Could not fetch NASA APOD today!"

def get_unsplash_wallpaper():
    access_key = "KFNyYebxcC7dZMHpZHYHqLjH8yi69SSINrkdFQvHWpw"
    resp = requests.get(
        "https://api.unsplash.com/photos/random",
        params={"query": "wallpaper", "orientation": "portrait"},
        headers={"Authorization": f"Client-ID {access_key}"}
    )
    if resp.ok:
        data = resp.json()
        return data['urls']['regular'], f"{data['description'] or data['alt_description'] or 'Wallpaper'}\nBy {data['user']['name']} (Unsplash)"
    return None, "Could not fetch Unsplash wallpaper!"

choices = [get_nasa_apod, get_unsplash_wallpaper]
image_url, caption = random.choice(choices)()

if image_url:
    url = f"https://api.telegram.org/bot{bot_token}/sendPhoto"
    payload = {
        "chat_id": chat_id,
        "photo": image_url,
        "caption": caption
    }
    response = requests.post(url, data=payload)
    print("Wallpaper sent!" if response.ok else response.text)
else:
    print(caption)
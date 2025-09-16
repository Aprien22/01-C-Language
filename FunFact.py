import requests
import random

bot_token = '7651396026:AAHDZs2kL0N-BSNkeyLd115y55DGemthEuk'  # Replace with your bot token
chat_id = '6473793835'      # Replace with your chat ID

def get_useless_fact():
    resp = requests.get("https://uselessfacts.jsph.pl/api/v2/facts/random")
    if resp.ok:
        return resp.json()['text'], "Useless Facts API"
    return "Could not fetch a useless fact today!", "Useless Facts API"

def get_nasa_apod_fact():
    api_key = "HcZ67V06Abc4IAClQDd5XFoU6hmuYdgzYb4YC34q"
    resp = requests.get(f"https://api.nasa.gov/planetary/apod?api_key={api_key}")
    if resp.ok:
        data = resp.json()
        image_url = data.get('url', '')
        title = data.get('title', 'Astronomy Picture of the Day')
        explanation = data.get('explanation', '')
        caption = f"{title}\n\n{explanation}\n(Source: NASA APOD API)"
        return image_url, caption
    return None, "Could not fetch a NASA APOD fact today! (NASA APOD API)"

def get_wikipedia_random_fact():
    resp = requests.get("https://en.wikipedia.org/api/rest_v1/page/random/summary")
    if resp.ok:
        data = resp.json()
        fact = f"{data.get('title', 'Wikipedia')}: {data.get('extract', '')}"
        return fact, "Wikipedia Random"
    return "Could not fetch a Wikipedia fact today!", "Wikipedia Random"

# List of fact functions
fact_sources = [get_useless_fact, get_nasa_apod_fact, get_wikipedia_random_fact]

random.shuffle(fact_sources)  # Shuffle to randomize order, no repeats

for i, fact_func in enumerate(fact_sources):
    fact, source = fact_func()
    message = f"🤓 Fun Fact #{i+1}:\n{fact}\n\n(Source: {source})"
    url = f"https://api.telegram.org/bot{bot_token}/sendMessage"
    payload = {
        "chat_id": chat_id,
        "text": message
    }
    response = requests.post(url, data=payload)
    if response.ok:
        print(f"Message {i+1} sent!")
    else:
        print(f"Failed to send message {i+1}:", response.text)

image_url, caption = get_nasa_apod_fact()
if image_url:
    url = f"https://api.telegram.org/bot{bot_token}/sendPhoto"
    payload = {
        "chat_id": chat_id,
        "photo": image_url,
        "caption": caption
    }
    response = requests.post(url, data=payload)
else:
    # fallback to sending text
    payload = {
        "chat_id": chat_id,
        "text": caption
    }
    url = f"https://api.telegram.org/bot{bot_token}/sendMessage"
    response = requests.post(url, data=payload)
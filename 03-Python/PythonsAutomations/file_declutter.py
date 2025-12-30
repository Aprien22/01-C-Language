import os
import shutil

# Define the folder to organize (change this to your target folder)
folder_path = input("Enter the folder path to organize: ").strip()
if not os.path.isdir(folder_path):
    print("Invalid folder path!")
    exit(1)

# File type categories
file_types = {
    "PDFs": [".pdf"],
    "Documents": [".docx", ".txt"],
    "Excels": [".xlsx"],
    "Powerpoints": [".pptx"],
    "Images": [".jpg", ".jpeg", ".png", ".gif", ".bmp"],
    "Videos": [".mp4", ".mov", ".avi", ".mkv"],
    "Audios": [".mp3", ".wav", ".flac", ".m4a"],
    "Archives": [".zip", ".rar", ".tar", ".7z"],
    "Software": [".exe", ".msi"],
    "Code": [".py", ".js", ".html", ".css", ".java", ".cpp"],
    "Others": [".ttf", ".otf"],
}

# Ensure subfolders exist
for category in file_types.keys():
    os.makedirs(os.path.join(folder_path, category), exist_ok=True)  # Create category folders if not present

# Scan and move files
for file in os.listdir(folder_path):
    file_path = os.path.join(folder_path, file)
    
    # Skip folders
    if os.path.isdir(file_path):
        continue

    # Get file extension
    ext = os.path.splitext(file)[1].lower()

    # Move files into respective folders
    for category, extensions in file_types.items():
        if ext in extensions:
            shutil.move(file_path, os.path.join(folder_path, category, file))  # Move file
            print(f"Moved: {file} → {category}/")
            break  # Stop checking once moved

print("📂 Folder organization complete!")

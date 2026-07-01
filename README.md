# 📝 C Notes Manager (Day 4 Project)

A modular, file-based Notes Manager written in **C** during my 4th day of learning programming. This project shifts from terminal-only structures to creating, reading, and managing physical `.txt` files on your drive, featuring a multi-file architecture.

## ✨ Features
* 📂 **File Generation:** Automatically creates and saves each note as an individual `.txt` file.
* 📋 **Show All:** Reads and outputs the contents of all active notes directly to the terminal.
* 🔍 **Keyword Search:** Scans through the text inside files using `strstr` to find specific keywords.
* 📂 **Load Existing Files:** Links external `.txt` files into the current app session tracker.
* ❌ **Hard Delete:** Permanently removes `.txt` files from the disk using the C `remove()` function.

## 🛠 Tech Stack & Architecture
* **Language:** C
* **Structure:** Modular architecture (`.c` source files and `.h` header file).
* **Key Concepts:** Global states (`extern`), File Systems (`fopen`/`fclose`), Dynamic Array Resizing (`realloc`), and String Manipulation (`strcat`, `strcmp`).

## 🚀 How to Run on Linux

### 1. Compile the modular project:
Since the code is split across multiple source files, compile them all together using `gcc`:
```bash
gcc notes.c func.c -o notes
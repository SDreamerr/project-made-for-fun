# 📝 C Task Manager (Day 3 Project)

A simple Command Line Interface (CLI) task manager written in **C** during my 3rd day of learning programming. It allows managing tasks and saving them to a file.

## ✨ Features
* ➕ **Add Tasks:** Create new tasks and save them directly to a `tasks.txt` file.
* 📋 **View All:** List all created tasks with their current status.
* ✅ **Mark as Done:** Update the status of specific tasks.
* 🔍 **Filter Completed:** View only the tasks that have been marked as done.
* ❌ **Delete Tasks:** Remove unwanted tasks from the active list.

## 🛠 Tech Stack
* **Language:** C
* **Concepts Used:** Structs, Dynamic Memory Allocation (`malloc`, `realloc`), File I/O, Pointers.

## 🚀 How to Run on Linux

### 1. Compile the code:
Open your terminal and compile the file using `gcc` (available via `nix-shell -p gcc` if you are on NixOS):
```bash
gcc taskmgr.c -o taskmgr
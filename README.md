# 🐚 Simple Shell

A lightweight command-line interpreter that mimics the basic behavior of the UNIX shell. Developed as part of the Holberton School low-level programming curriculum.

---

## 📌 Features

- Custom prompt (`$ `) in interactive mode
- Parses and executes commands from standard input
- Supports both interactive and non-interactive modes
- Built-in commands:
  - `exit [status]`: Exits the shell with a given status
  - `env`: Prints the current environment variables
- Searches commands in the `PATH` environment variable
- Handles comments using `#`
- Gracefully handles EOF (`Ctrl+D`) and invalid input
- Custom implementation of helper functions (`_strcmp`, `_atoi`, etc.)

---

## 🧠 Built-in Commands

| Command | Description |
|---------|-------------|
| `exit [status]` | Exit the shell with optional status code |
| `env` | Display current environment variables |

---

## ⚙️ Compilation

Use the following command to compile all `.c` files:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

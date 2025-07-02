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

## 📁 Project Structure

| File | Description |
|------|-------------|
| `main.c` | Main shell loop and program entry point |
| `shell.h` | Header file with function declarations |
| `builtins.c` | Built-in commands (exit, env) |
| `executor.c` | Command execution logic |
| `tokenizer.c` | Command parsing and tokenization |
| `utils.c` | Utility functions (_strcmp, _atoi, etc.) |
| `path.c` | PATH handling and command search |
| `README.md` | Project documentation |
| `man_1_simple_shell` | Manual page |
| `AUTHORS` | List of contributors |

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



---



## 👥 Authors

- **Abdullah Aldafas** 
- **Sara Ali Mareer** 


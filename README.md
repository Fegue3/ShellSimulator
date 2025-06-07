# ShellSimulator

**ShellSimulator** is a simple command-line shell implemented in C. It emulates the behavior of a traditional Unix shell with support for basic commands, file operations, I/O redirection, and a few custom-built features. It's useful for educational purposes, especially in Operating Systems and Systems Programming contexts.

## Features

* Execution of built-in commands (`cd`, `ls`, `cp`, `mv`, `exit`)
* I/O redirection (`>`, `<`, `>>`)
* Custom command: `socp` for secure file copying
* Basic multithreading support
* Command parsing and simple error handling
* History tracking via `.soshell_history`
* Testing via script `1.sh`

## Requirements

* A Unix-like system (Linux, macOS, WSL)
* GCC compiler
* `make` utility

## Installation

Clone the repository and build the shell:

```bash
git clone https://github.com/Fegue3/ShellSimulator.git
cd ShellSimulator
make
```

## Running the Shell

After compilation, run the shell with:

```bash
./shell
```

You will see a prompt where you can type supported commands.

## Built-in Commands

| Command            | Description                         |
| ------------------ | ----------------------------------- |
| `cd [dir]`         | Change current directory            |
| `ls`               | List files in the current directory |
| `cp [src] [dst]`   | Copy file from `src` to `dst`       |
| `mv [src] [dst]`   | Move or rename a file               |
| `socp [src] [dst]` | Custom secure copy command          |
| `exit`             | Exit the shell                      |

## Redirection Support

The shell supports:

* Output redirection: `>` and `>>`
* Input redirection: `<`

### Examples:

```bash
ls > files.txt
cat < files.txt
echo "Done" >> log.txt
```

## Custom Command: `socp`

`socp` works similarly to `cp`, but it is implemented from scratch using system calls for learning purposes.

```bash
socp file1.txt copy1.txt
```

## Testing

To run the test suite, use the provided shell script:

```bash
./1.sh
```

This script executes a series of automated tests to validate functionality and ensure robustness.

## File Structure

```
├── .soshell_history       # Command history log
├── 1.sh                   # Test script
├── calc.c                 # Calculator-related logic (if implemented)
├── display.c              # Terminal output functions
├── execute.c              # Command execution logic
├── files.c                # File management helpers
├── fileutils.c            # Additional file utilities
├── in.1                   # Input test file (used by 1.sh)
├── main.c                 # Entry point for the shell
├── Makefile               # Build instructions
├── parse.c                # Command parsing and tokenizer
├── README.md              # Project documentation
├── redirects.c            # I/O redirection handling
├── shell.h                # Header file with declarations
├── socp.c                 # Implementation of `socp`
├── threads.c              # Thread support logic
```

## Future Work

* Pipe support (`|`)
* Background process handling (`&`)
* Tab-completion and history navigation

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

## Authors

* Fegue3 — [https://github.com/Fegue3](https://github.com/Fegue3)

---

For educational use only. Contributions are welcome!

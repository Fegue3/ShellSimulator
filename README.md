ShellSimulator
ShellSimulator is a C-based command-line shell emulator designed to mimic the behaviour of Unix-like shells. It supports a variety of built-in commands, file operations, and redirection features, providing a comprehensive environment for executing and testing shell commands.

Features
Execution of built-in commands such as cd, ls, cp, and mv.

Support for input/output redirection using >, <, and >>.

Custom implementation of the socp command for file copying.

Thread management capabilities.

Comprehensive testing suite to validate functionalities.

Getting Started
Prerequisites
GCC compiler

Make utility

Unix-like operating system

Installation
Clone the repository:

bash
Copy
Edit
git clone https://github.com/Fegue3/ShellSimulator.git
cd ShellSimulator
Compile the source code:

bash
Copy
Edit
make
Usage
After compilation, run the shell simulator using:

bash
Copy
Edit
./soshell
You will be presented with a prompt where you can enter supported commands.

Supported Commands
cd [directory] - Change the current directory.

ls - List the contents of the current directory.

cp [source] [destination] - Copy files from source to destination.

mv [source] [destination] - Move or rename files.

socp [source] [destination] - Custom file copy implementation.

exit - Exit the shell simulator.

Redirection
The shell simulator supports the following redirection operators:

> - Redirect standard output to a file.

< - Redirect standard input from a file.

>> - Append standard output to a file.

Example:

bash
Copy
Edit
ls > output.txt
Testing
The repository includes a suite of tests to verify the functionality of various components.

Running Tests
Execute the test script provided:

bash
Copy
Edit
./1.sh
This script runs a series of predefined tests and outputs the results, helping ensure that all features work as expected.

Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your enhancements.

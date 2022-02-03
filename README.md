# Simple shell
> Writing a simple UNIX command interpreter.
### Description
A project for Holberton School, this is an interpreter, it has the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when printing an error, the name of the program must be equivalent to your argv[0].
![flowchart](https://github.com/nourouhichi/simple_shell/blob/master/Untitled%20Diagram.png)

###Why?
* This project raises the following questions:
* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / “end-of-file”?
### Requirements of project
All files were compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
### How to use
  `$ ./main`
### Example of usage
![flowchart](https://github.com/nourouhichi/simple_shell/blob/master/2022-02-03%20(4).png)
### Implemented features
* Displays a prompt and waits for the user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
* Handles command lines with arguments.
* Implements the exit built-in, that exits the shell
* If an executable cannot be found, prints an error message and displays the prompt again.
* Handles errors.
* handles the “end of file” condition (Ctrl+D)
### Challenges
- Detecting and treating memory leaks from not freeing dynamically allocated memory using valgrind.
- organizing project parts
### Features that I did not implement
* Handling the && and || shell logical operators
* Handling the commands separator ;
* Implementing the alias builtin command
* Handling comments (#)
* Implementing the help built-in
### Authors
* Nour Ouhichi


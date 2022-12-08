# simple_shell
## Description
The shell is a command line interface (CLI) program that takes commands from the keyboard and gives them to the operating system to perform.
## what is a shell ?
In computing, a shell is a computer program that exposes an operating system's services to a human user or other programs. In general, operating system shells use either a command-line interface (CLI) or graphical user interface (GUI), depending on a computer's role and particular operation. It is named a shell because it is the outermost layer around the operating system.
## COMPILATION
Shell will be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## shell will be executable this way:
```
./hsh
```
## Man Page
```
 man ./man_simple_shell
```
## help page for command
for ls:
```
man ./help_ls
```
for cd:
```
man ./help_cd
```
for exit:
```
man ./help_exit
```
for env:
```
man ./help_env
```
## Task of The Project

**0. README, man, AUTHORS**

+ Write a `README`
+ Write a `man` for your shell.
+ You should have an `AUTHORS` file at the root of your repository, listing all individuals having contributed content to the   repository. Format, see [Docker](https://github.com/moby/moby/blob/master/AUTHORS).

**1. Betty would be proud**

+ Write a beautiful code that passes the Betty checks

**2. Simple shell 0.1**
Write a UNIX command line interpreter.

+ Usage: simple_shell

Your Shell should:

+ Display a prompt and wait for the user to type a command. A command line always ends with a new line.
+ The prompt is displayed again each time a command has been executed.
+ The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
+ The command lines are made only of one word. No arguments will be passed to programs.
+ If an executable cannot be found, print an error message and display the prompt again.
+ Handle errors.
+ You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:
+ use the PATH
+ implement built-ins
+ handle special characters : `"`,`'`,`\`,`*`,`&`,`#`
+ be able to move the cursor
+ handle commands with arguments
``execve`` will be the core part of your Shell, don’t forget to pass the environ to it…

**3. Simple shell 0.2**

Simple shell 0.1 +

+ Handle command lines with arguments

**4. Simple shell 0.3**
Simple shell 0.2 +

+ Handle the `PATH`
+ `fork` must not be called if the command doesn’t exist

**5. Simple shell 0.4**
Simple shell 0.3 +

+ Implement the `exit` built-in, that exits the shell
+ Usage: `exit`
+ You don’t have to handle any argument to the built-in `exit`0

**6. Simple shell 1.0**
Simple shell 0.4 +

- Implement the `env` built-in, that prints the current environment


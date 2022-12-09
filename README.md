# simple_shell
## Description of the Project:
so in this project me **Rayane El kefif** and **Alexandre Mary** we program a shell.

## Description of a shell:
In computing, a shell is a computer program that exposes an operating system's services to a human user or other programs. In general, operating system shells use either a command-line interface (CLI) or graphical user interface (GUI), depending on a computer's role :desktop_computer:	and particular operation. It is named a shell because it is the outermost layer around the operating system.

## Resources
Read or watch:

+ [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
* [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
- [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)

## List of allowed functions and system calls
+ ``access`` (man 2 access)
+ ``chdir`` (man 2 chdir)
+ ``close`` (man 2 close)
+ ``closedir`` (man 3 closedir)
+ ``execve`` (man 2 execve)
+ ``exit`` (man 3 exit)
+ ``_exit`` (man 2 _exit)
+ ``fflush`` (man 3 fflush)
+ ``fork`` (man 2 fork)
+ ``free`` (man 3 free)
+ ``getcwd`` (man 3 getcwd)
+ ``getline`` (man 3 getline)
+ ``getpid`` (man 2 getpid)
+ ``isatty`` (man 3 isatty)
+ ``kill`` (man 2 kill)
+ ``malloc`` (man 3 malloc)
+ ``open``(man 2 open)
+ ``opendir`` (man 3 opendir)
+ ``perror`` (man 3 perror)
+ ``printf`` (man 3 printf)
+ ``fprintf`` (man 3 fprintf)
+ ``vfprintf`` (man 3 vfprintf)
+ ``sprintf`` (man 3 sprintf)
+ ``putchar`` (man 3 putchar)
+ ``read`` (man 2 read)
+ ``readdir`` (man 3 readdir)
+ ``signal`` (man 2 signal)
+ ``stat`` (__xstat) (man 2 stat)
+ ``lstat`` (__lxstat) (man 2 lstat)
+ ``fstat`` (__fxstat) (man 2 fstat)
+ ``strtok`` (man 3 strtok)
+ ``wait`` (man 2 wait)
+ ``waitpid`` (man 2 waitpid)
+ ``wait3`` (man 2 wait3)
+ ``wait4`` (man 2 wait4)
+ ``write``(man 2 write)

## COMPILATION:
Shell will be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## shell will be executable this way:
```
./hsh
```
## Man Page:
``` 
man ./man_simple_shell
```
## help page for command:
for ls:

```man ./help_ls```

for cd:

```man ./help_cd```

for exit:

```man ./help_exit```

for env:

```man ./help_env```

## Task of The Project:

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
**********************************************
## Authors and their github :octocat:

* Alexandre Mary [@soOwasTaken](https://github.com/soOwasTaken)
* Elkefif Mustapha Rayane [@rayaneRX](https://github.com/rayaneRX)


![image](https://user-images.githubusercontent.com/113839670/206601629-83aa3f27-fd7c-4dff-8c32-4d311890841f.png)

# simple_shell
## Description of the Project:
The Shell is a program that receives computer orders given by a user from its keyboard to send them to the operating system that will run them

A shell is a program that provides an interface for users to interact with the operating system. It allows users to execute commands, control the execution of programs, and manage the system's resources. Our school asked us to make a new one and it was pretty difficult, but we succeed on some task and we are kinda happy like that.

The program is not fully fonctionnal, you can check the <span style="color:green">man ./man_simple_shell </span> at the end of this file you will some of the reported bugs and problem we did encounters.

## List of allowed functions and system calls
<details>
<summary>
> Click here to see full list of allowed fonctions and system calls.
</summary>
+ ``access``
+ ``chdir``
+ ``close``
+ ``closedir``
+ ``execve``
+ ``exit``
+ ``_exit``
+ ``fflush``
+ ``fork``
+ ``free``
+ ``access``
+ ``chdir``
+ ``close``
+ ``closedir``
+ ``execve``
+ ``exit``
+ ``_exit``
+ ``fflush``
+ ``fork``
+ ``free``
+ ``getcwd``
+ ``getline``
+ ``getpid``
+ ``isatty``
+ ``kill``
+ ``malloc``
+ ``open``
+ ``opendir``
+ ``perror``
+ ``printf``
+ ``fprintf``
+ ``vfprintf``
+ ``sprintf``
+ ``putchar``
+ ``read``
+ ``readdir``
+ ``signal``
+ ``stat``
+ ``lstat``
+ ``fstat``
+ ``strtok``
+ ``wait``
+ ``waitpid``
+ ``wait3``
+ ``wait4``
+ ``write``
</details>

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

or
echo "<command>" | ./hsh
```
## Man Page:
```
man ./man_simple_shell
```
## Exemples:

```
$ ./shell
> ls
```
The output of the ls command is displayed, showing the contents of the current directory.
```
> /bin/ls
```
The output of the ls command is displayed, showing the contents of the current directory.
```
> exit
```
The shell terminates and the program returns 0 to indicate successful execution.

## How it work.
<p>
  When the program is **executed**, the <span style="color:blue">main</span> function is **called**, which sets up the **environment** and starts the shell loop. The shell loop repeatedly prompts the user for input and then uses the <span style="color:blue">read_and_parse_command</span> function to** read and parse the user's input.**</p>
<p>The <span style="color:blue">read_and_parse_command</span> function reads a line of input from the user and then uses the <span style="color:blue">strtok</span> function to split the input into individual words (i.e., *tokens*) using whitespace as the delimiter. These tokens are then stored in an array of strings, which is passed to the <span style="color:blue">execute_command</span> function.</p>
<p>The <span style="color:blue">execute_command</span> function checks if the user's input matches any of the predefined shell commands, such as <span style="color:green">ls</span> or <span style="color:green">cd</span>,<span style="color:green">exit</span>,<span style="color:green">env</span> or a <span style="color:green">PATH</span>. If a match is found, the corresponding function is called to execute the command. If no match is found, the <span style="color:blue">execute_path</span> function is called to search the user's <span style="color:green">PATH</span> environment variable for the specified command and execute it if it is found.</p>
<p>The <span style="color:blue">execute</span> function is called by the <span style="color:blue">execute_command</span> function to execute the specified command using the <span style="color:green">execvp</span> system call. **This call creates a new process**, which is a duplicate of the calling process using <span style="color:green">PID fork</span>, and then executes the specified command in the new process. The original process (i.e., the shell) is suspended until the new process finishes <span style="color:green">executing</span>, at which point the shell resumes and prompts the user for another command.
</p>

This process continues until the user enters the <span style="color:red">exit</span> command or reach the end of file signal, which causes the shell to <span style="color:red">terminate</span>.
**********************************************

![image](https://i.imgur.com/jLfNtSD.jpg)
<details>
<summary>
> Click here to see full flowchart explained with developper language.
</summary>

```
start
   |
   |--- allocate memory for args
   |
   |--- check if shell is running interactively
   |       |
   |       |--- yes
   |       |     |
   |       |     |--- enter loop
   |       |           |
   |       |           |--- prompt user for command
   |       |           |
   |       |           |--- read and parse command
   |       |           |
   |       |           |--- call execute_command() to execute command
   |       |           |
   |       |           |--- free memory for command and args
   |       |           |
   |       |           |--- loop back to prompt
   |       |
   |       |--- no
   |             |
   |             |--- check if argv or argc are non-NULL or non-zero
   |             |       |
   |             |       |--- yes
   |             |       |     |
   |             |       |     |--- call execute_command2()
   |             |       |
   |             |       |--- no
   |             |             |
   |             |             |--- end program
   |
end
```

</details>

```
## Testing
Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
````
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
````

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

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
**********************************************
## Authors and their github :octocat:

* Alexandre Mary [@soOwasTaken](https://github.com/soOwasTaken)
* Elkefif Mustapha Rayane [@rayaneRX](https://github.com/rayaneRX)

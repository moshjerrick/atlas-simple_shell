## Images
<img src="https://www.google.com/imgres?imgurl=https%3A%2F%2Fassets-global.website-files.com%2F6571f4826e9363343bcd2acd%2F65737bab80daf01df40b6a27_logo-atlas-school-blue.svg&tbnid=TIuhLuSFNWY9RM&vet=12ahUKEwja0en3w6GFAxW4w8kDHWUeA6MQMygBegQIARBo..i&imgrefurl=https%3A%2F%2Fwww.atlasschool.com%2F&docid=RcayfjY-EPbQcM&w=800&h=334&q=atlas%20school&client=firefox-b-1-d&ved=2ahUKEwja0en3w6GFAxW4w8kDHWUeA6MQMygBegQIARBo">
# Atlas Simple Shell

## Description
The Simple Shell is a basic Unix shell implementation written in C programming language. This shell is developed as part of the curriculum at Atlas School to learn about system calls, processes, and other low-level programming concepts.

The concepts we needed to learn in order to start coding our own shell includes: PID & PPID, getline() & strtok(), execve(), for(), wait(), and stat().

## Features
- Executes commands entered by the user
- Supports basic built-in commands like `cd` and `exit`
- Handles simple command execution with arguments
- Provides a basic prompt for user interaction

## Getting Started
To use the Simple Shell, follow these steps:

1. Clone the repository to your local machine.

git clone https://github.com/moshjerrick/atlas-simple_shell

2. Compile the shell using

gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o hsh.

3. Run the compiled executable to start the shell.

./hsh

4. Enter commands at the prompt and press Enter to execute them.

## List of allowed functions and system calls

    all functions from string.h
    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    _exit (man 2 _exit)
    fflush (man 3 fflush)
    fork (man 2 fork)
    free (man 3 free)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    getpid (man 2 getpid)
    isatty (man 3 isatty)
    kill (man 2 kill)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    printf (man 3 printf)
    fprintf (man 3 fprintf)
    vfprintf (man 3 vfprintf)
    sprintf (man 3 sprintf)
    putchar (man 3 putchar)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (__xstat) (man 2 stat)
    lstat (__lxstat) (man 2 lstat)
    fstat (__fxstat) (man 2 fstat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)


## Usage
Here are some examples of commands you can use with the Simple Shell:
ls
cd
mkdir
pwd
env

## Exiting Shell
To exit the shell: Type exit or Ctrl+D







## Contributors
Mou Chang
Josh Merrick

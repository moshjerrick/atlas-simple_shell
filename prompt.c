#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

void shloop(void);
char *read_line(void);
void parse_line(char*);

/**
 * main - function for prompt
 * Return: 0
*/
int main()
{
    shloop();
    return 0;
}

/**
 * shloop - prints character that prompts user to input a command
 * Return: 0
*/
void shloop(void)
{
    char *line;
    int status = 1;


    while (status)
    {
        if(isatty(STDIN_FILENO)){
            printf("# ");
        }
        line = read_line();
        if (line == NULL)
        {
            status = 0;
            continue;
        }
        parse_line(line);
        free(line);
    }
}

/**
 * read_line - reads input line
 * Return: line
*/
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    if (getline(&line, &bufsize, stdin) == EOF)
    {
        free(line);
        exit(EXIT_SUCCESS);
    }
    return line;
}

/**
 * parse_line - break down a string into smaller components
 * @line: pointer to line
 * Return: 0
*/
void parse_line(char *line)
{
    pid_t pid;
    char *args[32];
    char *token;
    int i = 0;
    int prev_space = 1;

    token = strtok(line, " \n");
    while (token != NULL && i < 31)
    {
        if (prev_space == 0 || *token != ' ') {
            args[i++] = token;
        }
        prev_space = (*token == ' ');
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;


    if (i > 0)
    {
        if (strcmp(args[0], "exit") == 0)
        {
            free(token);
            exit(EXIT_SUCCESS);
        }
        else if (strcmp(args[0], "cd") == 0)
        {
            if (i > 1)
            {
                if (chdir(args[1]) != 0)
                {
                    perror("cd failed");
                }
            }
            else
            {
                fprintf(stderr, "cd: missing argument\n");
            }
            return;
        }
    }

    pid = fork();
    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("Execution failed");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(NULL);
    }
}

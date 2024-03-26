#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

void shloop(void);
char *read_line(void);
void parse_line(char*);

int main(int argc, char **argv)
{
    shloop();
    return (0);
}

void shloop(void)
{
    char *line;
    int status = 1;

    while (status)
    {
        printf("# ");
        line = read_line();
        if (line == NULL)
        {
            status = 0;
            continue;
        }
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            parse_line(line);
            free(line); // Free the allocated memory before exiting child process
            exit(EXIT_SUCCESS);
        }
        else
        {
            wait(NULL);
        }
        free(line);
    }
}

char *read_line(void)
{
    char *line = NULL;
    ssize_t bufsize = 0;
    if (getline(&line, &bufsize, stdin) == -1)
    {
        return NULL;
    }
    return line;
}

void parse_line(char *line)
{
    // Tokenize the line into arguments
    char *args[32]; // Maximum number of arguments assumed
    char *token = strtok(line, " \n");
    int i = 0;
    while (token != NULL && i < 31)
    {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;


    if (i > 0)
    {
        if (strcmp(args[0], "exit") == 0)
        {
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

    // Execute other commands
    if (execvp(args[0], args) == -1)
    {
        perror("Execution failed");
        exit(EXIT_FAILURE);
    }
}

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

void shloop(void);
char *read_line(void);
void parse_line(char*);


int main()
{
    shloop();
    return 0;
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
        parse_line(line);
        free(line);
    }
}


char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    if (getline(&line, &bufsize, stdin) == EOF)
    {
        exit(EXIT_SUCCESS);
    }
    return line;
}


void parse_line(char *line)
{
    pid_t pid;
    char *args[32];
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
            printf("later skater\n");
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



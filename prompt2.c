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
    shloop ();
    return (0);
}

void shloop (void)
{
	char *line;
	char **args;
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
		if (pid <0)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)

			{
				parse_line(line);
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
		free(line);
		return (NULL);
	}


    return(line);
}

void parse_line(char *line)
{
	if (strcmp(line, "exit\n") == 0)
	{
        exit(EXIT_SUCCESS);
    }
	else
	{
	printf("%s",  line);
}
}
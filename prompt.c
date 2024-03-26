#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main2(int argc, char **argv)
{
	if (isatty(STDIN_FILENO))
	{
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		char *username = "test\0";
		char hostname[1024];
		gethostname(hostname, sizeof(hostname));
		printf("%s@%s:%s$", username, hostname, cwd);
	}
	return EXIT_SUCCESS;
}

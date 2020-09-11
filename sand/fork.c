#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int		main()
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		printf("I am child process.\n");
	else if (pid > 0)
		printf("I am parent process.\nchild's pid id \"%d\"\n", pid);
	else
		perror(NULL);
	return (0);
}

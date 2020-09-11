#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void	child_process(int out_fd)
{
	//dup2(out_fd, 1);
	//write(1, "Hello, World!\n", 15);
	char *arg[] = {"./helloWorld", NULL};
	dup2(out_fd, 1);
	execvp(arg[0], arg);
	exit(0);
}

int		main()
{
	int		fildes[2];
	pid_t	pid;
	char	buf[16];
	int		status;

	pipe(fildes);
	pid = fork();
	if (pid == 0)
		child_process(fildes[1]);
	wait(&status);
	dup2(fildes[0], 0);
	read(0, buf, 15);
	buf[15] = 0;
	buf[12] = '?';
	write(1, buf, 15);
	return (0);
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void	parent_process(pid_t pid)
{
	int		status;

	waitpid(pid, &status, 0);
	printf("I am parent process.\n");
	printf("child's pid id \"%d\"\n", pid);
	printf("wait status is \"%d\"\n", status);
	printf("WIFEXITED %d\n", WIFEXITED(status));
	printf("WEXITSTATUS %d\n", WEXITSTATUS(status));
}

void	g_child_process(int fd_out)
{
	char *arg[] = {"./helloWorld", NULL};
	dup2(fd_out, 1);
	execvp(arg[0], arg);
}

void	child_process()
{
	int		fildes[2];
	pid_t	pid;
	char *arg[] = {"cat", NULL};
	int		status;

	if (pipe(fildes) < 0)
		exit(1);
	pid = fork();
	if (pid == 0)
		g_child_process(fildes[1]);
	else if (pid > 0);
	else
		perror(NULL);

	wait(&status);
	dup2(fildes[0], 0);
	printf("I am child process.\n");
	execvp(arg[0], arg);
	perror(NULL);
	printf("cant reachable.\n");
}

int		main()
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		child_process();
	else if (pid > 0)
		parent_process(pid);
	else
		perror(NULL);
	return (0);
}

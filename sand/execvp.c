#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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

void	child_process()
{
	char *arg[] = {"cat", NULL};

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
	return (42);
}

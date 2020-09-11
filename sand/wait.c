#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void	parents_process(pid_t pid)
{
	int		status;

	waitpid(pid, &status, 0);
	printf("I am parent process.\n");
	printf("child's pid id \"%d\"\n", pid);
	printf("wait status is \"%d\"\n", status);
	printf("WIFEXITED %d\n", WIFEXITED(status));
	printf("WEXITSTATUS %d\n", WEXITSTATUS(status));
}

int		main()
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		printf("I am child process.\n");
	else if (pid > 0)
		parents_process(pid);
	else
		perror(NULL);
	return (42);
}

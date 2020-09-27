#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int		main()
{
	char 	buf[256];
	int		ret;

	signal(SIGINT, SIG_IGN);
	ret = read(0, buf, 255);
	printf("%s, %d\n", buf, ret);
	return (0);
}

#include <unistd.h>

#define BUF_SIZE 255

int		main()
{
	char	buf[BUF_SIZE+1];
	int		ret;

	write(1, "> ", 2);
	ret = read(0, buf, BUF_SIZE);
	buf[ret] = 0;
	return (0);
}

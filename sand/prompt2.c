#include "libft/libft.h"
#include <stdio.h>

int main()
{
	char	*line;

	write(1, "> ", 2);
	get_next_line(0, &line);
	printf("%s\n", line);
	return (0);
}

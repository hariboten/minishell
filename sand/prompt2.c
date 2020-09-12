#include "../libft/libft.h"
#include <stdio.h>

int main()
{
	char	*line;

	write(1, "> ", 2);
	while (get_next_line(0, &line))
	{
		printf("%s\n", line);
		write(1, "> ", 2);
	}
	return (0);
}

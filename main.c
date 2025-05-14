#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int main(void)
{
	char *str;
	int fd = 0;

	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("%s", str);
		free(str);
	}

	// str = get_next_line(fd);
	// if (str)
	// {
	// 	printf("%s", str);
	// 	free(str);
	// }
	// str = get_next_line(fd);
	// if (str)
	// {
	// 	printf("%s", str);
	// 	free(str);
	// }
}
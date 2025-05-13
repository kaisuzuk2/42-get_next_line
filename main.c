#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char *str;
	// while (1)
	// {
	// 	str = get_next_line(0);
	// 	if (!str)
	// 		break;
	// 	printf("%s", str);
	// 	free(str);
	// }
	str = get_next_line(0);
	printf("%s", str);
}
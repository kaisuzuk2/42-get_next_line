#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
	char *str;

	str = get_next_line(0);
	if (str)
		printf("%s\n", str);
	free(str);
	str = get_next_line(0);
	if (str)
		printf("%s\n", str);
	free(str);
}
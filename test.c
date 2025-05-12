#include <stdio.h>

int getchar(void)
{
	static char buf[BUFSIZ];
	static char *bufp;
	static int n = 0;

	if (n == 0)
	{
		n = read(0, buf, sizeof(buf));
		bufp = buf;
	}
	return (--n >= 0) ? (unsigned char)*bufp++ : EOF;
}

int main(void)
{
	int fd;
	int c;

	fd = open("test", O_RDONLY);
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break;
		printf("%c", c);
	}
	close(fd);
	return (0);
}
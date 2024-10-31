#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int		fd;
	char	*string;

	fd= open("texto.txt", O_RDONLY);
	string = get_next_line(fd);
	printf ("%s", string);

	return 0;
}

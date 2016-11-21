#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char 	**line;
	char 	*a;
	int		ret;

	a = "test";
	line = &a;
	(void)argc;
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, line)) > 0)
		printf("%d\n", ret);
	printf("%d", ret);
	return (0);
}		

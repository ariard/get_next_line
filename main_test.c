#include <stdio.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*a;
	char	**line;
	int		ret;
	int		fd;

	a = "test";
	line = &a;
	(void)argc;
	fd = open(argv[1], O_RDONLY);
	close(fd);
	while ((ret = get_next_line(fd, line)) > 0)
		printf("%s", *line);
	return (0);
}

#include <stdio.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*a;
	char	**line;
	int		ret;
	int		fd;

	a = "aaa";
	line = &a;
	(void)argc;
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, line)) > 0)
	{
		printf("ret : %d\n", ret);
		printf("%s\n", *line);
	}
	printf("ret : %d\n", ret);
	return (0);
}

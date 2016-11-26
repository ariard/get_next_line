#include <stdio.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*a;
	char	**line;
	int		ret;
	int		fd;

	(void)argc;
	(void)argv;	
	a = "";
	line = &a;

	fd = open(argv[1], O_RDONLY);
	ret = get_next_line(42, line);
	printf("%d", ret);

	
}

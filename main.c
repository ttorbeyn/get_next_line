#include "get_next_line.h"

int		main(void)
{
	int		fd;
	int		ret;
	char	*line;

	//if (ac != 2)
	//	printf("Pas assez d'arguements\n");
	fd = open("alphabet", O_RDONLY);
	while (1)
	{
		ret = get_next_line(fd, &line);
		printf("%d -- |%s|\n", ret, line);
		free(line);
		if (ret == 0)
			break ;
	}
	return (0);
}

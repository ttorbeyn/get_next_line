#include "get_next_line.h"

int		main(void)
{
	int		fd;
	int		ret;
	char	*line;

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

/*
int			get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buffer;
	int			i;
	int			ret;

	i = 0;
	if (fd <= -1 || BUFFER_SIZE <= 0 || !line ||
 			!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!save)
	{
		if ((ret = read(fd, buffer, BUFFER_SIZE)) == 0)
		{
			*line = "";
			free(buffer);
			buffer = NULL;
			return (0);
		}
		buffer[ret] = '\0';
		save = ft_strdup(buffer);
		free(buffer);
	}
	while (1)
	{
		if (save[i] == '\n')
		{
			save[i] = '\0';
			*line = ft_strdup(save);
			free(save);
			save = ft_strdup(&save[i + 1]);
			return (1);
		}
		else if (save[i] == '\0')
		{
			if ((ret = read(fd, buffer, BUFFER_SIZE)) == 0)
			{
				*line = ft_strdup(save);
				free(save);
				free(buffer);
				//buffer = NULL;
				return (0);
			}
			buffer[ret] = '\0';
			save = ft_strjoin(save, buffer);
			//free(buffer);
			//buffer = NULL;
			i--;
		}
		i++;
	}
	return (0);
}
*/
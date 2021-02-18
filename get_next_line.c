/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:00:23 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/01/19 16:00:26 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
static int	save_buffer(int fd, char *buffer, char *save, char **line)
{
	int		ret;

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if ((ret = read(fd, buffer, BUFFER_SIZE)) == 0)
	{
		*line = ft_strdup(save);
		return (0);
	}
	buffer[ret] = '\0';
	return (1);
}
*/
int			get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buffer;
	int			i;
	int			ret;


	i = 0;
	if (fd <= -1 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!save)
	{
		if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		if ((ret = read(fd, buffer, BUFFER_SIZE)) == 0)
		{
			*line = "";
			//free(buffer);
			return (0);
		}
		buffer[ret] = '\0';
		save = ft_strdup(buffer);
		//free(buffer);
	}
	while (1)
	{
		if (save[i] == '\n')
		{
			save[i] = '\0';
			*line = ft_strdup(save);
			save = ft_strdup(&save[i + 1]);
			return (1);
		}
		else if (save[i] == '\0')
		{
			if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
				return (-1);
			if ((ret = read(fd, buffer, BUFFER_SIZE)) == 0)
			{
				*line = ft_strdup(save);
				return (0);
			}
			buffer[ret] = '\0';
			save = ft_strjoin(save, buffer);
			free(buffer);
			i--;
		}
		i++;
	}
}

int		main(void)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("test", O_RDONLY);
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

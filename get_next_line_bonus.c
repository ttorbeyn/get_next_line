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

#include "get_next_line_bonus.h"

static int	save_buffer(int fd, char *buffer, char *save, char **line)
{
	int		ret;

	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret == -1)
		return (-1);
	if (ret == 0)
	{
		*line = ft_strdup(save);
		return (0);
	}
	buffer[ret] = '\0';
	return (1);
}
/*
static int	return_one(char *save, char **line, int i)
{
	char	*tmp;

	tmp = ft_strdup(save);
	save[i] = '\0';
	*line = ft_strdup(save);
	save = ft_strdup(&save[i + 1]);
	return (1);
}
*/
int			get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buffer;
	long		i;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!save)
		save = ft_strdup("");
	i = 0;
	while (1)
	{
		if (save[i] == '\n')
		{
			save[i] = '\0';
			*line = ft_strdup(save);
			save = ft_strdup(&save[i + 1]);
			return (1);
		}
		if (save[i] == '\0')
		{
			if (save_buffer(fd, buffer, save, line) == 0)
				return (0);
			save = ft_strjoin(save, buffer);
			i--;
		}
		i++;
	}
	return (0);
}
/*
int			main(void)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("alphabet", O_RDONLY);
	while (1)
	{
		ret = get_next_line(-5, &line);
		printf("%d -- |%s|\n", ret, line);
		break;
		free(line);
		if (ret == 0)
			break ;
	}
	return (0);
}
*/
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
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

int		check_if(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (0);
}

static char *ft_read(int fd)
{
	char	*buffer;
	int		ret;

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	if ((ret = read(fd, buffer, BUFFER_SIZE)) < 0)
		return (NULL);
	buffer[ret] = '\0';
	return (buffer);
}

static char *line_cat(char *new, int fd)
{
	char *buffer;

	buffer = ft_read(fd);
	new = ft_strjoin(new, buffer);
	free(buffer);
	return (new);
}

int		get_next_line(int fd, char **line)
{
	static char	*new;
	char		*buffer;
	int			i;

	if ((new && check_if(new) == 0) || !new)
	{
		buffer = ft_read(fd);
		if (new && check_if(new) == 0)
			new = ft_strjoin(new, buffer);
		else
			new = ft_strdup(buffer);
		free(buffer);
	}
	i = 0;

	while (ft_strlen(new) > 0)
	{
		//printf("len new	:	%lu\n", ft_strlen(new));
		if (new[i] == '\n')
		{
			//new[i] = '\0';
			*line = ft_strndup(new, i);
			new = ft_strdup(&new[i + 1]);
			//printf("new	:	%s\n", new);
			return (1);
		}
		if (new[i] == '\0' && ft_strlen(new) > 1)
		{
			new = line_cat(new, fd);
			i--;
		}
		i++;
	}
	printf("new	:	%s\n", new);
	free(new);
	return (0);
}

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
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

static char *line_cat(char *new, int fd)
{
	int ret;
	char *buffer;

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	ret = read(fd, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	new = ft_strjoin(new, buffer);
	//free(buffer);
	return (new);
}


int		get_next_line(int fd, char **line)
{
	static char	*new;
	char		*buffer;
	int			i;
	int			ret;

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	//on regarde si new existe et s'il contient pas de \n
	if (new && check_if(new) == 0)
		new = ft_strjoin(new, buffer);
	//Si new n'existe pas on y met le buffer
	else if (!new)
		new = ft_strdup(buffer);
	//printf("new	:	%s\n", new);
	free(buffer);
	i = 0;
	while (1)
	{
		if (new[i] == EOF)
			break ;
		if (new[i] == '\n')
		{
			*line = ft_strndup(new, i);
			//i++;
			new = ft_strdup(&new[i + 1]);
			return (1);
		}
		else if (new[i] == '\0')
		{
			new = line_cat(new, fd);
			i--;
		}
		i++;

	}
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
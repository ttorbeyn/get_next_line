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

int		get_next_line(int fd, char **line)
{
	static char	*new;
	char		*buffer;
	int 		ret;
	int			i;

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE))))
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	if (new && check_if(new) == 0)
		new = ft_strjoin(new, buffer);
	else if (!new)
		new = ft_strdup(buffer);
	i = 0;
	while (1)
	{
		if (new[i] == '\n')
		{
			*line = ft_strndup(new, i);
			i++;
			new = ft_strdup(&new[i]);

			return (1);
		}
		else if (new[i] == '\0')
		{
			if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
				return (-1);
			ret = read(fd, buffer, BUFFER_SIZE);
			new = ft_strjoin(new, buffer);
			break;
		}
		i++;
		//free(buffer);
	}
	return (0);
}


int main()
{
	int fd;
	int ret;
	char *line;

	fd = open("test", O_RDONLY);
	while(1)
	{
		ret = get_next_line(fd, &line);
		printf("%d -- |%s|\n", ret, line);
		free(line);
		if (ret == 0)
			break;
	}
	return (0);
}
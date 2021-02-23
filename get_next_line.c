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

static int	save_buffer(int fd, char *buffer, char *save, char **line)
{
	int	ret;
	char *tmp;

	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret == -1)
		return (-1);
	if (ret == 0)
	{
		tmp = buffer;
		*line = ft_strdup(save);
		free(tmp);
		tmp = NULL;
		return (0);
	}
	buffer[ret] = '\0';
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*save;
	int			i;
	char 		*buffer;
	int 		ret;
	char *tmp;

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
			tmp = save;
			*line = ft_strdup(save);

			save = ft_strdup(&save[i + 1]);
			free(tmp);
			tmp = NULL;
			free(buffer);
			return (1);
		}
		if (save[i] == '\0')
		{
			ret = save_buffer(fd, buffer, save, line);
			if (ret == 0)
			{
				if (i > 0)
					free(save);
				return (0);
			}
			if (ret == -1)
				return (-1);
			save = ft_strjoin(save, buffer);
			i--;
		}
		i++;
	}
	return (0);
}
/*
int main()
{
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;

	j = 1;
	if (!(fd = open("files/41_char", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (!(fd = open("files/42_char", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (!(fd = open("files/43_char", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 1)
		printf("\nRight number of lines\n");
	else if (j != 1)
		printf("\nNot Good - Wrong Number Of Lines\n");
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
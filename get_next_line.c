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

int get_next_line(int fd, char **line)
{
	char *buffer;
	char *save;
	int i;
	int x;
	int y;
	int a;

	i = 0;
	x = 0;
	y = 0;
	a = 0;
	if (!(save = malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (0);
	if (!(buffer = malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (0);
	if (!(*line = malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (0);
	read(fd, buffer, BUF_SIZE);
	while (buffer[i] && buffer[i] != '\n')
	{
		line[x][y++] = buffer[i++];
	}
	z = 0;
	if (buffer[i] == '\n')
	{
		a = 1;
		i++;
		while (buffer[i])
			save[z++] = buffer[i++];
	}
	line[x][y] = '\0';
	return (a);
}

int main()
{
	int fd;
	int a;
	int ret;
	char **line;

	if (!(line = malloc(sizeof(char *) * (BUF_SIZE + 1))))
		return (0);
	if (!(*line = malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (0);
	fd = open("test", O_RDONLY);
	if (fd == -1)
	{
		printf("open error");
		return (1);
	}
	a = 0;
	while (a < 15)
	{
		ret = get_next_line(fd, line);
		printf("%d -- |%s|\n", ret, *line);
		a++;
	}
	if (close(fd) == -1)
	{
		printf("close error");
		return (1);
	}
	return (0);
}
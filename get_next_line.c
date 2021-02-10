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
	static char *save;
	static char *save2;
	int i;
	int x;
	int y;
	int z;
	int a;
	int b;
	static int ret;
	static int s;


	x = 0;
	y = 0;
	a = 0;
	b = 0;
	z = 0;
	while (s && save2[b] != '\n')
	{
		save[z++] = save2[b++];
		s--;
	}
	printf("save	:	%s\n", save);
	if (!(save = malloc(sizeof(char) * (100))))
		return (-1);
	if (!(save2 = malloc(sizeof(char) * (100))))
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (-1);
	if (!(*line = malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (-1);



	printf("save2	:	%s\n", save2);
	ret = read(fd, buffer, BUF_SIZE);

	printf("save	:	%s\n", save);
	while (ret)
	{
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
		{
			save[z++] = buffer[i++];
			ret--;
		}
		if (buffer[i] == '\n')
		{
			s = ret;
			i++;
			b = 0;
			while (ret)
			{
				save2[b++] = buffer[i++];
				ret--;
			}
			printf("save2	:	%s\n", save2);
			break;
		}
		else
			ret = read(fd, buffer, BUF_SIZE);
		/*while (ret)
		{
			save2[z++] = buffer[i++];
			ret--;
		}*/
		/*
		if (buffer[i] == '\n')
		{
			a = 1;
			i++;
			while (buffer[i] && buffer[i] != '\n')
				save[z++] = buffer[i++];
			save[z] = '\0';
			break;
		}*/
	}
	/*b = 0;
	while (ret)
	{
		save2[b++] = buffer[i];
		ret--;
	}*/
	save[z] = '\0';
	z = 0;
	while (save[z])
		line[x][y++] = save[z++];
	line[x][y] = '\0';
	//printf("%s\n", save);
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
	while (a < 5)
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
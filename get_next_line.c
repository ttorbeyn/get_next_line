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

/*int get_next_line(int fd, char **line)
{
	char *buffer;
	static char *save;
	int i;
	int x;
	int y;
	int a;
	int b;
	static int ret;
	static int s;


	x = 0;
	y = 0;
	a = 0;
	b = 0;

	if (!(*line = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (s > 1 && save[b] != '\n')
	{
		line[x][y++] = save[b++];
		s--;
	}
	//printf("save1	:	%s\n", save);
	//printf("z	:	%d\n", z);
	if (!(save = malloc(sizeof(char) * (100))))
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret)
	{
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
		{
			line[x][y++] = buffer[i++];
			ret--;
		}
		//printf("buffer	:	%s\n", buffer);
		//printf("save	:	%s\n", save);
		if (buffer[i] == '\n')
		{
			s = ret;
			i++;
			b = 0;
			while (ret)
			{
				save[b++] = buffer[i++];
				ret--;
			}
			break;
		}
		else
			ret = read(fd, buffer, BUFFER_SIZE);
	}
	line[x][y] = '\0';
	return (a);
}
*/
/*
int	line_len(int fd)
{
	int x;
	int i;
	char *buffer;

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	x = read(fd, buffer, BUFFER_SIZE);
	i = 0;
	while (x && buffer[i] != '\n')
	{
		while (buffer[i] != '\n')
		{
			i++;
			x--;
		}
		if (buffer[i] == '\n')
			return (i);
		else
			x = read(fd, buffer, BUFFER_SIZE);
	}
	return (i);
}

void	**save_overflow(char **line, char *save, int s)
{
	int y;
	int x;
	int b;

	x = 0;
	b = 0;
	y = 0;
	while (s > 1 && save[b] != '\n')
	{
		line[x][y++] = save[b++];
		s--;
	}
}


int		get_next_line(int fd, char **line)
{
	char *buffer;
	char *buffer2;
	static char *save;
	int i;
	int x;
	int y;
	int a;
	int b;
	int ret;
	static int s;
	int z;


	x = 0;
	a = 0;
	b = 0;
	if (!(*line = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	y = 0;
	if (s)
		save_overflow(line, save, s);
	printf("save_o	:	%s\n", save);
	printf("save_o	:	%s\n", line[x]);

	while (s && save[b] != '\n')
	{
		line[x][y++] = save[b++];
		s--;
	}
	//printf("save1	:	%s\n", save);
	//printf("line1	:	%s\n", line[x]);
	//printf("y	:	%d\n", y);
	if (!(save = malloc(sizeof(char) * (1000))))
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 2))))
		return (-1);
	//printf("save2	:	%s\n", save);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret)
	{
		//printf("bufferA	:	%s\n", buffer2);
		//printf("lineA	:	%s\n", line[x]);
		i = 0;
		z = 0;
		buffer2 = ft_strdup(buffer);
		while (buffer2[i] && buffer2[i] != '\n' && z < 10)
		{
			line[x][y++] = buffer2[i++];
			ret--;
			z++;
		}
		//printf("y	:	%c\n", line[x][7]);
		//printf("buffer3	:	%s\n", buffer2);
		//printf("line	:	%s\n", line[x]);
		if (buffer2[i] == '\n')
		{
			s = ret;
			i++;
			b = 0;
			while (ret)
			{
				save[b++] = buffer2[i++];
				ret--;
			}
			break;
		}
		else
			ret = read(fd, buffer, BUFFER_SIZE);
	}
	line[x][y] = '\0';
	return (a);
}
*/
/*
int		get_next_line(int fd, char **line)
{
	char *buffer;
	static char *save;
	static int j;
	int i;
	int x;
	int y;
	int z;
	int a;
	int ret;

	i = 0;
	x = 0;
	y = 0;
	a = 0;
	z = 0;

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!(*line = malloc(sizeof(char) * (100))))
		return (-1);
	while (j && save[z] != '\n')
	{
		line[x][y++] = save[z++];
		j--;
	}
	printf("save	:	%s\n", save);
	if (!(save = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	j = 0;
	while (buffer[i])
	{
		while (buffer[i] != '\n' && ret)
		{
			line[x][y++] = buffer[i++];
			ret--;
		}
		if (buffer[i] == '\n')
		{
			//ret--;
			//i++;
			z = 0;
			while (buffer[i])
			{
				save[z++] = buffer[i++];
				j++;
			}
			save[z] = '\0';
			a = 1;
		}
		else
			read(fd, buffer, BUFFER_SIZE);
	}
	line[x][y] = '\0';
	return (a);
}
*/

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
	static char	*new = 0;
	char		*buffer;
	int ret;

	if (!(*line = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	printf("buffer	:	%s\n", buffer);
	printf("new	:	%s\n", new);
	if (new && check_if(new) == 0)
		new = ft_strjoin(new, buffer);
	else if (!new)
		new = ft_strdup(buffer);
	printf("new2	:	%s\n", new);
	while (new)
	{
		if (check_if(new))
		{
			*line = ft_strndup(new, check_if(new));
			new = &new[check_if(new) + 1];
			printf("Coucou\n");
			return (1);
		}
		else
		{
			if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
				return (-1);
			ret = read(fd, buffer, BUFFER_SIZE);
			new = ft_strjoin(new, buffer);
		}
		free(buffer);
	}
	return (0);
}


int main()
{
	int fd;
	int a;
	int ret;
	char **line;

	if (!(line = malloc(sizeof(char *) * (100))))
		return (0);
	if (!(*line = malloc(sizeof(char) * (100))))
		return (0);
	fd = open("test", O_RDONLY);
	if (fd == -1)
	{
		printf("open error");
		return (1);
	}
	a = 0;
	while (a < 4)
	{
		ret = get_next_line(fd, line);
		printf("%d -- |%s|\n", ret, *line);
		//printf("%d\n", line_len(fd));
		a++;
	}
	if (close(fd) == -1)
	{
		printf("close error");
		return (1);
	}
	return (0);
}
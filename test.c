int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buffer
	int			i;
	int			ret;

	i = 0;
	if (!save)
	{
		if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		if (ret = read(fd, buffer, BUFFER_SIZE) == 0)
			return (0);
		buffer[ret] = '\0';
		save = strjoin(save, buffer);
	}
	while (1)
	{
		if (save[i] == '\n')
		{
			save[i] = '\0';
			*line = strdup(save);
			save = strdup(&save[i + 1]);
			return (1);
		}
		else if (save[i] == '\0')
		{
			if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
				return (-1);
			if (ret = read(fd, buffer, BUFFER_SIZE) == 0)
				return (0);
			buffer[ret] = '\0';
			save = strjoin(save, buffer);
		}
		i++;
	}
}
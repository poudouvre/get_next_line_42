
void	ft_lines(char **lines, char *stock)
{
	int len;
	char *tmp;

	len = 0;
	while (stock[len] != '\0' && stock[len] != '\n')
		len++;

	*line = ft_substr(stock, 0, len);

	if (stock[len] == '\0')
		free(stock);

	else
	{
		tmp = ft_substr(stock, len + 1, ft_strlen(stock));
		free(stock);
		stock = ft_strdup(tmp);
		free(tmp);
	}

int values(char **lines, char *stock, int ret)
{
	if (ret < 0)
	{
		free(stock);
		return (-1);
	}

	else if (ret == 0 && !stock)
	{
		*lines = ft_strdup("");
		return (0);
	}

	else if (!(ft_strchr(stock, '\n')))
	{
		*lines = ft_strdup(stock);
		free(stock);
		return (0);
	}

	else
	{
		ft_line(lines, stock);
		return (1);
	}
}

int	gnl(int fd, char **lines)
{
	int ret;
	char buff[BUFF_SIZE + 1];
	char *tmp;
	static char *stock;

	if (fd < 0 || fd > 256 || !*lines || BUFFER_SIZE < 1)
		return (-1);

	ret = read(fd, buff, BUFFER_SIZE);

	while (ret > 0)
	{
		buff[ret] = 0;

		if (!stock)
			stock = ft_strdup(buff);

		else
		{
			tmp = ft_strdup(stock);
			free(stock);
			stock = ft_strjoin(tmp, buff);
			free(tmp);
		}

		if (ft_strchr(stock, '\n'))
			break ;

		ret = read(fd, buff, BUFFER_SIZE);
	}

	return ft_valeus(lines, stock, ret);
}

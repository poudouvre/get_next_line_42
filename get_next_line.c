#include "get_next_line.h"

int	ft_lines(char **stock, char **line)
{
	int len;
	char *tmp;

	len = 0;

	while ((*stock)[len] != '\0' && (*stock)[len] != '\n')
		len++;

	*line = ft_substr(*stock, 0, len);

	if ((*stock)[len] == '\0')
	{
		free(*stock);
		return (0);
	}
	
	else
	{
		tmp = ft_substr(*stock, len + 1, ft_strlen(*stock));
		free(*stock);
		*stock = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
}


int	ft_value(char **stock, char **line, int ret)
{
	if (ret < 0)
	{
		free(*stock);
		return (-1);
	}

	else if (ret == 0 && !(*stock))
	{
		*line = ft_strdup("");
		free(*stock);
		return (0);
	}
	
	else
	{
		return (ft_lines(stock, line));
	}
}

int	get_next_line(int fd, char **line)
{
	int	ret;
	char buff[BUFFER_SIZE + 1];
	char *tmp;
	static char *stock;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);

	ret = read(fd, buff, BUFFER_SIZE);

	while (ret > 0)
	{
		buff[ret] = '\0';

		if (!stock)
			stock = ft_strdup(buff);

		else
		{
			tmp = ft_strjoin(stock, buff);
			free(stock);
			stock = tmp;
		}

		if (ft_strchr(stock, '\n'))
			break ;

		ret = read(fd, buff, BUFFER_SIZE);
	}

	return (ft_value(&stock, line, ret));
}

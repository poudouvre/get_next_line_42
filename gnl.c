
#include "get_next_line.h"

void ft_output(char **line, char *stock)
{
	int	len;
	char *tmp;

	len = 0;
	while (stock[len] != '\n' && stock[len] != '\0')
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
}


int	ft_values(char **line, char *stock, int ret)
{
	if (ret < 0)
	{
		free(stock);
		return (-1);
	}

	else if (ret == 0 && !stock)
	{
		*line = ft_strdup("");
		return (0);
	}

	else if (!(ft_strchr(stock, '\n')))
	{
		*line = ft_strdup(stock);
		free(stock);
		return (0);
	}

	else
	{
		ft_output(line, stock);
		return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		*tmp;
	char		buff[BUFFER_SIZE + 1];
	static char	*stock;

	if (fd < 0 || fd > 256 || !*line || BUFFER_SIZE < 1)
		return(- 1);

	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';

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
	}

	return (ft_values(line, stock, ret));
}

int main(void)
{
	char *line[500];
	int fd = open("test.txt", O_RDONLY);

	gnl(fd, line);
	gnl(fd, line);
	gnl(fd, line);
	gnl(fd, line);
	close(fd);

	return (0);
}

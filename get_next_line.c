/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:30:13 by nrubin            #+#    #+#             */
/*   Updated: 2021/01/19 14:50:14 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lines(char **line, char **stock)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*stock)[len] != '\0' && (*stock)[len] != '\n')
		len++;
	*line = ft_substr(*stock, 0, len);
	if ((*stock)[len] == '\0')
	{
		free(*stock);
		*stock = NULL;
		return (0);
	}
	else
	{
		tmp = ft_substr(*stock, len + 1, ft_strlen(*stock));
		free(*stock);
		*stock = NULL;
		*stock = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
		return (1);
	}
}

int	ft_value(int ret, char **line, char **stock)
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
		return (ft_lines(line, stock));
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	static char *stock[256];

	ret = read(fd, buff, BUFFER_SIZE);
	if (BUFFER_SIZE < 1 || !line || ret == -1)
		return (-1);
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (!(stock[fd]))
			stock[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(stock[fd], buff);
			free(stock[fd]);
			stock[fd] = ft_strdup(tmp);
			free(tmp);
		}
		if (ft_strchr(stock[fd], '\n'))
			break ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_value(ret, line, &(stock[fd])));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:30:13 by nrubin            #+#    #+#             */
/*   Updated: 2021/01/22 15:52:13 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// This function fills line until either newline or EOF are encountered. If EOF is encountered
// 0 is simply returned. If newline is encountered, 1 is returned and stock is filled with the
// leftover bytes.

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

// This function checks for and handles two specific cases, otherwise passing line and stock to another function.

int	ft_value(int ret, char **line, char **stock)
{
	if (ret < 0) // in case a read fails midway
	{
		free(*stock);
		return (-1);
	}
	else if (ret == 0 && !(*stock)) // in case the read is successful but the file is empty
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (ft_lines(line, stock));
}

// This function will call read in a loop until reaching EOF. If it is the first call of the function, stock is filled
// with the buffer read. If it isn't, the new buffer read is appendend to stock. This process is repeated until a newline
// is reached. Both stock and line are passed to ft_value and ft_lines which will fill each appropriately depending on
// EOF or newline being reached first.

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	static char *stock[256]; // amd array for 256 strings is created so as to allow multiple calls on differents FDs.

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:38:53 by nrubin            #+#    #+#             */
/*   Updated: 2020/12/02 12:50:23 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 5 

int	get_next_line(int fd)
{
	int	ret;
	char buf[BUFFER_SIZE + 1];
	static char *str;
	char *stock;
	int i;
	char *join;

	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = 0;
	
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;

	str = ft_substr(buf, 0, i);
	stock = ft_substr(buf, i+1, BUFFER_SIZE);
	printf("str: %s\n", str);
	//str = ft_strjoin(stock, buf);
	//printf("\n");
	printf("stock:%s\n", stock);
	//printf("\n");
	//printf("join %s", join);
	free(stock);
	free(str);
	//free(join);
	return (0);
}

int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return (0);
}

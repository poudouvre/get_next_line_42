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

<<<<<<< HEAD
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
=======
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 10

int	main()
{
	int	fd; // the file descriptor
	fd = open("test.txt", O_RDONLY);

	char *buff = (char *)malloc(BUFF_SIZE * sizeof(char));

	int ret;

	static char str[5000];
	
	while (ret = read("test.txt", str, BUFF_SIZE) > 0)
	{
		if (str == NULL)
			str = strdup(buff);
		else 


	printf("fd is %i\nnumber of bytes read: %i\nbytes read: %s\n", fd, bytes, str);
>>>>>>> 263262f5f6eb9d011f31a7ee6c0cdc87a211ce3e
	return (0);
}

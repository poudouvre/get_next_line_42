/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:38:53 by nrubin            #+#    #+#             */
/*   Updated: 2020/11/27 19:26:46 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (0);
}

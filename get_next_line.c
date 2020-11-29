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

#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;

	fd = open("test.txt", O_RDONLY);

	printf("%i\n", fd);

	read(fd, )

}

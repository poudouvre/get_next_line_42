/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:43:39 by nrubin            #+#    #+#             */
/*   Updated: 2020/12/01 18:14:36 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		size++;
		s++;
	}
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(*ret) * (len + 1))))
		return (NULL);
	while (s1[i])
	{
		ret[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		ret[j] = s2[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ret = malloc(sizeof(char));
		ret[0] = 0;
		return (ret);
	}
	if (!(ret = (char *)malloc(sizeof(*ret) * (len + 1))))
		return (NULL);
	while (s[start] && i < len)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}

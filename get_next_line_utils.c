/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:52:30 by asaracut          #+#    #+#             */
/*   Updated: 2024/12/24 16:41:55 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}

char	*ft_strchr(const char *string, int searchedChar )
{
	char	*str;

	str = (char *)string;
	while (*str != searchedChar && *str != 0)
		str++;
	if (*str == searchedChar)
		return (str);
	else
		return (NULL);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;
	size_t	totalsize;
	size_t	i;

	totalsize = elementCount * elementSize;
	res = malloc(totalsize);
	if (!res)
		return (NULL);
	i = 0;
	while (i < totalsize)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_free_and_join(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	if (!temp)
	{
		free(buffer);
		free(buf);
		return (NULL);
	}
	free(buffer);
	return (temp);
}

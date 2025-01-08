/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 06:25:26 by asaracut          #+#    #+#             */
/*   Updated: 2025/01/08 07:57:15 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print(char *s)
{
	return(write(1, s, ft_strlen(s)));
}

char	*ft_strdup(const char	*src)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *) malloc(ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 06:25:26 by asaracut          #+#    #+#             */
/*   Updated: 2025/01/19 23:21:37 by asaracut         ###   ########.fr       */
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

void	free_map_exit(Info *info)
{
    int i;

    i = 0;
    if (info->map) 
	{
        while (info->map[i]) {
            free(info->map[i]);
            i++;
        }
        free(info->map);
    }
	if (info->map_final) 
	{
        i = 0;
        while (info->map_final[i]) {
            free(info->map_final[i]);
            i++;
        }
        free(info->map_final);
    }
	exit(1);
}

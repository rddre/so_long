/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:54:47 by asaracut          #+#    #+#             */
/*   Updated: 2024/12/29 07:55:53 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h> // a retirer apres le test

int	so_long_parsing(int	fd)
{
	char	*line;
	
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return (1);
}
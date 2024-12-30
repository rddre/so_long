/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:54:47 by asaracut          #+#    #+#             */
/*   Updated: 2024/12/30 06:29:32 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h> // a retirer apres le test
void	print_map(char **map) 
{
    int i = 0;
    
    // Parcours chaque ligne de la map
    while (map[i])
    {
        // Parcours chaque caractère de la ligne
        int j = 0;
        while (map[i][j])  
        {
            // Affichage des caractères normalement
            printf("%c", map[i][j]);
            j++;
        }
        printf("\n");  // Nouvelle ligne après chaque ligne de la map
        i++;
    }
}

int map_height_calcul(int *fd)
{
    char buffer[1];
    int line_count = 0;
    int bytes_read;

    while ((bytes_read = read(*fd, buffer, 1)) > 0)
    {
		write(1, buffer, 1);
        if (buffer[0] == '\n')
            line_count++;
    }
    if (bytes_read < 0)
		return (0);
    if (close(*fd) < 0)
		return (0);
    *fd = open("map.ber", O_RDONLY); // pas bon du tout
    if (*fd < 0)
		return (0);
    return line_count;
}

int	check_cube(char	*line)
{
	printf("%zu\n", ft_strlen(line));
	return (1);
}

int	so_long_parsing(int	*fd)
{
	char	**map;
	int		y;
	int		y_max;
	
	
	y = 0;
	y_max = map_height_calcul(fd);
	if (y_max == 0)
		return (0);
	map = malloc(sizeof(char *) * y_max);
    if (!map)
        return (0);
	
	while ((map[y] = get_next_line(*fd)))
	{
		printf("%zu\n", ft_strlen(map[y]));
		check_cube(map[y]);
		y++;
	}
	print("\n");
	print_map(map);
	return (1);
}

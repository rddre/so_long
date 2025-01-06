/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:54:47 by asaracut          #+#    #+#             */
/*   Updated: 2025/01/06 03:27:11 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	check_conform(Info *info)
{
	int	i;

	i = 0;
	while (i < info->x)
	{
		if (info->map[0][i] != '1' || info->map[info->y - 1][i] != '1')
		{
			print("Erreur : il faut des 1 tout au tour >:{\n");
			exit(1);	
		}
		i++;
	}
	i = 1;
	while (i < (info->y - 1))
	{
		if (info->map[i][0] != '1' || info->map[i][info->x - 1] != '1')
		{
			print("Erreur : il faut des 1 tout au tour >:{\n");
			exit(1);
		}
		i++;
	}
}

void	add_stat(char c, Info *info)
{
	if (c == 'P')
		info->player++;
	if (c == 'E')
		info->exit++;
	if (c == 'C')
		info->collect++;
	if (info->player > 1)
	{
		print("Erreur : trop de joueur sur la map. :[]\n"); //a chqnger !=
		exit(1);
	}
	if (info->exit > 1)
	{
		print("Erreur : trop de sortie sur la map. :-]\n");
		exit(1);
	}
}

int	check_cube(Info *info, char	*line)
{
	int i;

	if (info->y == 0)
		info->x = ft_strlen(line);
	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'E'
			&& line[i] != 'C' && line[i] != 'P' && line[i] != '\n')
		{
			print("Erreur : caractère invalide trouvé. >:|\n");
			exit(1);
		}
		add_stat(line[i], info);
		i++;
	}
	if (i != info->x)
	{
		print("Erreur : la map n'est pas rectangulaire *_*");
		exit(1);
	}
	info->y++;
	return (1);
}

int	so_long_parsing(int	fd, Info *info)
{
	info->map = malloc(sizeof(char *) * 200);
		if (!info->map)
				return (0);
	info->y = 0;
	while ((info->map[info->y] = get_next_line(fd)))
	{
		check_cube(info, info->map[info->y]);
	}
	info->map[info->y] = NULL;
	if (info->y < 3 || info->x < 3)
		return (0);
	check_conform(info);
	back_traking(info);
	return (1);
}

/*               pour afficher la map
-----------------------------------------------------------
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
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:54:47 by asaracut          #+#    #+#             */
/*   Updated: 2025/01/08 11:02:08 by asaracut         ###   ########.fr       */
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

void	add_stat(char c, Info *info, int x, int y)
{
	if (c == 'P')
	{
		info->player++;
		info->player_x = x;
		info->player_y = y;
	}
	if (c == 'E')
	{
		info->exit++;
		info->exit_x = x;
		info->exit_y = y;
	}
	if (c == 'C')
		info->collect++;
	if (info->player > 1)
	{
		print("Erreur : trop de joueur sur la map. :[]\n");
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
			&& line[i] != 'C' && line[i] != 'P')
		{
			print("Erreur : caractère invalide trouvé. >:|\n");
			exit(1);
		}
		add_stat(line[i], info, i, info->y);
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
	if (info->x > 500 || info->y > 200)
	{
		print("Erreur : la map est trop grande");
		exit(1);
	}
	if (info->player < 1 || info->exit < 1 || info->collect < 1)
	{
		print("Erreur : il y a pas de jour ou de sortie sur la map :(");
		exit(1);
	}
	check_conform(info);
	back_traking(info);
	return (1);
}

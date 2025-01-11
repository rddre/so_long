/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_back_traking.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:42:21 by asaracut          #+#    #+#             */
/*   Updated: 2025/01/08 11:06:48 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void free_map(Info *info)
{
    int i;

    i = 0;
    while (info->map[i]) {
        free(info->map[i]);
        i++;
    }
    free(info->map);
}*/

void copy_map(Info *info)
{
    int i;

    info->map_final = (char **)malloc(sizeof(char *) * (info->y + 1));
    if (!info->map_final)
    {
        print("Erreur : malloc de la copy n'as pas marche x_x");
        exit(1);
    }
    i = 0;
    while (i < info->y)
    {
        info->map_final[i] = ft_strdup(info->map[i]);
        if (!info->map_final[i])
        {
            print("Erreur : strdup de la copy n'as pas marche x_x");
            exit(1);
        }
        i++;
    }
    info->map_final[i] = NULL;
}

int	is_valid_move(Info *info, int x, int y)
{
    if (info->map[y][x] == '1')
        return (0);
    return (1);
}

int	backtracking(Info *info, int x, int y)
{
    if (info->map[y][x] == 'E')
        info->exit_trouve++;
    if (info->map[y][x] == 'C')
        info->collect_trouve++;
		
    info->map[y][x] = '1';

    if (is_valid_move(info, x + 1, y))
		backtracking(info, x + 1, y);
    if (is_valid_move(info, x - 1, y))
		backtracking(info, x - 1, y);
    if (is_valid_move(info, x, y + 1))
		backtracking(info, x, y + 1);
    if (is_valid_move(info, x, y - 1))
		backtracking(info, x, y - 1);

    return (1);
}

void	back_traking(Info *info)
{
	copy_map(info);
	backtracking(info, info->player_x, info->player_y);
	if (info->collect == info->collect_trouve && info->exit_trouve == 1)
        print("reussi : Le joueur peut atteindre la sortie ! ^_^\n");
    else
	{
        print("Erreur : Aucun chemin trouvé vers la sortie. O_O'\n");
		exit(1);
	}
}

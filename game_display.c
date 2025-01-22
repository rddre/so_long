/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 06:25:26 by asaracut          #+#    #+#             */
/*   Updated: 2025/01/22 04:29:59 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_close(Info *info)
{
	print("tu a etaind le jeu (ㆆ _ ㆆ)\n");
	free_images(info);
	if (info->display)
		mlx_destroy_window(info->mlx, info->display);
	free_map_exit(info);
	return (1);
}

void render_map(void *mlx, void *win, char **map, Info *info)
{
	int x = 0;
	int y = 0;
	int img_width, img_height;

	info->wall_img = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &img_width, &img_height);
	info->floor_img = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &img_width, &img_height);
	info->collectible_img = mlx_xpm_file_to_image(mlx, "img/collectible.xpm", &img_width, &img_height);
	info->exit_img = mlx_xpm_file_to_image(mlx, "img/exit.xpm", &img_width, &img_height);
	info->player_img = mlx_xpm_file_to_image(mlx, "img/player.xpm", &img_width, &img_height);


	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '1') mlx_put_image_to_window(mlx, win, info->wall_img, x * 50, y * 50);
			else if (map[y][x] == '0') mlx_put_image_to_window(mlx, win, info->floor_img, x * 50, y * 50);
			else if (map[y][x] == 'C') mlx_put_image_to_window(mlx, win, info->collectible_img, x * 50, y * 50);
			else if (map[y][x] == 'E') mlx_put_image_to_window(mlx, win, info->exit_img, x * 50, y * 50);
			else if (map[y][x] == 'P') mlx_put_image_to_window(mlx, win, info->player_img, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

int move_player(int x, int y, Info *info)
{
	if (info->map_final[y][x] == '1')
		return (0);
	else if (info->map_final[y][x] == '0')
	{
		info->map_final[y][x] = 'P';
		info->map_final[info->player_y][info->player_x] = '0';
	}
	else if (info->map_final[y][x] == 'C')
	{
		info->map_final[y][x] = 'P';
		info->map_final[info->player_y][info->player_x] = '0';
		info->collect_trouve++;
	}
	else if (info->map_final[y][x] == 'E')
	{
		print("tu a gagne !!! (ᕗ ͠° ਊ ͠° )ᕗ");
		free_images(info);
		free_map_exit(info);
	}
	info->player_x = x;
	info->player_y = y;
	if (info->collect_trouve == info->collect)
		info->map_final[info->exit_y][info->exit_x] = 'E';
	return (1);
}

int handle_keypress(int keycode, Info *info)
{
	if (keycode == 119)  // W - haut
		move_player(info->player_x, info->player_y - 1, info);
	else if (keycode == 115)  // S - bas
		move_player(info->player_x, info->player_y + 1, info);
	else if (keycode == 97)  // A - gauche
		move_player(info->player_x - 1, info->player_y, info);
	else if (keycode == 100)  // D - droite
		move_player(info->player_x + 1, info->player_y, info);
	else if (keycode == 65307)  // Esc - quitter
	{
		print("esc\n");
		handle_close(info);
		return (0);
	}

	// Rendu de la nouvelle carte
	render_map(info->mlx, info->display, info->map_final, info);
	
	return (0);
}

void	game_display(Info *info)
{
	info->mlx = mlx_init();
	info->display = mlx_new_window(info->mlx, info->x * 50, info->y * 50, "so_long");

	render_map(info->mlx, info->display, info->map_final, info);

	mlx_hook(info->display, 17, 0, handle_close, NULL);

	mlx_key_hook(info->display, handle_keypress, info);

	mlx_loop(info->mlx);
}

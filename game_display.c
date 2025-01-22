#include "so_long.h"

int handle_close()
{
    print("tu a etaind le jeu (ㆆ _ ㆆ)\n");
    exit(0);
    return (0);
}

void render_map(void *mlx, void *win, char **map)
{
    int x = 0;
    int y = 0;
    int img_width, img_height;

    void *wall_img = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &img_width, &img_height);
    void *floor_img = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &img_width, &img_height);
    void *collectible_img = mlx_xpm_file_to_image(mlx, "img/collectible.xpm", &img_width, &img_height);
    void *exit_img = mlx_xpm_file_to_image(mlx, "img/exit.xpm", &img_width, &img_height);
    void *player_img = mlx_xpm_file_to_image(mlx, "img/player.xpm", &img_width, &img_height);


    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x] != '\0')
        {
            if (map[y][x] == '1') mlx_put_image_to_window(mlx, win, wall_img, x * 50, y * 50);
            else if (map[y][x] == '0') mlx_put_image_to_window(mlx, win, floor_img, x * 50, y * 50);
            else if (map[y][x] == 'C') mlx_put_image_to_window(mlx, win, collectible_img, x * 50, y * 50);
            else if (map[y][x] == 'E') mlx_put_image_to_window(mlx, win, exit_img, x * 50, y * 50);
            else if (map[y][x] == 'P') mlx_put_image_to_window(mlx, win, player_img, x * 50, y * 50);
            x++;
        }
        y++;
    }
}

int handle_keypress(int keycode, Info *info)
{
    // Déplacement du joueur
    if (keycode == 119)  // W - haut
        print("w\n");
    else if (keycode == 115)  // S - bas
        print("s\n");
    else if (keycode == 97)  // A - gauche
        print("a\n");
    else if (keycode == 100)  // D - droite
        print("d\n");
    else if (keycode == 65307)  // Esc - quitter
    {
        print("esc\n");
        handle_close();  // Appelle la fonction pour fermer le jeu
        return (0);
    }

    // Rendu de la nouvelle carte
    render_map(info->mlx, info->display, info->map_final);
    
    return (0);
}

void	game_display(Info *info)
{
    info->mlx = mlx_init();
    info->display = mlx_new_window(info->mlx, info->x * 50, info->y * 50, "so_long");

    render_map(info->mlx, info->display, info->map_final);

    mlx_hook(info->display, 17, 0, handle_close, NULL);

    mlx_key_hook(info->display, handle_keypress, info);

    mlx_loop(info->mlx);
}

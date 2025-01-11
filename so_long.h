/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:54:58 by asaracut          #+#    #+#             */
/*   Updated: 2025/01/11 21:44:50 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include "mlx/mlx.h"

typedef struct {
	char	**map;
    char    **map_final;
    int		x;
	int		y;
	
    int 	collect;
    int 	player;
    int 	exit;
	
    int     collect_trouve;
    int     exit_trouve;
    
    int 	score;

    int     player_x;
    int     player_y;
    int     exit_x;
    int     exit_y;
} Info;

/*          utils         */
char	*get_next_line(int fd);
int		print(char *s);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char	*src);

/*          parsing         */
int 	so_long_parsing(int	fd, Info *info);
void	back_traking(Info *info);
// visobod505@pofmagic.com QWERTY123ss@
#endif
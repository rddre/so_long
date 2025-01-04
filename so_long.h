/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:54:58 by asaracut          #+#    #+#             */
/*   Updated: 2025/01/04 09:09:36 by asaracut         ###   ########.fr       */
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

typedef struct {
	char	**map;
    int		x;
	int		y;
	
    int 	collect;
    int 	player;
    int 	exit;
	
    int 	score;
} Info;

/*          utils         */
char	*get_next_line(int fd);
int		print(char *s);
size_t	ft_strlen(const char *str);

/*          parsing         */
int	so_long_parsing(int	fd, Info *info);
// visobod505@pofmagic.com QWERTY123ss@
#endif
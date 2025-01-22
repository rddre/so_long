/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:54:55 by asaracut          #+#    #+#             */
/*   Updated: 2025/01/21 22:01:39 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verifi_extension(char *s)
{
	int i;

	i = ft_strlen(s);
	if (i < 5)
		return (0);
	if (s[i - 1] != 'r' || s[i - 2] != 'e' ||
		 s[i - 3] != 'b' || s[i - 4] != '.')
        return (0);
	return (1);
}

int	main(int nbmap, char **map)
{
	int		fd;
	
	Info info = {0};
	if (nbmap != 2)
		return (print("Erreur : il faut UNE map :)"));
	if (verifi_extension(map[1]) == 0)
		return (print("Erreur : l'extension *.ber n'est pas respecte :-)"));
	fd = open(map[1], O_RDONLY);
	if (fd < 0)
		return (print("Erreur : aucune map avec ce nom n'as ete trouve :()"));
	if (so_long_parsing(fd, &info) == 0)
		return (print("Erreur : la map est mal configurer >:()"));
	close(fd);
	game_display(&info);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orca_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:47:36 by desambou          #+#    #+#             */
/*   Updated: 2025/03/20 18:47:45 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_to(int x, int y, t_game *map)
{
	char	type;

	type = map->copy[y][x];
	if (type == 'C')
	{
		map->c_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (type == 'E')
	{
		map->e_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (type == '0' || type == 'P')
		map->copy[y][x] = '1';
	else
		return ;
    movement_to(x + 1, y, map);
	movement_to(x - 1, y, map);
	movement_to(x, y + 1, map);
	movement_to(x, y - 1, map);
}

void	check_filling(t_game *map)
{
	map->c_check = map->c;
	map->e_check = map->e;
	player_status(map);
	movement_to(map->player.x, map->player.y, map);
	if (map->c_check != 0 || map->e_check >= map->e)
	{
		write(2, "NO VALID PATH\n", 14);
		ft_free_array(map->array, map->y);
		ft_free_array(map->copy, map->y);
		exit(EXIT_FAILURE);
	}
}
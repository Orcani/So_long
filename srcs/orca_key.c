/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orca_verification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:49:01 by desambou          #+#    #+#             */
/*   Updated: 2025/03/20 18:49:04 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Update the player location*/
void	player_status(t_game *map)
{
	map->player.y = 0;
	map->player.x = 0;
	while (map->player.y < map->y)
	{
		while (map->player.x < map->x)
		{
			if (map->array[map->player.y][map->player.x] == 'P')
				break ;
			map->player.x++;
		}
		if (map->array[map->player.y][map->player.x] == 'P')
			break ;
		map->player.x = 0;
		map->player.y++;
	}
}

/*Move the player left, right, up and dow but also close the file if the user press ESC or display the 'Win' if the goal is reached*/
int	key_hook(int keycode, t_game *map)
{
	player_status(map);
	if (keycode == ESC)
		return (ft_close(map));
	else if (map->exit_place == 1)
		return (0);
	else if (keycode == LEFT)
		move_left(map);
	else if (keycode == DOWN)
		move_down(map);
	else if (keycode == RIGHT)
		move_right(map);
	else if (keycode == UP)
		move_up(map);
	return (0);
}
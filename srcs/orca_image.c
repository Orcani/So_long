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

/*save the images xmp in the struture to be used somewhere else such as the water, walls, exit, collectible and enemies*/
void	file_to_image(t_game *map)
{
	int	a;

	a = IMG_PXL;
	map->img.water = mlx_xpm_file_to_image(map->mlx,
			"so_long_sprite/Water.xpm", &a, &a);
	map->img.wall = mlx_xpm_file_to_image(map->mlx,
			"so_long_sprite/Walls.xpm", &a, &a);
	map->img.exit_place = mlx_xpm_file_to_image(map->mlx,
			"so_long_sprite/Exit.xpm", &a, &a);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx,
			"so_long_sprite/Collectible.xpm", &a, &a);
	map->img.enemy = mlx_xpm_file_to_image(map->mlx,
			"so_long_sprite/Enemies.xpm", &a, &a);
	file_to_image_player(map);
}

/*save the player xpm in the structure to be used somewhere else*/
void	file_to_image_player(t_game *map)
{
	int	a;

	a = IMG_PXL;
	map->img.player_right1 = mlx_xpm_file_to_image(map->mlx,
			"so_long_sprite/Right_Orca.xpm", &a, &a);
	// map->img.player_right2 = mlx_xpm_file_to_image(map->mlx,
	// 		"Resources/right-2-40.xpm", &a, &a);
	map->img.player_up1 = mlx_xpm_file_to_image(map->mlx,
			"so_long_sprite/Up_Orca.xpm", &a, &a);
	// map->img.player_up2 = mlx_xpm_file_to_image(map->mlx,
	// 		"Resources/up-2-40.xpm", &a, &a);
	map->img.player_down1 = mlx_xpm_file_to_image(map->mlx,
			"so_long_sprite/Down_Orca.xpm", &a, &a);
	// map->img.player_down2 = mlx_xpm_file_to_image(map->mlx,
	// 		"Resources/down-2-40.xpm", &a, &a);
	map->img.player_left1 = mlx_xpm_file_to_image(map->mlx,
			"so_long_sprite/Left_Orca.xpm", &a, &a);
	// map->img.player_left2 = mlx_xpm_file_to_image(map->mlx,
	// 		"Resources/left-2-40.xpm", &a, &a);
}
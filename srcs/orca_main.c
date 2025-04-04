/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orca_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:48:38 by desambou          #+#    #+#             */
/*   Updated: 2025/03/20 18:48:42 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Initalize the map to clean the plate -> good practice for the memory*/
void	map_init(t_game *map, char **av)
{
	map->filename = av[1];
	map->moves = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->y = 0;
	map->player.y = 0;
	map->player.x = 0;
	map->exit_place = 0;
}

int	main(int ac, char **av)
{
	t_game	map;

	if (ac == 2)
	{
		map_init(&map, av);
		map_g_check(&map);
		map.mlx = mlx_init();
		map.wnd = mlx_new_window(map.mlx, map.x
				* IMG_PXL, map.y * IMG_PXL, WND_NAME);
		file_to_image(&map);
		map_duplica(&map);
		mlx_hook(map.wnd, 17, 0, ft_close, &map);
		mlx_key_hook(map.wnd, key_hook, &map);
		mlx_loop(map.mlx);
	}
	write(2, "Usage: ./so_long mapfile\n", 25);
	exit(EXIT_FAILURE);
}
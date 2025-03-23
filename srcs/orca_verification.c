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

/*Check if the name of the file is indeed a .ber and if a name exist for the .ber*/
static void	name_file(t_game *map)
{
	size_t	len;

	len = ft_strlen(map->filename);
	if (map->filename[len - 1] != 'r')
		error_filename();
	if (map->filename[len - 2] != 'e')
		error_filename();
	if (map->filename[len - 3] != 'b')
		error_filename();
	if (map->filename[len - 4] != '.')
		error_filename();
	if (!ft_strnstr(map->filename, ".ber", ft_strlen(map->filename)))
		error_filename();
}

/*Check if all the elements are present for a game such as 1 exit, 1 player, at least a collectible etc...*/
static void	floodfill(t_game *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			if (map->array[y][x] == 'C')
				map->c += 1;
			else if (map->array[y][x] == 'E')
				map->e += 1;
			else if (map->array[y][x] == 'P')
				map->p += 1;
			else if (map->array[y][x] == '0' || map->array[y][x] == '1')
				;
			else
				error_map_elements(map);
			x++;
		}
		x = 0;
		y++;
	}
	if (map->c < 1 || map->e < 1 || map->p != 1)
		error_map_elements(map);
}

/*Checking if the map is indeed rectangular AND has closed walls!*/
static void	wall_check(t_game *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->array[0][x] == '1' && map->array[1][x])
		x++;
	if (map->array[1][x] != '\0')
		error_wall(map);
	y = 1;
	while (y < map->y)
	{
		if (map->array[y][0] != '1' ||
				map->array[y][map->x - 1] != '1')
			error_wall(map);
		y++;
	}
	x = 0;
	while (map->array[map->y - 1][x] == '1')
		x++;
	if (map->array[map->y - 1][x] != '\0')
		error_wall(map);
}

/*Checking if the size of the map is possible. Two lines won't make a map.*/
void	norm_size(t_game *map)
{
	int	y;
	int	x;
	int	max;

	y = 0;
	x = 0;
	max = ft_strlen(map->array[y]);
	while (y < map->y)
	{
		x = ft_strlen(map->array[y]);
		if (max != x)
			error_size(map);
		y++;
	}
	map->x = max;
}

/*Gather all the checking points-> General check.*/
void	map_g_check(t_game *map)
{
	name_file(map);
	// map_array(map);
	norm_size(map);
	wall_check(map);
	floodfill(map);
	check_filling(map);
	ft_free_array(map->copy, map->y);
}
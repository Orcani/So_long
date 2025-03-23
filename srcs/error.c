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

/*write in the error file for an error in the name then free the map before exiting*/
void	error_filename(void)
{
	write(2, "Filename should be a BER extension file\n", 40);
	exit(EXIT_FAILURE);
}

/*write in the error file  for invalid walls then free the map before exiting*/
void	error_wall(t_game *map)
{
	write(2, "Wall not valid\n", 17);
	ft_free_array(map->array, map->y);
	ft_free_array(map->copy, map->y);
	exit(EXIT_FAILURE);
}

/*write in the error file for failing to open the file before exiting*/
void	error_openfile(void)
{
	write(2, "failed open\n", 12);
	exit(EXIT_FAILURE);
}

/*write in the error file due to the size of the map then free the map before exiting*/
void	error_size(t_game *map)
{
	write(2, "Size not valid\n", 15);
	ft_free_array(map->array, map->y);
	ft_free_array(map->copy, map->y);
	exit(EXIT_FAILURE);
}

/*write in the error file if an element is not correct then free the map before exiting*/
void	error_map_elements(t_game *map)
{
	write(2, "Elements not valid\n", 19);
	ft_free_array(map->array, map->y);
	ft_free_array(map->copy, map->y);
	exit(EXIT_FAILURE);
}
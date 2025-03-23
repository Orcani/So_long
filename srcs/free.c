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

/*Free the map*/
int	ft_free_array(char **ret, int i)
{
	while (i > 0)
		free(ret[--i]);
	free(ret);
	return (0);
}

/*Free TOUT when the player exit*/
void	ft_exit_free(t_game *map)
{
	if (map->array)
		free(map->array);
	if (map->copy)
		free(map->copy);
	if (map->file)
		free(map->file);
	if (map->line)
		free(map->file);
	exit(EXIT_FAILURE);
}
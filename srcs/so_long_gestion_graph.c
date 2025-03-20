/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_gestion_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:38:15 by desambou          #+#    #+#             */
/*   Updated: 2025/02/03 16:10:41 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// create a window using MinilibX
//  - create the required structure to store all the necessary information
// Load all the required sprites (images) for your game and store them into memory
// Create the different hooks
//  - key_handler
//  - mouse_handler (if necessary)
//  - close_handler, this is a hook on the red cross that closes the program correctly
//  - loop_hook (-> you game loop)

#include "mlx.h"


t_sprite *create_sprite(void *mlx, const char *path, int *width, int *height) {
    t_sprite *sprite = malloc(sizeof(t_sprite));
    sprite->sprite = mlx_xpm_file_to_image(mlx, path, width, height);
    sprite->width = *width;
    sprite->height = *height;
    return sprite;
}

t_entity *create_entity(char type, int x, int y, t_sprite *sprite) {
    t_entity *new_entity = malloc(sizeof(t_entity));
    if (!new_entity) {
        return NULL;
    }
    new_entity->type = type;
    new_entity->x = x;
    new_entity->y = y;
    new_entity->sprite = sprite;
    new_entity->next = NULL;
    return new_entity;
}

void add_entity_to_game(t_game *game, t_entity *entity) {
    if (!game->entities) {
        game->entities = entity;  // First entity, set it as head of the list
    } else {
        t_entity *last = game->entities;
        while (last->next) {
            last = last->next;  // Traverse to the last entity in the list
        }
        last->next = entity;  // Add new entity at the end
    }
}



int key_handler(int keycode, t_game *game)
{
    if (keycode == 53 || keycode == 17)
	{
		if (game->player_sprite)
			mlx_destroy_image(game->mlx, game->player_sprite);
		if (game->floor_sprite)
			mlx_destroy_image(game->mlx, game->floor_sprite);
		if (game->wall_sprite)
			mlx_destroy_image(game->mlx, game->wall_sprite);
		if (game->enemies_sprite)
			mlx_destroy_image(game->mlx, game->enemies_sprite);
		if (game->exit_sprite)
			mlx_destroy_image(game->mlx, game->exit_sprite);
		if (game->collectible_sprite)
			mlx_destroy_image(game->mlx, game->collectible_sprite);
		if (game->window)
        	mlx_destroy_window(game->mlx,game->window);

		exit (0);
	}
    else if (keycode == 0 || keycode == 123)
        game->player_x -= 1;
    else if (keycode == 2 || keycode == 124)
        game->player_x += 1;
    else if (keycode == 1 || keycode == 125)
        game->player_y += 1;
    else if (keycode == 13 || keycode == 126)
	{
		game->player_y -= 1;
	}
        
	mlx_clear_window(game->mlx,game->window);
	mlx_put_image_to_window(game->mlx,game->window,game->player_sprite,
				game->player_x,game->player_y);
	return (0);
}
int game_loop(t_game *game)
{
	mlx_clear_window(game->mlx,game->window);
	mlx_put_image_to_window(game->mlx,game->window,game->player_sprite,
				game->player_x,game->player_y);
	return(0);
}

void render_map(t_game *game)
{
	int x;
	int y;
	x = 0;
	while (x < count_lines;)
}


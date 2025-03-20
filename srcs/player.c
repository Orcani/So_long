/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:41:40 by desambou          #+#    #+#             */
/*   Updated: 2025/02/21 16:48:35 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

t_entity *create_entity(char type, int x, int y, void *sprite)
{
    t_entity *entity = malloc(sizeof(t_entity));
    if (!entity)
    {
        perror("Error allocating memory for entity");
        return NULL;
    }
    entity->type = type;
    entity->x = x;
    entity->y = y;
    entity->sprite = sprite;  // Sprite associated with the entity
    return entity;
}

// This function assumes that the game has an array of entities in `game->entities`
// Adjust as per your design (e.g., linked list, array, etc.)
void add_entity_to_game(t_game_state *game, t_entity *entity)
{
    // Assume you have a dynamic list of entities to hold all entities in the game
    game->num_entities++;
    game->entities = realloc(game->entities, game->num_entities * sizeof(t_entity *));
    game->entities[game->num_entities - 1] = entity;
}

void load_sprites(t_game_state *game)
{
    // Load player sprite
    game->player_sprite = mlx_xpm_file_to_image(game->mlx, "./so_long_sprite/Player.xpm", &game->player_width, &game->player_height);
    
    // Load floor sprite
    game->floor_sprite = mlx_xpm_file_to_image(game->mlx, "./so_long_sprite/Water.xpm", &game->width, &game->height);
    
    // Load wall sprite
    game->wall_sprite = mlx_xpm_file_to_image(game->mlx, "./so_long_sprite/Walls.xpm", &game->width, &game->height);
    
    // Load enemy sprite
    game->enemies_sprite = mlx_xpm_file_to_image(game->mlx, "./so_long_sprite/Enemies.xpm", &game->width, &game->height);
    
    // Load exit sprite
    game->exit_sprite = mlx_xpm_file_to_image(game->mlx, "./so_long_sprite/Exit.xpm", &game->width, &game->height);
    
    // Load collectible sprite
    game->collectible_sprite = mlx_xpm_file_to_image(game->mlx, "./so_long_sprite/Collectible.xpm", &game->width, &game->height);
}

void add_entities_to_game(t_game_state *game)
{
    // Create and add player
    t_entity *player = create_entity('P', game->player_x, game->player_y, game->player_sprite);
    add_entity_to_game(game, player);

    // Create and add walls
    t_entity *wall = create_entity('1', wall_x, wall_y, game->wall_sprite);
    add_entity_to_game(game, wall);

    // Create and add enemies
    t_entity *enemy = create_entity('X', enemies_x, enemies_y, game->enemies_sprite);
    add_entity_to_game(game, enemy);

    // Create and add exit
    t_entity *exit = create_entity('E', game->map->exit_x, game->map->exit_y, game->exit_sprite);
    add_entity_to_game(game, exit);

    // Create and add collectibles
    t_entity *collectible = create_entity('C', collectible_x, collectible_y, game->collectible_sprite);
    add_entity_to_game(game, collectible);
}

void render_game(t_game_state *game)
{
    // Render all entities
    for (int i = 0; i < game->num_entities; i++)
    {
        t_entity *entity = game->entities[i];
        mlx_put_image_to_window(game->mlx, game->window, entity->sprite, entity->x, entity->y);
    }
}

void destroy_sprites(t_game_state *game)
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
}

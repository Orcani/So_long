/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:13:30 by desambou          #+#    #+#             */
/*   Updated: 2025/02/21 16:48:51 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"


// int main(void)
// {
// 	t_game game;
// 	int width = 64;
// 	int height = 64;

// 	game.mlx = mlx_init();
// 	if (game.mlx == NULL)
// 		return (1);
// 	game.window = mlx_new_window(game.mlx, 800, 600, "So Long Orca Game"); 
// 	if (game.window == NULL)
// 		return (1);
// 	game.player_sprite = mlx_xpm_file_to_image(game.mlx,"./so_long_sprite/Down_Orca.xpm", &width, &height);
// 	if (!game.player_sprite)
// 	{
// 		ft_printf("Error loading player sprite!\n");
// 		return (1);
// 	}
// 	t_entity *player = create_entity('P', player_x, player_y, player_sprite);
// 	add_entity_to_game(game, player);
// 	game.floor_sprite = mlx_xpm_file_to_image(game.mlx,"./so_long_sprite/Water.xpm", &width, &height);
	
// 	game.wall_sprite = mlx_xpm_file_to_image(game.mlx,"./so_long_sprite/Walls.xpm", &width, &height);
// 	t_entity *player = create_entity('1', wall_x, wall_y, wall_sprite);
// 	add_entity_to_game(game, wall);
// 	game.enemies_sprite = mlx_xpm_file_to_image(game.mlx,"./so_long_sprite/Enemies.xpm", &width, &height);
// 	t_entity *player = create_entity('', enemies_x, enemies_y, enemies_sprite);
// 	add_entity_to_game(game, enemies);
// 	game.exit_sprite = mlx_xpm_file_to_image(game.mlx,"./so_long_sprite/Exit.xpm", &width, &height);
// 	game.collectible_sprite = mlx_xpm_file_to_image(game.mlx,"./so_long_sprite/Collectible.xpm", &width, &height);

// 	mlx_loop_hook(game.mlx,game_loop, &game);
// 	mlx_key_hook(game.window,key_handler, &game);
// 	mlx_loop(game.mlx);
	
// 	if( game.player_sprite)
// 		mlx_destroy_image(game.mlx, game.player_sprite);
// 	if( game.floor_sprite)
// 		mlx_destroy_image(game.mlx, game.floor_sprite);
// 	if( game.wall_sprite)
// 		mlx_destroy_image(game.mlx, game.wall_sprite);
// 	if( game.enemies_sprite)
// 		mlx_destroy_image(game.mlx, game.enemies_sprite);
// 	if( game.exit_sprite)
// 		mlx_destroy_image(game.mlx, game.exit_sprite);
// 	if( game.collectible_sprite)
// 		mlx_destroy_image(game.mlx, game.collectible_sprite);
// 	return (0);
// }

// int initialize_game(t_game *game)
// {
//     // Initialize the map
//     game->map = malloc(sizeof(t_map));
//     if (!game->map) {
//         ft_printf("Error allocating map\n");
//         return 1;
//     }

//     // Initialize the player
//     game->player = malloc(sizeof(t_player));
//     if (!game->player) {
//         ft_printf("Error allocating player\n");
//         return 2;
//     }

//     // Load map from file (assuming a function `load_map`)
//     if (load_map(game->map, "map.ber") != 0) {
//         ft_printf("Error loading map\n");
//         return 3;
//     }

//     // Initialize directions (already set in array, but you can also set here for clarity)
//     int directions[4][2] = {
//         {1, 0},    // South
//         {-1, 0},   // North
//         {0, 1},    // East
//         {0, -1}    // West
//     };

//     // Set directions in game structure
//     memcpy(game->directions, directions, sizeof(directions));

//     // Initialize sprites
//     game->floor_sprite = malloc(sizeof(t_sprite));
//     game->wall_sprite = malloc(sizeof(t_sprite));
//     game->exit_sprite = malloc(sizeof(t_sprite));
//     game->collectible_sprite = malloc(sizeof(t_sprite));
//     game->enemy_sprite = malloc(sizeof(t_sprite));

//     if (!game->floor_sprite || !game->wall_sprite || !game->exit_sprite || !game->collectible_sprite || !game->enemy_sprite) {
//         ft_printf("Error initializing sprites\n");
//         return 4;
//     }

//     // Load sprites (example)
//     game->floor_sprite->sprite = load_image("floor.png");
//     game->wall_sprite->sprite = load_image("wall.png");
//     game->exit_sprite->sprite = load_image("exit.png");
//     game->collectible_sprite->sprite = load_image("collectible.png");
//     game->enemy_sprite->sprite = load_image("enemy.png");

//     // Set sprite sizes (if needed)
//     game->floor_sprite->width = 32; // Example width
//     game->floor_sprite->height = 32; // Example height
//     // Similarly set sizes for other sprites...

//     return 0; // Success
// }

// int main(void)
// {
//     t_game game;

//     // Initialize game structures
//     game.map = malloc(sizeof(t_map));
//     game.player = malloc(sizeof(t_player));

//     // Load the map (assuming this function is defined elsewhere)
//     if (allocate_and_copy_map(game.map) != 0) {
//         ft_printf("Error loading map\n");
//         return 1;
//     }

//     // Validate the map content (assuming this function is defined elsewhere)
//     if (validate_map(game.map, &game.exit_game, &game.collectible, &game.enemies, &game.player_x, &game.player_y) != 0) {
//         ft_printf("Error: Map is invalid.\n");
//         return 2;
//     }

//     // Check the filling and perform flood fill from the player's position
//     if (check_filling(game.map) != 1) {
//         ft_printf("Error: Map is incorrectly filled.\n");
//         return 3;
//     }

//     // Start flood fill from player's position to ensure connectivity
//     floodfill(game.map, game.player->x, game.player->y, &game.exit_game, &game.collectible, &game.enemies);

//     // Additional game logic and rendering here...

//     return 0;
// }


int main(int argc, char *argv[])
{
    t_game_state game;
    
    // Initialize the game state
    game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "So Long");

    // Load the sprites
    load_sprites(&game);

    // Add entities to the game
    add_entities_to_game(&game);

    // Set up the game loop and key handler
    mlx_loop_hook(game.mlx, game_loop, &game);
    mlx_key_hook(game.window, key_handler, &game);
    mlx_loop(game.mlx);

    // Destroy the sprites when done
    destroy_sprites(&game);

    return 0;
}


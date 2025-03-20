/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:03:35 by desambou          #+#    #+#             */
/*   Updated: 2024/12/15 12:59:28 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// // Structure for a sprite (for player, walls, floors, exit, enemies, collectibles)
// typedef struct s_sprite {
//     void *sprite;    // Pointer to the sprite (image)
//     int width;       // Width of the sprite
//     int height;      // Height of the sprite
// } t_sprite;

// typedef struct s_map {
//     char **grid;      // 2D array representing the map grid (characters like '1', '0', 'P', 'E', 'C', etc.)
//     int width;        // Width of the map (number of columns)
//     int height;       // Height of the map (number of rows)
//     int exit_x;       // X position of the exit
//     int exit_y;       // Y position of the exit
// } t_map;

// typedef struct s_entity {
//     char type;          // Type of the entity ('P' for player, '1' for wall, etc.)
//     int x;              // X position of the entity
//     int y;              // Y position of the entity
//     void *sprite;       // Pointer to the sprite image of the entity
// } t_entity;


// // Structure for a single collectible item
// typedef struct s_collectible {
//     int x;            // X position of the collectible
//     int y;            // Y position of the collectible
//     int collected;   // Boolean to indicate if the collectible has been collected
// } t_collectible;

// // Structure for a single enemy
// typedef struct s_enemy {
//     int x;            // X position of the enemy
//     int y;            // Y position of the enemy
// } t_enemy;

// // Structure to hold the player position and other info
// typedef struct s_player {
//     int x;            // Player's current X position
//     int y;            // Player's current Y position
//     t_sprite *sprite; // Pointer to the player sprite
// } t_player;

// typedef struct s_data {
//     void *addr;             // Address of the image data
//     int line_length;        // Line length (in bytes)
//     int bits_per_pixel;     // Bits per pixel
// } t_data;

// typedef struct s_game_state {
//     t_map *map;                // Map structure
//     t_player *player;          // Pointer to the player structure
//     t_sprite *floor_sprite;    // Sprite for the floor
//     t_sprite *wall_sprite;     // Sprite for the wall
//     t_sprite *exit_sprite;     // Sprite for the exit
//     t_sprite *collectible_sprite; // Sprite for the collectible
//     t_sprite *enemy_sprite;    // Sprite for the enemy

//     t_collectible *collectibles;  // Array of collectibles
//     int num_collectibles;         // Total number of collectibles
//     int remaining_collectibles;   // Number of remaining collectibles
//     t_enemy *enemies;             // Array of enemies
//     int num_enemies;              // Total number of enemies
//     int exit_reached;            // Flag to check if the player has reached the exit

//     t_data *image_data;         // Pointer to image data (drawing buffer)
//     int player_x;               // Current X position of the player (may change during the game)
//     int player_y;               // Current Y position of the player (may change during the game)
// } t_game_state;


// void validate_map_boundaries(t_map *map);
// void check_wall_edges(t_map *map);
// void wall_check(t_map *map);
// int player_count(t_game_state *game);
// int exit_count(t_game_state *game);
// int enemies_count(t_game_state *game);
// int collectible_count(t_game_state *game);
// int check_filling(t_game_state *game);
// int check_and_mark(t_game_state *game, int player_x, int player_y, int *exit_game, int *collectible, int *enemies);
// int floodfill(t_game_state *game, int player_x, int player_y, int exit_game, int collectible, int enemies);



// int	ft_printf(const char *format, ...);
// int	format_specifier(const char *format, va_list args);
// int	print_c(char c);
// int	print_hex(uintptr_t n, int uppercase);
// int	print_nbr(int n);
// int	print_p(void *p);
// int	print_str(char *s);
// int	print_u(unsigned int n);
// char	*get_next_line(int fd);
// char	*ft_strdup(const char *s);
// size_t	ft_strlen(const char *s);
// char	*ft_strchr(const char *s, int c);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// int allocate_and_copy_map(t_game *game);
// int error_check(t_game *game);
// int key_handler(int keycode, t_game *game);
// int game_loop(t_game *game);
// int validate_map(t_game *game, int *exit_game, int *collectible, int *enemies, int *player_x, int *player_y);
// int open_and_read_map(char *filename, int *count_lines);

#endif
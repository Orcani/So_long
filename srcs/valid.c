/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:41:43 by desambou          #+#    #+#             */
/*   Updated: 2025/02/21 16:42:02 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void validate_map_boundaries(t_map *map)
{
    int i;
    int first_line_length;

    // Check if map is NULL or empty
    if (map == NULL || map->grid == NULL || map->height == 0)
    {
        ft_printf("Error: Invalid map.\n");
        exit(0);
    }

    // Get the length of the first row
    first_line_length = ft_strlen(map->grid[0]) - 1;

    // Check that all rows have the same length
    for (i = 1; i < map->height; i++)
    {
        int current_line_length = ft_strlen(map->grid[i]) - 1;

        if (first_line_length != current_line_length)
        {
            ft_printf("Error: Map is not rectangular.\n");
            exit(2);
        }
    }
}

void check_wall_edges(t_map *map)
{
    int i;

    // Check the first and last columns for walls (1's)
    for (i = 0; i < map->height; i++)
    {
        if (map->grid[i][0] != '1' || map->grid[i][ft_strlen(map->grid[i]) - 2] != '1') // -2 to ignore the newline character
        {
            ft_printf("Error: Map is not surrounded by walls.\n");
            exit(0);
        }
    }

    // Check the first and last rows for walls (1's)
    for (i = 0; i < ft_strlen(map->grid[0]) - 1; i++)  // -1 to ignore the newline character
    {
        if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
        {
            ft_printf("Error: Map is not surrounded by walls.\n");
            exit(0);
        }
    }
}
void wall_check(t_map *map)
{
    validate_map_boundaries(map);  // Check for rectangular map and consistent row lengths
    check_wall_edges(map);         // Check if map is surrounded by walls (1's)
}

int player_count(t_game_state *game)
{
    int x = 0, y = 0;
    int player = 0;
    
    // Loop through the map to find the player's position
    while (x < game->map->height)
    {
        y = 0;  // Reset y to 0 for each row
        while (game->map->grid[x][y] != '\0')  // Loop until the end of the row (avoid '\n' if present)
        {
            if (game->map->grid[x][y] == 'P')  // If we find the player
            {
                player++;  
                game->player->x = x;  // Update the player's x position
                game->player->y = y;  // Update the player's y position
            }
            y++;
        }
        x++;
    }
    // Ensure that there is exactly one player
    if (player != 1)
    {
        ft_printf("Error: Invalid number of players.\n");
        exit(1);
    }
    return 0;
}

int exit_count(t_game_state *game)
{
    int x = 0, y = 0;
    int ex_game = 0;

    // Loop through the map to find the exit
    while (x < game->map->height)
    {
        y = 0;  // Reset y to 0 for each row
        while (game->map->grid[x][y] != '\0')  // Loop until the end of the row
        {
            if (game->map->grid[x][y] == 'E')  // If we find the exit
            {
                ex_game++; 
                game->map->exit_x = x;  // Update the exit's x position in the map structure
                game->map->exit_y = y;  // Update the exit's y position in the map structure
            }
            y++;
        }
        x++;
    }
    // Ensure that there is exactly one exit
    if (ex_game != 1)
    {
        ft_printf("Error: Invalid number of exits.\n");
        exit(1);
    }
    return 1;
}

//--------------------------Limite des 25 lignes------------------------------------

int enemies_count(t_game_state *game)
{
    int x = 0, y = 0;
    int enemy_count = 0;

    // Loop through the map to find enemies ('X')
    while (x < game->map->height)
    {
        y = 0;
        while (game->map->grid[x][y] != '\0')
        {
            if (game->map->grid[x][y] == 'X')  // If we find an enemy
            {
                // Store the enemy's position in the enemies array
                game->enemies[enemy_count].x = x;
                game->enemies[enemy_count].y = y;
                enemy_count++;  // Increment the number of enemies
            }
            y++;
        }
        x++;
    }

    // Update the total number of enemies in the game state
    game->num_enemies = enemy_count;

    return 1;
}

int collectible_count(t_game_state *game)
{
    int x = 0, y = 0;
    int collect_count = 0;

    // Loop through the map to find collectibles ('C')
    while (x < game->map->height)
    {
        y = 0;
        while (game->map->grid[x][y] != '\0')
        {
            if (game->map->grid[x][y] == 'C')  // If we find a collectible
            {
                // Store the collectible's position in the collectibles array
                game->collectibles[collect_count].x = x;
                game->collectibles[collect_count].y = y;
                game->collectibles[collect_count].collected = 0;  // Mark it as not collected
                collect_count++;  // Increment the number of collectibles
            }
            y++;
        }
        x++;
    }
    // Update the total number of collectibles in the game state
    game->num_collectibles = collect_count;
    game->remaining_collectibles = collect_count;
    return 1;
}

int check_filling(t_game_state *game)
{
    int x = 0, y = 0;
    int V_point = 0;

    // Loop through the map to validate the characters
    while (x < game->map->height)
    {
        y = 0;
        while (game->map->grid[x][y] != '\0')  // Loop through each character in the row
        {
            if (game->map->grid[x][y] == 'V' || game->map->grid[x][y] == '1')  // Valid positions
            {
                V_point++;
            }
            else if (game->map->grid[x][y] == 'E' || game->map->grid[x][y] == 'X' ||
                     game->map->grid[x][y] == '0' || game->map->grid[x][y] == 'C') 
            {
                exit(0);  // Exit if invalid character is found
            }
            y++;
        }
        x++;
    }
    return 1;  // Return 1 if check is successful
}

int check_and_mark(t_game_state *game, int player_x, int player_y, int *exit_game, int *collectible, int *enemies)
{
    if (player_x < 0 || player_y < 0 || player_x >= game->map->height ||
        player_y >= game->map->width || game->map->grid[player_x][player_y] == '1' || 
        game->map->grid[player_x][player_y] == 'V') 
    {
        return 0;
    }
    game->map->grid[player_x][player_y] = 'V';
    if (game->map->grid[player_x][player_y] == 'E')
        (*exit_game)--;
    if (game->map->grid[player_x][player_y] == 'C')
        (*collectible)--;
    if (game->map->grid[player_x][player_y] == 'X')
        (*enemies)--;
    return 1;
}

int floodfill(t_game_state *game, int player_x, int player_y, int exit_game, int collectible, int enemies)
{
    int new_x, new_y;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int i = 0;

    if (!check_and_mark(game, player_x, player_y, &exit_game, &collectible, &enemies))
    {
        return 4; 
    }
    while (i < 4)
    {
        new_x = player_x + directions[i][0];
        new_y = player_y + directions[i][1];
        floodfill(game, new_x, new_y, exit_game, collectible, enemies); 
        i++;
    }
    return 3;  
}

// void ft_put_pixel(t_game_state *game, int x, int y, int color)
// {
//     char *pxl;

//     // Ensure the pixel is within the valid window dimensions
//     if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
//     {
//         // Access the image data from the game state
//         pxl = game->image_data->addr + (y * game->image_data->line_length + x * (game->image_data->bits_per_pixel / 8));

//         // Set the color at the specified pixel location
//         *(unsigned int *)pxl = color;
//     }
// }


// t_data *image_data = malloc(sizeof(t_data));
// image_data->addr = /* allocate memory or get the image address */;
// image_data->line_length = /* calculate line length */;
// image_data->bits_per_pixel = /* set the bits per pixel */;
// game->image_data = image_data;





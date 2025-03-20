/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:59:11 by desambou          #+#    #+#             */
/*   Updated: 2025/02/10 12:30:27 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define	WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080


int directions[4][2] = {
    {1, 0},  // south
    {-1, 0}, // north
    {0, 1},  // east
    {0, -1}  // west
};

int wall_check (char **map, int count_lines)
{
    int first_line;
    int i;
    int current_line;
    if (map == NULL || count_lines == 0)
    {
        ft_printf("Error.\n");
        return 0; 
    }
    sleep(1);
    if (map[0] == NULL)
    {
        ft_printf("Error.\n");
        exit(0);
    }
    first_line = ft_strlen(map[0]) - 1;
    i = 1;
    
    while ( i < count_lines)
    {
        if (map[i] == NULL)
        {
            ft_printf("Error\n", i);
            exit (0);
        }
        current_line = ft_strlen(map[i]) - 1;

        if (first_line != current_line)
        {
            ft_printf("Error.\n");
            exit (2);
        }
       
        i++;
    }
    i = 0;
	while (i < count_lines)
	{
	 if (map[i][0] != '1' || map[i][current_line - 1] != '1')
        exit (0);

    i++;
	}
    i = 0;
    while (map[0][i] != '\n')
    {
        if (map[0][i] != '1' ) 
			exit(0);
        i++;
    }
    i = 0;
    while (map[count_lines - 1][i] != '\n')
    {
        if (map[count_lines - 1][i] != '1' )
			exit (0);
        i++;
    }
    return 1;
}


int player_count(char **map, int count_lines, int *player_x, int *player_y)
{
  int x = 0, y = 0;
    int player = 0;
    while (x < count_lines)
    {
        y = 0;  // Réinitialiser i à 0 pour chaque ligne
        while (map[x][y] != '\0')  // Vérifier jusqu'à la fin de la ligne, pas '\n' qui peut être absent
        {
            if (map[x][y] == 'P')  // Vérifier si c'est un exit
               {
                player++;  
                *player_x = x;  // Mettre à jour la position du joueur
                *player_y = y;
               }
            y++;
        }
        x++;
    }
    if (player != 1)
    {
        exit (1);
    }
   return (0);
}
int exit_count(char **map, int count_lines, int *exit_game)
{
    int i;
    int j;
    int ex_game;

    j = 0;
    ex_game = 0;
    while (j < count_lines)
    {
        i = 0;  
        while (map[j][i] != '\0')  
        {
            if (map[j][i] == 'E') 
            {
                ex_game++; 
                *exit_game = ex_game;  
            }
            i++;
        }
        j++;
    }
    if (ex_game != 1)
    {
        exit (1);
    }
    return (1);
}
int enemies_count(char **map, int count_lines, int *enemies)
{
    int i;
    int j;
    int enem;

    j = 0;
    enem = 0;
    while (j < count_lines)
    {
        i = 0;  
        while (map[j][i] != '\0') 
        {
            if (map[j][i] == 'X')  
               {
                 enem++;
                 *enemies = enem;
               }    
            i++;
        }
        j++;
    }
    return (1);
}
int collectible_count(char **map, int count_lines, int *collectible)
{
    int i;
    int j;
    int collect;

    j = 0;
    collect = 0;
    while (j < count_lines)
    {
        i = 0;  
        while (map[j][i] != '\0')  
        {
            if (map[j][i] == 'C') 
               {
                 collect++;
                 *collectible = collect;
               }    
            i++;
        }
        j++;
    }
    return (1);
}
int check_filling(char **map, int count_lines)
{
    int i;
    int j;
    int V_point;

    j = 0;
    V_point = 0;
    while (j < count_lines)
    {
        i = 0; 
        while (map[j][i] != '\0')  
        {
            if (map[j][i] == 'V' || map[j][i] == '1')  
               {
                 V_point++;
               }
            else if (map[j][i] == 'E' || map[j][i] == 'X' || map[j][i] == '0' || map[j][i] == 'C') 
                exit (0) ;
            i++;
        }
        j++;
    }
    return (1);
}

int floodfill(char **map, int player_x, int player_y, int count_lines, int first_line, int *exit_game, int *collectible, int *enemies)
{
	int new_x;
	int new_y;
	int i;
    i = 0;
	if (player_x < 0 || player_y < 0 || player_x >= count_lines|| player_y >= first_line || map[player_x][player_y] == '1' || map[player_x][player_y] == 'V')
        return (4);
	map[player_x][player_y] = 'V';
    if (map[player_x][player_y] == 'E')
        (*exit_game)--;
    if (map[player_x][player_y] == 'C')
        (*collectible)--;
    if (map[player_x][player_y] == 'X')
    {
        (*enemies)--;
    }
	while (i < 4)
	{
		new_x = player_x + directions[i][0];
		new_y = player_y + directions[i][1];
		floodfill(map, new_x, new_y, count_lines, first_line, exit_game, collectible, enemies);
		i++;
	}
    
    return (3);
}

void ft_put_pixel(t_data *data, int x, int y, int color)
{
    char *pxl;

    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
    {
        pxl = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)pxl = color;
    }
}

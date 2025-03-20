/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_verification.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:23:40 by desambou          #+#    #+#             */
/*   Updated: 2025/02/21 14:00:24 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int open_and_read_map(char *filename, int *count_lines)
{
    int fd;
    char *line;

    *count_lines = 0;
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        ft_printf("Error\n");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL) {
        (*count_lines)++;
        free(line);
    }
    if (*count_lines == 0) {
        ft_printf("Error.\n");
        close(fd);
        return (1);
    }
    close(fd);
    return 0;
}
int allocate_and_copy_map(int count_lines, char ***map)
{
    int fd;
    char *line;
    int i;

    *map = malloc(count_lines * sizeof(char *));
    if (*map == NULL) {
        ft_printf("Error\n");
        return (2);
    }
    fd = open("map.ber", O_RDONLY);
    lseek(fd, 0, SEEK_SET);
    i = 0;
    while ((line = get_next_line(fd)) != NULL) {
        (*map)[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
        if ((*map)[i] == NULL) {
            ft_printf("Error\n");
            close(fd);
            return (3);
        }
        ft_strlcpy((*map)[i], line, ft_strlen(line) + 1);
        free(line);
        i++;
    }
    close(fd);
    return 0;
}

int validate_map(char **map, int count_lines, int *exit_game, int *collectible, int *enemies, int *player_x, int *player_y)
{
    // int first_line = ft_strlen(map[0]) - 1;

    wall_check(map, count_lines);
    exit_count(map, count_lines, exit_game);
    collectible_count(map, count_lines, collectible);
    enemies_count(map, count_lines, enemies);
    player_count(map, count_lines, player_x, player_y);

    if (*collectible < 0 || *enemies < 0 || *exit_game < 0) {
        ft_printf("Error\n");
        return 1;
    }
    
    return 0;
}
// voir si exit au lieu de return.
int error_check(void)
{
    int count_lines;
    char **map;
    int player_x = -1, player_y = -1;
    int exit_game = 0, collectible = 0, enemies = 0;

    if (open_and_read_map("map.ber", &count_lines) != 0) {
        return 1;
    }

    if (allocate_and_copy_map(count_lines, &map) != 0) {
        return 2;
    }

    if (validate_map(map, count_lines, &exit_game, &collectible, &enemies, &player_x, &player_y) != 0) {
        return 1;
    }

    floodfill(map, player_x, player_y, count_lines, ft_strlen(map[0]) - 1, &exit_game, &collectible, &enemies);

    return 0;
}



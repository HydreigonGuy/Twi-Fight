/*
** Twi-Fight
** 
** File description:
** fill_game_info
*/

#include "game.h"
#include <stdlib.h>

playing_t *fill_game_info(void)
{
    playing_t *game_info = NULL;

    game_info = malloc(sizeof(playing_t));
    if (!game_info)
        return (NULL);
    game_info->tower_selected = 0;
    game_info->tower = NULL;
    game_info->enemy = NULL;
    game_info->spawn_var = 1;
    return (game_info);
}
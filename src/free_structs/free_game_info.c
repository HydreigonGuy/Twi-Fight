/*
** Twi-Fight
** 
** File description:
** free_game_info
*/

#include "game.h"
#include <stdlib.h>

void free_game_info(playing_t *game_info)
{
    free_all_towers(game_info->tower);
    free_all_enemies(game_info->enemy);
    free_all_attacks(game_info->atk);
    free_all_lives(game_info->life);
    free(game_info->wolf_btn);
    free(game_info);
}
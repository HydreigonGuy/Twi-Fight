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
    tower_t *twr = game_info->tower;

    while (twr && twr->next) {
        for (; twr && twr->next && twr->next->next; twr = twr->next);
        free_sprite(twr->next->spr);
        free(twr->next);
        twr->next = NULL;
        twr = game_info->tower;
    }
    if (twr) {
        free_sprite(twr->spr);
        free(twr);
    }
    free(game_info);
}
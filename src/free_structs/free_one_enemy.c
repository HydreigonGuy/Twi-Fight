/*
** Twi-Fight
** 
** File description:
** free_one_enemy
*/

#include "game.h"
#include <stdlib.h>

void free_one_enemy(playing_t *game_info, enemy_t *enm)
{
    enemy_t *hold = game_info->enemy;

    if (hold == enm) {
        game_info->enemy = hold->next;
        free_sprite(hold->spr);
        free(hold);
        return;
    }
    for (; hold && hold->next; hold = hold->next) {
        if (hold->next == enm) {
            hold->next = hold->next->next;
            free_sprite(enm->spr);
            free(enm);
            return;
        }
    }
}
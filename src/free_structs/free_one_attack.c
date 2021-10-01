/*
** Twi-Fight
** 
** File description:
** free_one_attack
*/

#include "game.h"
#include <stdlib.h>

void free_one_attack(playing_t *game_info, attack_t *atk)
{
    attack_t *hold = game_info->atk;

    if (hold == atk) {
        game_info->atk = hold->next;
        free_sprite(hold->spr);
        free(hold);
        return;
    }
    for (; hold && hold->next; hold = hold->next) {
        if (hold->next == atk) {
            hold->next = hold->next->next;
            free_sprite(atk->spr);
            free(atk);
            return;
        }
    }
}
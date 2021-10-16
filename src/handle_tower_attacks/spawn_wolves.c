/*
** Twi-Fight
** 
** File description:
** spawn_wolves
*/

#include "game.h"

void spawn_wolves(playing_t *gi)
{
    attack_t *atk = gi->atk;

    if (!atk) {
        gi->atk = spawn_all_wolves();
    } else {
        for (; atk && atk->next; atk = atk->next);
        atk->next = spawn_all_wolves();
    }
}
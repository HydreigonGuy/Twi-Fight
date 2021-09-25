/*
** Twi-Fight
** 
** File description:
** spawn_enemies
*/

#include "game.h"

void spawn_enemies(playing_t *gi)
{
    if (gi->spawn_var > 0) {
        for (int i = 0; i < 5 * gi->spawn_var; i++)
            spawn_enemy(gi->spawn_var, i * ENEMY_SEPARATION * -1, &gi->enemy);
        gi->spawn_var = (gi->spawn_var + 1) * -1;
    }
}
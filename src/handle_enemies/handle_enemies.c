/*
** Twi-Fight
** 
** File description:
** handle_enemies
*/

#include "game.h"
#include <stdlib.h>

void handle_enemies(int clock, playing_t *game_info)
{
    enemy_t *enemys = game_info->enemy;
    enemy_t *hold = NULL;
    int check_first = 1;

    while (enemys && check_first) {
        check_first = 0;
        enemys->spr->crds.x += (enemys->spd * clock) / ENEMY_SPD_LIMITTER;
        sfSprite_setPosition(enemys->spr->spr, enemys->spr->crds);
        if (enemys->spr->crds.x > 900) {
            free_sprite(enemys->spr);
            hold = enemys->next;
            free(enemys);
            game_info->enemy = hold;
            enemys = game_info->enemy;
            check_first = 1;
        }
    }
    for (; enemys && enemys->next; enemys = enemys->next) {
        enemys->next->spr->crds.x += (enemys->next->spd * clock) / ENEMY_SPD_LIMITTER;
        sfSprite_setPosition(enemys->next->spr->spr, enemys->next->spr->crds);
        if (enemys->next->spr->crds.x > 900) {
            free_sprite(enemys->next->spr);
            hold = enemys->next->next;
            free(enemys->next);
            enemys->next = hold;
        }
    }
    spawn_enemies(game_info);
}
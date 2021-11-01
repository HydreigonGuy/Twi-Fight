/*
** Twi-Fight
** 
** File description:
** move_enemies
*/

#include "game.h"
#include <stdlib.h>

void handle_mooving_first_enemy(int clock, playing_t *game_info)
{
    enemy_t *enm = game_info->enemy;
    enemy_t *hold = NULL;
    int check_first = 1;

    while (enm && check_first) {
        check_first = 0;
        enm->spr->crds.x += (enm->spd * clock) / ENEMY_SPD_LIMITTER;
        sfSprite_setPosition(enm->spr->spr, enm->spr->crds);
        if (enm->spr->crds.x > 900) {
            free_sprite(enm->spr);
            hold = enm->next;
            free(enm);
            game_info->enemy = hold;
            enm = game_info->enemy;
            check_first = 1;
            free_one_life(&game_info->life);
        }
    }
}

void move_enemies(int clk, playing_t *game_info)
{
    enemy_t *enm = game_info->enemy;
    enemy_t *hold = NULL;

    handle_mooving_first_enemy(clk, game_info);
    enm = game_info->enemy;
    for (; enm && enm->next; enm = enm->next) {
        enm->next->spr->crds.x += (enm->next->spd * clk) / ENEMY_SPD_LIMITTER;
        sfSprite_setPosition(enm->next->spr->spr, enm->next->spr->crds);
        if (enm->next->spr->crds.x > 900) {
            free_sprite(enm->next->spr);
            hold = enm->next->next;
            free(enm->next);
            enm->next = hold;
            free_one_life(&game_info->life);
        }
    }
}
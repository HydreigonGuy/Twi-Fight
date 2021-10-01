/*
** Twi-Fight
** 
** File description:
** handle_atk_enemy_collision
*/

#include "game.h"

void check_if_atk_hit_enemy(playing_t *game_info, attack_t *atk)
{
    for (enemy_t *enm = game_info->enemy; enm; enm = enm->next)
        if (check_for_atk_colision(game_info, atk, enm))
            return;
}

void handle_atk_enemy_collision(playing_t *game_info)
{
    attack_t *hold = game_info->atk;
    attack_t *atk = game_info->atk;

    while (hold) {
        atk = hold;
        hold = hold->next;
        check_if_atk_hit_enemy(game_info, atk);
    }
}
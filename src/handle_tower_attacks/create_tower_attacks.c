/*
** Twi-Fight
** 
** File description:
** create_tower_attacks
*/

#include "game.h"

void create_tower_attacks(playing_t *game_info)
{
    tower_t *tower = game_info->tower;

    for (; tower; tower = tower->next) {
        if (tower->cooldown <= 0) {
            add_one_attack(&game_info->atk, tower);
            tower->cooldown = tower->max_cooldown;
        }
    }
}
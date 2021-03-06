/*
** Twi-Fight
** 
** File description:
** handle_tower_attacks
*/

#include "game.h"

void handle_tower_attacks(game_t *game, playing_t *game_info)
{
    int furthest_enemy_x = find_furthest_enemy_x(game_info->enemy);

    handle_atk_enemy_collision(game_info);
    handle_wolf_btn_press(game->mouse, game_info, game->clock->time_elapsed);
    for (attack_t *atk = game_info->atk; atk; atk = atk->next) {
        get_next_atk_crds(atk, game->clock->time_elapsed, furthest_enemy_x);
        sfSprite_setPosition(atk->spr->spr, atk->spr->crds);
    }
    if (!game_info->enemy && game_info->atk) {
        free_all_attacks(game_info->atk);
        game_info->atk = NULL;
        for (tower_t *tower = game_info->tower; tower; tower = tower->next)
            tower->cooldown = 0;
    }
    remove_excess_attacks(&game_info->atk);
    for (tower_t *tower = game_info->tower; tower; tower = tower->next)
        tower->cooldown -= game->clock->time_elapsed / TOWER_CD_LIMITTER;
    if (game_info->enemy && game_info->tower)
        create_tower_attacks(game_info);
    check_game_over(game, game_info->life);
}
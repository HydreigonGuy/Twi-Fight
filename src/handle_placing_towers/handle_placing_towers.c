/*
** Twi-Fight
** 
** File description:
** handle_placing_towers
*/

#include "game.h"

void handle_placing_towers(game_t *game, playing_t *game_info, button_t *btn)
{
    if (game->state >= 10 && game->state <= 13) {
        handle_selecting_tower(&game->state, game_info);
        mouse_reset(game->mouse);
    }
    if (game_info->tower_selected) {
        highlignt_selected_tower_btn(game_info->tower_selected, btn);
        if (game->mouse->r_x != -1 && check_if_can_place_tower(game->mouse)) {
            add_tower(game_info, game->mouse->r_x, game->mouse->r_y);
            mouse_reset(game->mouse);
        }
        if (game->mouse->r_x != -1)
            mouse_reset(game->mouse);
    }
}
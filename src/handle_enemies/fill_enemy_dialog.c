/*
** Twi-Fight
** 
** File description:
** fill_enemy_dialog
*/

#include "game.h"
#include "ad_lib.h"

void fill_enemy_dialog(playing_t *game_info)
{
    if (game_info->spawn_var == -1) {
        game_info->dialog[1] = fill_sprite(my_str_concat(IMAGE_PATH,
        "evil/vmp.png"), 0, 500);
        game_info->dialog[2] = fill_sprite(my_str_concat(IMAGE_PATH,
        "evil/vmp_txt.png"), 200, 600);
    }
}
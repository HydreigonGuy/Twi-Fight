/*
** Twi-Fight
** 
** File description:
** fill_game_info
*/

#include "game.h"
#include "ad_lib.h"
#include <stdlib.h>

playing_t *fill_game_info(void)
{
    playing_t *game_info = NULL;

    game_info = malloc(sizeof(playing_t));
    if (!game_info)
        return (NULL);
    game_info->tower_selected = 0;
    game_info->tower = NULL;
    game_info->enemy = NULL;
    game_info->atk = NULL;
    game_info->spawn_var = -1;
    game_info->wolf_btn = fill_wolf_btn();
    game_info->dialog = malloc(sizeof(sprite_t) * 3);
    game_info->life = fill_game_lives();
    if (!game_info->dialog || !game_info->wolf_btn)
        return (NULL);
    for (int i = 0; i < 3; game_info->dialog[i] = NULL, i++);
    game_info->dialog[0] = fill_sprite(my_str_concat(IMAGE_PATH,
        "evil/press_space_to_continue.png"), 200, 675);
    return (game_info);
}
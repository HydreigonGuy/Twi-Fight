/*
** Twi-Fight
** 
** File description:
** play_game
*/

#include "game.h"

void play_game(game_t *game)
{
    scene_t *scene = fill_play_game_scene();
    playing_t *game_info = fill_game_info();

    if (!scene || !game_info)
        game->state = -3;
    mouse_reset(game->mouse);
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        handle_events(game);
        mouse_check(scene->btn, game);
        handle_placing_towers(game, game_info, scene->btn);
        //handle_tower_attacks();
        display_play_game(game->window, scene, game_info);
    }
    free_scene(scene);
    free_game_info(game_info);
}
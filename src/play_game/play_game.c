/*
** Twi-Fight
** 
** File description:
** play_game
*/

#include "game.h"
#include <stdlib.h>

void play_game(game_t *game)
{
    scene_t *scene = fill_play_game_scene();
    playing_t *game_info = fill_game_info();

    if (!scene || !game_info)
        game->state = -3;
    mouse_reset(game->mouse);
    srand(sfClock_getElapsedTime(game->clock->clock).microseconds % 10000);
    reset_game_time(game->clock);
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        update_clock(game->clock);
        handle_ingame_events(handle_events(game), game_info);
        mouse_check(scene->btn, game);
        handle_placing_towers(game, game_info, scene->btn);
        handle_tower_attacks(game, game_info);
        handle_enemies(game->clock->time_elapsed, game_info);
        display_play_game(game->window, game->clock, scene, game_info);
    }
    free_scene(scene);
    free_game_info(game_info);
}
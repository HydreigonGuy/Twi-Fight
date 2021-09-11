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

    if (!scene)
        game->state = -3;
    mouse_reset(game->mouse);
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        handle_events(game);
        mouse_check(scene->btn, game);
        display_play_game(game->window, scene);
    }
    free_scene(scene);
}
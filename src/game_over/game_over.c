/*
** Twi-Fight
** 
** File description:
** game_over
*/

#include "game.h"

void game_over(game_t *game)
{
    scene_t *scene = fill_game_over_scene();

    if (!scene)
        game->state = -3;
    mouse_reset(game->mouse);
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        handle_events(game);
        display_scene(game->window, scene);
    }
    free_scene(scene);
}
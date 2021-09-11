/*
** Twi-Fight
** 
** File description:
** start_menu
*/

#include "game.h"

void start_menu(game_t *game)
{
    scene_t *scene = fill_start_menu_scene();

    if (!scene)
        game->state = -3;
    mouse_reset(game->mouse);
    while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
        handle_events(game);
        mouse_check(scene->btn, game);
        display_start_menu(game->window, scene);
    }
    free_scene(scene);
    change_start_menu_game_state(game);
}
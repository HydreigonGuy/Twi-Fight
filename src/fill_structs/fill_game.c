/*
** Twi-Fight
** 
** File description:
** fill_game
*/

#include "game.h"
#include <stdlib.h>

game_t *fill_game(void)
{
    game_t *game = NULL;
    sfVideoMode mode = {1200, 700, 32};

    game = malloc(sizeof(game_t));
    if (!game)
        return (NULL);
    game->music = NULL;
    game->window = sfRenderWindow_create(mode,
        WINDOW_NAME, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, FRAME_RATE);
    game->clock = fill_game_time();
    game->state = GAME_STATE_START_MENU;
    game->mouse = fill_mouse();
    return (game);
}
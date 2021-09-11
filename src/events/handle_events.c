/*
** Twi-Fight
** 
** File description:
** handle_events
*/

#include "game.h"

void handle_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            game->state = GAME_STATE_EXIT;
        game->mouse->x = event.mouseMove.x;
        game->mouse->y = event.mouseMove.y;
        game->mouse->p_x = event.mouseButton.x;
        game->mouse->p_y = event.mouseButton.y;
        if (event.type == sfEvtMouseButtonReleased) {
            game->mouse->r_x = event.mouseButton.x;
            game->mouse->r_y = event.mouseButton.y;
        }
    }
}
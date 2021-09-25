/*
** Twi-Fight
** 
** File description:
** handle_events
*/

#include "game.h"

void init_extra_event(extra_events_t *extra)
{
    extra->space_bar_press = 0;
}

void fill_extra_events(sfEvent event, extra_events_t *extra)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
        extra->space_bar_press = 1;
}

extra_events_t handle_events(game_t *game)
{
    sfEvent event;
    extra_events_t extra;

    init_extra_event(&extra);
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
        fill_extra_events(event, &extra);
    }
    return (extra);
}
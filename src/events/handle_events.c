/*
** Twi-Fight
** 
** File description:
** handle_events
*/

#include "game.h"

static void init_extra_event(extra_events_t *extra)
{
    extra->space_bar_press = 0;
}

static void fill_extra_events(sfEvent event, extra_events_t *extra)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
        extra->space_bar_press = 1;
}

static void handle_mouse_events(sfEvent event, mouse_t *mouse)
{
        mouse->x = event.mouseMove.x;
        mouse->y = event.mouseMove.y;
        mouse->p_x = event.mouseButton.x;
        mouse->p_y = event.mouseButton.y;
        mouse->r_x = -1;
        mouse->r_y = -1;
        if (event.type == sfEvtMouseButtonReleased) {
            mouse->r_x = event.mouseButton.x;
            mouse->r_y = event.mouseButton.y;
        }
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
        handle_mouse_events(event, game->mouse);
        fill_extra_events(event, &extra);
    }
    return (extra);
}
/*
** Twi-Fight
** 
** File description:
** main
*/

#include "game.h"

int main(int ac, char **av)
{
    game_t *game = NULL;

    if (handle_errors())
        return (84);
    game = fill_game();
    if (!game)
        return (84);
    while (game->window && game->state != GAME_STATE_EXIT)
        next_scene(game);
    free_game(game);
}
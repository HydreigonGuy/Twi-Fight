/*
** Twi-Fight
** 
** File description:
** fill_game_over_scene
*/

#include "game.h"
#include "ad_lib.h"
#include <stdlib.h>

scene_t *fill_game_over_scene(void)
{
    scene_t *scene = NULL;

    scene = malloc(sizeof(scene_t));
    if (!scene)
        return (NULL);
    scene->bg = NULL;
    scene->btn = NULL;
    fill_background(&scene->bg, my_str_concat(IMAGE_PATH, "game_over_bg.png"),
        0, 0);
    return (scene);
}
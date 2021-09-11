/*
** Twi-Fight
** 
** File description:
** fill_start_menu_scene
*/

#include "game.h"
#include "ad_lib.h"
#include <stdlib.h>

scene_t *fill_start_menu_scene(void)
{
    scene_t *scene = NULL;

    scene = malloc(sizeof(scene_t));
    if (!scene)
        return (NULL);
    scene->bg = NULL;
    scene->btn = NULL;
    fill_background(&scene->bg, my_str_concat(IMAGE_PATH, "start_bg.png"), 0, 0);
    fill_btn(&scene->btn, my_str_concat(IMAGE_PATH, "btn/play.png"), 450, 250);
    fill_rect(scene->btn->spr, 300, 200);
    fill_btn(&scene->btn, my_str_concat(IMAGE_PATH, "btn/exit.png"), 500, 500);
    fill_rect(scene->btn->next->spr, 200, 100);
    return (scene);
}
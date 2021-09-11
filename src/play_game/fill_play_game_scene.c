/*
** Twi-Fight
** 
** File description:
** fill_play_game_scene
*/

#include "game.h"
#include "ad_lib.h"
#include <stdlib.h>

scene_t *fill_play_game_scene(void)
{
    scene_t *scene = NULL;

    scene = malloc(sizeof(scene_t));
    if (!scene)
        return (NULL);
    scene->bg = NULL;
    scene->btn = NULL;
    fill_background(&scene->bg, my_str_concat(IMAGE_PATH, "game_bg.png"), 0, 0);
    fill_btn(&scene->btn, my_str_concat(IMAGE_PATH, "btn/adrien_tower_btn.png"), 1010, 50);
    fill_rect(scene->btn->spr, 180, 100);
    fill_btn(&scene->btn, my_str_concat(IMAGE_PATH, "btn/adrien_tower_btn.png"), 1010, 200);
    fill_rect(scene->btn->next->spr, 180, 100);
    fill_btn(&scene->btn, my_str_concat(IMAGE_PATH, "btn/adrien_tower_btn.png"), 1010, 350);
    fill_rect(scene->btn->next->next->spr, 180, 100);
    fill_btn(&scene->btn, my_str_concat(IMAGE_PATH, "btn/adrien_tower_btn.png"), 1010, 500);
    fill_rect(scene->btn->next->next->next->spr, 180, 100);
    return (scene);
}
/*
** Twi-Fight
** 
** File description:
** fill_wolf_btn
*/

#include "game.h"
#include "ad_lib.h"
#include <stdlib.h>

wolf_btn_t *fill_wolf_btn(void)
{
    wolf_btn_t *btn = NULL;

    btn = malloc(sizeof(wolf_btn_t));
    if (!btn)
        return (NULL);
    btn->cooldown = 0;
    btn->last_shake = 0;
    btn->reset_shake = 0;
    btn->shake_x = 0;
    btn->shake_y = 0;
    btn->cd_spr = fill_sprite(my_str_concat(IMAGE_PATH, "wolf_cd.png"),
        415, 472);
    if (!btn->cd_spr)
        return (NULL);
    fill_rect(btn->cd_spr, 287, 228);
    return (btn);
}
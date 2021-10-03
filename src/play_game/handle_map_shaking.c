/*
** Twi-Fight
** 
** File description:
** handle_map_shaking
*/

#include "game.h"

void handle_map_shaking(playing_t *gi, scene_t *scn)
{
    background_t *hold = scn->bg;

    if (gi->wolf_btn->shake_x != 0 || gi->wolf_btn->shake_y != 0 ||
        gi->wolf_btn->reset_shake) {
        gi->wolf_btn->cd_spr->crds.x = 415 + gi->wolf_btn->shake_x;
        gi->wolf_btn->cd_spr->crds.y = 472 + gi->wolf_btn->shake_y;
        sfSprite_setPosition(gi->wolf_btn->cd_spr->spr,
            gi->wolf_btn->cd_spr->crds);
        for (; hold; hold = hold->next) {
            hold->spr->crds.x = hold->x + gi->wolf_btn->shake_x;
            hold->spr->crds.y = hold->y + gi->wolf_btn->shake_y;
            sfSprite_setPosition(hold->spr->spr, hold->spr->crds);
        }
    }
}
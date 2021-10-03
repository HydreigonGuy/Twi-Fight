/*
** Twi-Fight
** 
** File description:
** handle_wolf_btn_press
*/

#include "game.h"
#include "ad_lib.h"

void handle_wolf_btn_press(mouse_t *mouse, playing_t *gi, int time)
{
    if (my_vector_norm(mouse->r_x, mouse->r_y, 555, 618) < 140 &&
        gi->wolf_btn->cooldown <= 0 && gi->enemy){
        gi->wolf_btn->cooldown = WOLF_BTN_CD;
        mouse_reset(mouse);
    }
    if (!gi->enemy && gi->wolf_btn->cooldown > 0) {
        gi->wolf_btn->cooldown = 0;
        gi->wolf_btn->reset_shake = 1;
        gi->wolf_btn->shake_x = 0;
        gi->wolf_btn->shake_y = 0;
    }
    if (gi->wolf_btn->cooldown <= 0 && gi->wolf_btn->cd_spr->r.top != 0) {
        gi->wolf_btn->cd_spr->r.top = 0;
        sfSprite_setTextureRect(gi->wolf_btn->cd_spr->spr,
            gi->wolf_btn->cd_spr->r);
    }
    if (gi->wolf_btn->cooldown > 0) {
        gi->wolf_btn->cooldown -= time / TOWER_CD_LIMITTER;
        gi->wolf_btn->cd_spr->r.top = (gi->wolf_btn->cd_spr->r.height *
            gi->wolf_btn->cooldown) / WOLF_BTN_CD;
        sfSprite_setTextureRect(gi->wolf_btn->cd_spr->spr,
            gi->wolf_btn->cd_spr->r);
        handle_wolf_map_shake(gi->wolf_btn, time);
    }
}
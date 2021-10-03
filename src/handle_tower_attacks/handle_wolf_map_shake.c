/*
** Twi-Fight
** 
** File description:
** handle_wolf_map_shake
*/

#include "game.h"
#include <stdlib.h>

void handle_wolf_map_shake(wolf_btn_t *btn, int time)
{
    if (btn->cooldown > WOLF_BTN_CD - MAP_SHAKE_TIME) {
        btn->last_shake += time / TOWER_CD_LIMITTER;
        if (btn->last_shake >= TIME_BETWEEN_SHAKES) {
            btn->last_shake = 0;
            btn->shake_x = rand() % SHAKE_PIXEL_LIMIT -
                (SHAKE_PIXEL_LIMIT / 2);
            btn->shake_y = rand() % SHAKE_PIXEL_LIMIT -
                (SHAKE_PIXEL_LIMIT / 2);
        }
    } else if (btn->shake_x != 0 || btn->shake_y != 0) {
        btn->reset_shake = 1;
        btn->shake_x = 0;
        btn->shake_y = 0;
    }
}
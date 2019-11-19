/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

void move_perso(temp_t *time, persorect_t *persorect,
perso_t *perso, hunter_t *hunter)
{
    persorect->pos_perso.x = 40;
    time->time_clock = sfClock_getElapsedTime(time->clock);
    time->sec = time->time_clock.microseconds / 1000000.0;
    if (time->sec > 0.07) {
        persorect->rect.left += 80;
        if (persorect->rect.left > 560) {
            persorect->rect.left = 0;
        }
        sfSprite_move(perso->s_perso, persorect->pos_perso);
        persorect->pos_perso = sfSprite_getPosition(perso->s_perso);
        sfClock_restart(time->clock);
    }
}
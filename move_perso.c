/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

void move_right_to_left(temp_t *time, persorect_t *persorect,
    perso_t *perso, hunter_t *hunter)
{
    if (persorect->pos_perso.x >= 1850)
            persorect->direction = - 1;
        if (persorect->pos_perso2.x >= 1850)
            persorect->direction2 = - 1;
        persorect->pos_perso.x += 20 * persorect->direction;
        persorect->pos_perso2.x += 23 * persorect->direction2;
        sfSprite_setPosition(perso->s_perso, persorect->pos_perso);
        sfSprite_setPosition(perso->s_perso2, persorect->pos_perso2);
}

void move_left_to_right(temp_t *time, persorect_t *persorect,
    perso_t *perso, hunter_t *hunter)
{
    if (persorect->pos_perso.x < 0)
        persorect->direction = 1;
    if (persorect->pos_perso2.x < 0)
        persorect->direction2 = 1;
    persorect->pos_perso.x += 20 * persorect->direction;
    persorect->pos_perso2.x += 23 * persorect->direction2;
}

int move_perso(temp_t *time, persorect_t *persorect,
    perso_t *perso, hunter_t *hunter)
{
    persorect->pos_perso.y = 500;
    persorect->pos_perso2.y = 400;
    time->time_clock = sfClock_getElapsedTime(time->clock);
    time->sec = time->time_clock.microseconds / 1000000.0;
    if (time->sec > 0.07) {
        persorect->rect.left += 80;
        persorect->rect2.left += 80;
        if (persorect->rect.left >= 640 && persorect->rect2.left >= 640) {
            persorect->rect.left = 0;
            persorect->rect2.left = 0;
        }
        move_right_to_left(time, persorect, perso, hunter);
        move_left_to_right(time, persorect, perso, hunter);
        sfClock_restart(time->clock);
    }
}

int random_gen()
{
    int num = (rand() % 2 - 1 + 1);
    return (num);
}

int random_gen2()
{
    int num = (rand() % 3 - 1 + 1);
    return (num);
}
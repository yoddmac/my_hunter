/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

int move_perso(temp_t *time, persorect_t *persorect,
perso_t *perso, hunter_t *hunter)
{
    persorect->pos_perso.y = 500;
    time->time_clock = sfClock_getElapsedTime(time->clock);
    time->sec = time->time_clock.microseconds / 1000000.0;
    if (time->sec > 0.07) {
        persorect->rect.left += 80;
        printf("left1 = %d\n", persorect->rect.left);
        if (persorect->rect.left >= 640)
        {
            persorect->rect.left = 0;
        }
        if (persorect->pos_perso.x > 1850) {
            persorect->direction = - 1;
        }
        persorect->pos_perso.x += 23 * persorect->direction;
        sfSprite_setPosition(perso->s_perso, persorect->pos_perso);
        //sfSprite_setPosition(perso->s_perso2, persorect->pos_perso);

        if(persorect->pos_perso.x < 0) {
            persorect->direction = 1;
        }
        sfClock_restart(time->clock);
        persorect->pos_perso.x += 23 * persorect->direction;
    }
}

int move_perso2(temp_t *time, persorect_t *persorect,
perso_t *perso, hunter_t *hunter)
{
    //persorect->pos_perso2.y = 200;
    time->time2 = sfClock_getElapsedTime(time->clock);
    time->sec2 = time->time2.microseconds / 1000000.0;
    if (time->sec2 > 0.07) {
        printf("ici");
        printf("left2 = %d\n", persorect->rect2.left);
        persorect->rect2.left += 80;
        if (persorect->rect2.left >= 640)
        {
            printf("ici");
            persorect->rect2.left = 0;
        }
        sfClock_restart(time->clock2);
    }
}

void game_hit(texture_t *tex, hunter_t *window)
{
    sfText_setPosition(tex->text, tex->text_pos);
    if (tex->hit_true == 1) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(tex->clock_text)) > 800) {
            tex->hit_true = 0;
            sfClock_restart(tex->clock_text);
        }
        else{
            sfRenderWindow_drawText(window->window, tex->text, NULL);
        }
    }
}

int random_gen()
{
    int num = (rand() % 2 - 1 + 1);

    return (num);
}

void display_hit(texture_t *tex, hunter_t *window)
{
    text_create(tex);
    text_from(tex);
    text_font(tex);
    write_text(tex);
    size_text(tex);
    set_text_color(tex);
}
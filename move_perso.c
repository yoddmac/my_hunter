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

        if (persorect->pos_perso.x >= 1850)
            persorect->direction = - 1;
        if (persorect->pos_perso2.x >= 1850)
            persorect->direction2 = - 1;

        persorect->pos_perso.x += 20 * persorect->direction;
        persorect->pos_perso2.x += 23 * persorect->direction2;
        sfSprite_setPosition(perso->s_perso, persorect->pos_perso);
        sfSprite_setPosition(perso->s_perso2, persorect->pos_perso2);

        if(persorect->pos_perso.x < 0 )
            persorect->direction = 1;
        if(persorect->pos_perso2.x < 0) 
            persorect->direction2 = 1;
        sfClock_restart(time->clock);
        persorect->pos_perso.x += 20 * persorect->direction;
        persorect->pos_perso2.x += 23 * persorect->direction2;
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

void display_hit(texture_t *tex, hunter_t *hunter, persorect_t *persorect)
{
    text_create(tex);
    text_from(tex);
    text_font(tex);
    write_text(tex, persorect);
    size_text(tex);
    set_text_color(tex);
}
/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

void cursor(hunter_t *hunter, perso_t *perso, persorect_t *persorect)
{
    sfRenderWindow_setMouseCursorVisible(hunter->window, sfFalse);
    perso->mouse = sfMouse_getPositionRenderWindow(hunter->window);
    sfMouse_getPositionRenderWindow(hunter->window);
    sfSprite_setPosition(perso->s_cursor, (sfVector2f)
    {perso->mouse.x, perso->mouse.y});
}

void check_touch(hunter_t *hunter, persorect_t *persorect, perso_t *perso,
    texture_t *tex)
{
    persorect->c = 0;
    persorect->f_rect = sfSprite_getGlobalBounds(perso->s_perso);
    perso->mouse = sfMouse_getPositionRenderWindow(hunter->window);
    persorect->f_rect2 = sfSprite_getGlobalBounds(perso->s_perso2);
    if (sfFloatRect_contains(&persorect->f_rect,
        perso->mouse.x, perso->mouse.y) == sfTrue) {
        persorect->c = 1;
        shoot(hunter, perso, persorect, tex);
    }
    if (sfFloatRect_contains(&persorect->f_rect2, perso->mouse.x,
        perso->mouse.y) == sfTrue) {
        persorect->c = 2;
        shoot(hunter, perso, persorect, tex);
    }
}

void init_shoot(hunter_t *hunter, perso_t *perso, persorect_t *persorect,
    texture_t *tex)
{
    int a = random_gen();
    if (a == 0) {
        if (persorect->c == 1) {
            persorect->pos_perso.x = 0;
            persorect->direction = 1;
        } else {
            persorect->pos_perso2.x = 0;
            persorect->direction2 = 1;
        }
    } else {
        if (persorect->c == 1) {
            persorect->pos_perso.x = 1850;
            persorect->direction = -1;
        } else {
            persorect->pos_perso2.x = 1850;
            persorect->direction2 = -1;
        }
    }
}

int shoot (hunter_t *hunter, perso_t *perso, persorect_t *persorect,
    texture_t *tex)
{
    perso->mouse = sfMouse_getPositionRenderWindow(hunter->window);
    persorect->f_rect = sfSprite_getGlobalBounds(perso->s_perso);
    persorect->f_rect2 = sfSprite_getGlobalBounds(perso->s_perso2);
    sfSound_play(hunter->sound);
    persorect->ipos_perso = sfMouse_getPosition((sfWindow *)hunter->window);
    persorect->ipos_perso2 = sfMouse_getPosition((sfWindow *)hunter->window);
    sfClock_restart(tex->clock_text);
    tex->hit_true = 1;
    sfVector2i tmp = sfMouse_getPositionRenderWindow(hunter->window);
    tex->text_pos.x = tmp.x;
    tex->text_pos.y = tmp.y;
    init_shoot(hunter, perso, persorect, tex);
}

void game_hit(texture_t *tex, hunter_t *window)
{
    sfText_setPosition(tex->text, tex->text_pos);
    if (tex->hit_true == 1) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime
            (tex->clock_text)) > 800) {
            tex->hit_true = 0;
            sfClock_restart(tex->clock_text);
        }
        else{
            sfRenderWindow_drawText(window->window, tex->text, NULL);
        }
    }
}
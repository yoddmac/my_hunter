/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

void analyse_events(hunter_t *hunter, perso_t *perso)
{
    if (hunter->event.type == sfEvtClosed)
        sfRenderWindow_close(hunter->window);
}

void cursor(hunter_t *hunter, perso_t *perso, persorect_t* persorect)
{
    sfRenderWindow_setMouseCursorVisible(hunter->window, sfFalse);
    perso->mouse = sfMouse_getPositionRenderWindow(hunter->window);
    sfMouse_getPositionRenderWindow(hunter->window);
    sfSprite_setPosition(perso->s_cursor, (sfVector2f){perso->mouse.x, perso->mouse.y});
}

int shoot (hunter_t *hunter, perso_t *perso, persorect_t* persorect, texture_t *tex)
{
    int a = random_gen();
    perso->mouse = sfMouse_getPositionRenderWindow(hunter->window);
    persorect->f_rect = sfSprite_getGlobalBounds(perso->s_perso);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            sfSound_play(hunter->sound);
            persorect->ipos_perso = sfMouse_getPosition((sfWindow *)hunter->window);
        if(sfFloatRect_contains(&persorect->f_rect, perso->mouse.x, perso->mouse.y) == sfTrue) {
            sfClock_restart(tex->clock_text);
            tex->hit_true = 1;
            sfVector2i tmp = sfMouse_getPositionRenderWindow(hunter->window);
            tex->text_pos.x = tmp.x;
            tex->text_pos.y = tmp.y;
            sfSprite_move(perso->s_perso, persorect->pos_perso);
            if (a == 1) {
                persorect->pos_perso.x = 0;
            }
            if (a == 0) {
                persorect->pos_perso.x = 1850;
                persorect->direction = -1;
            }
        }
    }
}

void window (hunter_t *hunter, texture_t *tex, perso_t *perso,
persorect_t *persorect, temp_t *time)
{
    malloc_struct(&hunter, &tex, &perso, &persorect, &time);
    create_sprite(hunter, tex, perso, persorect);
    display_hit(tex, hunter);
    create_texture(tex, perso, time, hunter);
    set_texture(hunter, tex, perso, persorect);
    hunter->video.width = 1920;
    hunter->video.height = 1080;
    persorect->rect.width = 80;
    persorect->rect.height = 89;
    persorect->rect.left = 0;
    persorect->rect2.width = 80;
    persorect->rect2.height = 89;
    persorect->rect2.left = 0;
    persorect->direction = 1;
    sfMusic_play(hunter->music);

    hunter->window = sfRenderWindow_create(hunter->video,
                                           "Window Hunter",
                                           sfResize | sfClose,
                                           NULL);
    sfRenderWindow_setFramerateLimit(hunter->window, 30);

    while (sfRenderWindow_isOpen(hunter->window)) {
        while (sfRenderWindow_pollEvent(hunter->window, &hunter->event)) {
            analyse_events(hunter, perso);
            shoot(hunter, perso, persorect, tex);
        }
        move_perso(time, persorect, perso, hunter);
        sfRenderWindow_clear(hunter->window, sfBlack);
        cursor(hunter, perso, persorect);
        draw_texture(hunter, tex, perso, persorect);
        sfRenderWindow_display(hunter->window);
    }
    destroy_all(hunter, tex, perso, persorect);
}

int main ()
{
    hunter_t *hunter;
    texture_t *tex;
    perso_t *perso;
    persorect_t *persorect;
    temp_t *time;
    window(hunter, tex, perso, persorect, time);
}

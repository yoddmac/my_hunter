/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

void analyse_events(hunter_t *hunter, perso_t *perso, persorect_t *persorect,
    texture_t *tex)
{
    if (hunter->event.type == sfEvtClosed)
        sfRenderWindow_close(hunter->window);
    if (hunter->event.type == sfEvtMouseButtonPressed)
        check_touch(hunter, persorect, perso, tex);
}

void init_window(hunter_t *hunter, texture_t *tex, perso_t *perso,
    persorect_t *persorect, temp_t *time)
{
    hunter->video.width = 1920;
    hunter->video.height = 1080;
    persorect->rect.width = 80;
    persorect->rect.height = 89;
    persorect->rect.left = 0;
    persorect->rect2.width = 80;
    persorect->rect2.height = 89;
    persorect->rect2.left = 0;
    persorect->direction = 1;
    persorect->direction2 = 1;
    persorect->life = 0;
    hunter->window = sfRenderWindow_create(hunter->video,
    "Window Hunter", sfResize | sfClose, NULL);
}

void window(hunter_t *hunter, texture_t *tex, perso_t *perso,
    persorect_t *persorect, temp_t *time)
{
    malloc_struct(&hunter, &tex, &perso, &persorect, &time);
    create_sprite(hunter, tex, perso, persorect);
    display_hit(tex, hunter, persorect);
    create_texture(tex, perso, time, hunter);
    set_texture(hunter, tex, perso, persorect);
    sfMusic_play(hunter->music);
    init_window(hunter, tex, perso, persorect, time);
    while (sfRenderWindow_isOpen(hunter->window)) {
        while (sfRenderWindow_pollEvent(hunter->window, &hunter->event)) {
            analyse_events(hunter, perso, persorect, tex);
        }
        move_perso(time, persorect, perso, hunter);
        sfRenderWindow_clear(hunter->window, sfBlack);
        cursor(hunter, perso, persorect);
        draw_texture(hunter, tex, perso, persorect);
        sfRenderWindow_display(hunter->window);
    }
    destroy_all(hunter, tex, perso, persorect);
    free_malloc(hunter, tex, perso, persorect, time);
}

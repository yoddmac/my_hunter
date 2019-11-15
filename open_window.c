/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

void analyse_events(hunter_t *hunter)
{
    if (hunter->event.type == sfEvtClosed)
        sfRenderWindow_close(hunter->window);
}

void window (hunter_t *hunter, texture_t *tex, perso_t *perso, persorect_t *persorect, temp_t *time)
{
    //sfRenderWindow_setFramerateLimit(hunter->window, 30);
    malloc_struct(&hunter, &tex, &perso, &persorect, &time);
    create_sprite(tex, perso, persorect);
    create_texture(tex, perso, time);
    set_texture(tex, perso, persorect);
    hunter->video.width = 800;
    hunter->video.height = 600;
    persorect->rect.width = 74;
    persorect->rect.height = 80;
    persorect->rect.left = 30;

    hunter->window = sfRenderWindow_create(hunter->video,
                                           "Window Hunter", 
                                           sfResize | sfClose,
                                           NULL);

    while(sfRenderWindow_isOpen(hunter->window)) {
        while (sfRenderWindow_pollEvent(hunter->window, &hunter->event))
        {
            analyse_events(hunter);
        }
            move_perso(time, persorect, perso, hunter);
            sfRenderWindow_clear(hunter->window, sfBlack);
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

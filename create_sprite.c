/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

void create_sprite(texture_t *tex, perso_t *perso, persorect_t *persorect)
{
    tex->s_back = sfSprite_create();
    perso->s_perso = sfSprite_create();
    persorect->s_persorect = sfSprite_create();
}

void create_texture(texture_t *tex, perso_t *perso, temp_t *time)
{
    tex->t_background = sfTexture_createFromFile("./png/foret.png", NULL);
    perso->t_perso = sfTexture_createFromFile("./png/mouette_inversé.png", NULL);
    time->clock = sfClock_create();
}

void set_texture(texture_t *tex, perso_t *perso, persorect_t *persorect)
{
    sfSprite_setTexture(tex->s_back, tex->t_background, sfTrue);
    sfSprite_setTexture(perso->s_perso, perso->t_perso, sfTrue);
    sfSprite_setTextureRect(persorect->s_persorect, persorect->rect);
}

void draw_texture(hunter_t *hunter, texture_t *tex, perso_t *perso, persorect_t *persorect)
{
    sfRenderWindow_drawSprite(hunter->window, tex->s_back, NULL);
    sfRenderWindow_drawSprite(hunter->window, perso->s_perso, NULL);
    sfRenderWindow_drawSprite(hunter->window, persorect->s_persorect, NULL);
    sfSprite_setTextureRect(perso->s_perso, persorect->rect);
}

void destroy_all(hunter_t *hunter, texture_t *tex, perso_t *perso, persorect_t *persorect)
{
    sfTexture_destroy(perso->t_perso);
    sfTexture_destroy(tex->t_background);
    sfRenderWindow_destroy(hunter->window);
}
/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

void create_sprite(hunter_t *hunter, texture_t *tex, perso_t *perso,
    persorect_t *persorect)
{
    tex->s_back = sfSprite_create();
    perso->s_game_over = sfSprite_create();
    perso->s_perso = sfSprite_create();
    perso->s_perso2 = sfSprite_create();
    persorect->s_persorect = sfSprite_create();
    persorect->s_persorect2 = sfSprite_create();
    perso->s_cursor = sfSprite_create();
    tex->s_tube_back = sfSprite_create();
    hunter->sound = sfSound_create();
}

void create_texture(texture_t *tex, perso_t *perso, temp_t *time,
    hunter_t *hunter)
{
    hunter->music = sfMusic_createFromFile("./png/menu.ogg");
    hunter->buffer = sfSoundBuffer_createFromFile("./png/sniper.ogg");
    tex->t_background = sfTexture_createFromFile("./png/background.png", NULL);
    perso->t_perso = sfTexture_createFromFile("./png/crevette.png", NULL);
    perso->t_perso2 = sfTexture_createFromFile("./png/crevette2.png", NULL);
    tex->t_tube_back = sfTexture_createFromFile("./png/tube.png", NULL);
    perso->t_cursor = sfTexture_createFromFile("./png/viseur.png", NULL);
    perso->t_game_over = sfTexture_createFromFile("./png/gameover.png", NULL);
    time->clock = sfClock_create();
    tex->clock_text = sfClock_create();
}

void set_texture(hunter_t *hunter, texture_t * tex, perso_t *perso,
    persorect_t *persorect)
{
    sfSound_setBuffer(hunter->sound, hunter->buffer);
    sfSprite_setTexture(tex->s_tube_back, tex->t_tube_back, sfTrue);
    sfSprite_setTexture(perso->s_game_over, perso->t_game_over, sfTrue);
    sfSprite_setTexture(tex->s_back, tex->t_background, sfTrue);
    sfSprite_setTexture(perso->s_perso, perso->t_perso, sfTrue);
    sfSprite_setTexture(perso->s_perso2, perso->t_perso2, sfTrue);
    sfSprite_setTexture(perso->s_cursor, perso->t_cursor, sfTrue);
    sfSprite_setTextureRect(persorect->s_persorect, persorect->rect);
    sfSprite_setTextureRect(persorect->s_persorect2, persorect->rect2);
}

void draw_texture(hunter_t *hunter, texture_t *tex,
    perso_t *perso, persorect_t *persorect)
{
    sfRenderWindow_drawSprite(hunter->window, tex->s_back, NULL);
    sfRenderWindow_drawSprite(hunter->window, perso->s_perso, NULL);
    sfRenderWindow_drawSprite(hunter->window, perso->s_perso2, NULL);
    sfRenderWindow_drawSprite(hunter->window, persorect->s_persorect, NULL);
    sfRenderWindow_drawSprite(hunter->window, persorect->s_persorect2, NULL);
    sfSprite_setTextureRect(perso->s_perso, persorect->rect);
    sfSprite_setTextureRect(perso->s_perso2, persorect->rect2);
    sfRenderWindow_drawSprite(hunter->window, perso->s_cursor, NULL);
    sfRenderWindow_drawSprite(hunter->window, tex->s_tube_back, NULL);
    game_hit(tex, hunter);
}

void destroy_all(hunter_t *hunter, texture_t *tex,
    perso_t *perso, persorect_t *persorect)
{
    sfTexture_destroy(perso->t_perso);
    sfSprite_destroy(perso->s_perso);
    sfTexture_destroy(perso->t_cursor);
    sfSprite_destroy(perso->s_cursor);
    sfTexture_destroy(perso->t_perso2);
    sfSprite_destroy(perso->s_perso2);
    sfTexture_destroy(tex->t_tube_back);
    sfSprite_destroy(tex->s_tube_back);
    sfTexture_destroy(perso->t_game_over);
    sfSprite_destroy(perso->s_game_over);
    sfSprite_destroy(tex->s_back);
    sfTexture_destroy(tex->t_background);
    sfSprite_destroy(persorect->s_persorect);
    sfSprite_destroy(persorect->s_persorect2);

    sfText_destroy(tex->text);
    sfText_destroy(tex->text_score);

    sfRenderWindow_destroy(hunter->window);
}
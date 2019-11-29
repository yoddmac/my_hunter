/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

void text_create(texture_t *tex)
{
    tex->text = sfText_create();
    tex->text_score = sfText_create();
    tex->font = sfFont_createFromFile("./text/hit.ttf");
}

void text_font(texture_t *tex)
{
    sfText_setFont(tex->text, tex->font);
    sfText_setFont(tex->text_score, tex->font);

}

void write_text(texture_t *tex, persorect_t *persorect)
{
    sfText_setString(tex->text, "HIT");
    sfText_setString(tex->text_score, persorect->char_score);
}

void size_text(texture_t *tex)
{
    sfText_setCharacterSize(tex->text, 50);
    sfText_setCharacterSize(tex->text_score, 50);
    sfText_setColor(tex->text, sfWhite);
    sfText_setColor(tex->text_score, sfRed);
}

void draw_text(texture_t *tex, hunter_t *hunter)
{
    sfRenderWindow_drawText(hunter->window, tex->text, NULL);
    sfRenderWindow_drawText(hunter->window, tex->text_score, NULL);
}
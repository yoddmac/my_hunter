/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

void text_create (texture_t *tex)
{
    tex->text = sfText_create();
}

void text_from(texture_t *tex)
{
    tex->font = sfFont_createFromFile("./text/hit.ttf");
}

void text_font(texture_t *tex)
{
    sfText_setFont(tex->text, tex->font);
}

void write_text(texture_t *tex)
{
    sfText_setString(tex->text, "HIT");
}

void size_text(texture_t *tex) 
{
    sfText_setCharacterSize(tex->text, 50);
}

void set_text_color(texture_t *tex)
{
    sfText_setColor(tex->text, sfWhite);
}

void draw_text(texture_t *tex, hunter_t *hunter)
{
    sfRenderWindow_drawText(hunter->window, tex->text, NULL);
}
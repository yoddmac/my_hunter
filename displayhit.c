/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

void display_hit(texture_t *tex, hunter_t *hunter, persorect_t *persorect)
{
    text_create(tex);
    text_font(tex);
    write_text(tex, persorect);
    size_text(tex);
}
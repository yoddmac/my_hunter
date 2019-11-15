/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

void malloc_struct (hunter_t **hunter, texture_t **tex, perso_t **perso, persorect_t **persorect, temp_t **time)
{
    *hunter = malloc(sizeof(hunter_t));
    *tex = malloc(sizeof(texture_t));
    *perso = malloc(sizeof(perso_t));
    *persorect = malloc(sizeof(persorect_t));
    *time = malloc(sizeof(temp_t));
}
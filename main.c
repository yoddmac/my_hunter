/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

int main(int ac, char **av)
{
    char c;
    if (ac == 2)
    {
        help();
    }
    if (ac == 1) {
    hunter_t *hunter;
    texture_t *tex;
    perso_t *perso;
    persorect_t *persorect;
    temp_t *time;
    window(hunter, tex, perso, persorect, time);
    }
}
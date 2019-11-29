/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

void end_game(persorect_t *persorect, perso_t *perso)
{
   sfVector2f end = sfSprite_getPosition(perso->s_perso);
   if (end.x >= 1700) {
       persorect->nb_bong += 1;
       printf("%d\n", persorect->nb_bong);
       if (persorect->nb_bong == 5) {
           persorect->life = 0;
       }
    }
}
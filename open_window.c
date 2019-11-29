/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include "hunter.h"

void check_touch(hunter_t *hunter, persorect_t *persorect, perso_t *perso, texture_t *tex)
{
    //static int score = 0;
    persorect->c = 0;
    persorect->f_rect = sfSprite_getGlobalBounds(perso->s_perso);
    perso->mouse = sfMouse_getPositionRenderWindow(hunter->window);
    persorect->f_rect2 = sfSprite_getGlobalBounds(perso->s_perso2);

    if (sfFloatRect_contains(&persorect->f_rect, perso->mouse.x, perso->mouse.y) == sfTrue) {
        persorect->c = 1;
        shoot(hunter, perso, persorect, tex);
            //score++;
            //printf("%d\n", score);
    }

    if (sfFloatRect_contains(&persorect->f_rect2, perso->mouse.x, perso->mouse.y) == sfTrue)
    {
        persorect->c = 2;
        shoot(hunter, perso, persorect, tex);
            // score++;
            // printf("%d\n", score);
    }
}
void analyse_events(hunter_t *hunter, perso_t *perso, persorect_t *persorect, texture_t *tex)
{
    if (hunter->event.type == sfEvtClosed)
        sfRenderWindow_close(hunter->window);
    if (hunter->event.type == sfEvtMouseButtonPressed)
            check_touch(hunter, persorect, perso, tex);
}

void cursor(hunter_t *hunter, perso_t *perso, persorect_t* persorect)
{
    sfRenderWindow_setMouseCursorVisible(hunter->window, sfFalse);
    perso->mouse = sfMouse_getPositionRenderWindow(hunter->window);
    sfMouse_getPositionRenderWindow(hunter->window);
    sfSprite_setPosition(perso->s_cursor, (sfVector2f){perso->mouse.x, perso->mouse.y});
}


int shoot (hunter_t *hunter, perso_t *perso, persorect_t* persorect, texture_t *tex)
{
    int a = random_gen();
    perso->mouse = sfMouse_getPositionRenderWindow(hunter->window);
    persorect->f_rect = sfSprite_getGlobalBounds(perso->s_perso);
    persorect->f_rect2 = sfSprite_getGlobalBounds(perso->s_perso2);
    sfSound_play(hunter->sound);
    persorect->ipos_perso = sfMouse_getPosition((sfWindow *)hunter->window);
    persorect->ipos_perso2 = sfMouse_getPosition((sfWindow *)hunter->window);
    sfClock_restart(tex->clock_text);
    tex->hit_true = 1;
    sfVector2i tmp = sfMouse_getPositionRenderWindow(hunter->window);
    tex->text_pos.x = tmp.x;
    tex->text_pos.y = tmp.y;
    if (a == 0) {
        if (persorect->c == 1) {
            persorect->pos_perso.x = 0;
            persorect->direction = 1;
        }
        else {
            persorect->pos_perso2.x = 0;
            persorect->direction2 = 1;
        }
    }
    else {
        if (persorect->c == 1) {
            persorect->pos_perso.x = 1850;
            persorect->direction = -1;
        }
        else {
            persorect->pos_perso2.x = 1850;
            persorect->direction2 = -1;
        }
    }
}

void window (hunter_t *hunter, texture_t *tex, perso_t *perso,
persorect_t *persorect, temp_t *time)
{
    malloc_struct(&hunter, &tex, &perso, &persorect, &time);
    create_sprite(hunter, tex, perso, persorect);
    display_hit(tex, hunter, persorect);
    create_texture(tex, perso, time, hunter);
    set_texture(hunter, tex, perso, persorect);
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
    sfMusic_play(hunter->music);
    persorect->life = 0;
    persorect->nb_bong = 0;

    hunter->window = sfRenderWindow_create(hunter->video,
                                           "Window Hunter",
                                           sfResize | sfClose,
                                           NULL);
    while (sfRenderWindow_isOpen(hunter->window)) {
        while (sfRenderWindow_pollEvent(hunter->window, &hunter->event)) {
            analyse_events(hunter, perso, persorect, tex);
            end_game(persorect, perso);
        }
        //printf("%s\n", persorect->score);
        move_perso(time, persorect, perso, hunter);
        sfRenderWindow_clear(hunter->window, sfBlack);
        cursor(hunter, perso, persorect);
        if (persorect->life == 0)
            (sfRenderWindow_drawSprite(hunter->window, perso->s_game_over, NULL));
        draw_texture(hunter, tex, perso, persorect);
        sfRenderWindow_display(hunter->window);
    }
    destroy_all(hunter, tex, perso, persorect);
}

/*char* my_itoa(int nbr)
{
    char *res;
    int i = 0;
    res = malloc(sizeof(char) * 6);

    if (nbr == 0) {
        res[i] = '0';
        res[i + 1] = '\0';
        return (res);
    }
    while(nbr > 0) {
        res[i] = '0';
        res[i] = nbr % 10;
        nbr /= 10;
        i++;
    }
    res[i] = '\0';
    my_revstr(res);
    //printf("%s\n", res);
    return (res);
}*/

/*void score(texture_t *tex, hunter_t *hunter, persorect_t *persorect)
{
    persorect->score = 0;
    persorect->char_score = my_itoa(score);
    sfText_setPosition(tex->text_score, (sfVector2f){50, 0});
    sfRenderWindow_drawText(hunter->window, tex->text_score, NULL);

}*/
int main ()
{
    hunter_t *hunter;
    texture_t *tex;
    perso_t *perso;
    persorect_t *persorect;
    temp_t *time;
    window(hunter, tex, perso, persorect, time);
}

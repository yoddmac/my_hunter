/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <time.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio.h>
#include <stdio.h>

typedef struct hunter_s
{
    sfRenderWindow *window;
    sfVideoMode video;
    sfEvent event;

} hunter_t;

typedef struct perso_s
{
    sfTexture *t_perso;
    sfSprite *s_perso;

} perso_t;

typedef struct persorect_s
{
    sfIntRect rect;
    sfSprite *s_persorect;
    sfRectangleShape *shape;
    sfVector2f x;

} persorect_t;

typedef struct texture_s
{
    sfTexture *t_background;
    sfSprite *s_back;

} texture_t;

typedef struct temp_s
{
    sfClock *clock;
    sfTime time_clock;
    sfTime my_time;
    float sec;
} temp_t;

void move_perso(temp_t *time, persorect_t *persorect, perso_t *perso, hunter_t *hunter);
void analyse_events(hunter_t *hunter);
void window(hunter_t *hunter, texture_t *tex, perso_t *perso, persorect_t *persorect, temp_t *time);
void create_sprite(texture_t *tex, perso_t *perso, persorect_t *persorect);
void create_texture(texture_t *tex, perso_t *perso, temp_t *time);
void set_texture(texture_t *tex, perso_t *perso, persorect_t *persorect);
void draw_texture(hunter_t *hunter, texture_t *tex, perso_t *perso, persorect_t *persorect);
void destroy_all(hunter_t *hunter, texture_t *tex, perso_t *perso, persorect_t *persorect);
void malloc_struct(hunter_t **hunter, texture_t **tex, perso_t **perso, persorect_t **persorect, temp_t **time);

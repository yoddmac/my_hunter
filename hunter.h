/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct hunter_s
{
    sfRenderWindow *window;
    sfVideoMode video;
    sfEvent event;
    sfMusic *music;
    sfSoundBuffer *buffer;
    sfSound *sound;
} hunter_t;

typedef struct perso_s
{
    sfTexture *t_perso;
    sfSprite *s_perso;

    sfTexture *t_perso2;
    sfSprite *s_perso2;

    sfSprite *s_cursor;
    sfTexture *t_cursor;
    sfVector2i mouse;

    sfTexture *t_game_over;
    sfSprite *s_game_over;

} perso_t;

typedef struct persorect_s
{
    sfIntRect rect;
    sfIntRect rect2;
    sfFloatRect f_rect;
    sfFloatRect f_rect2;

    int direction;
    int direction2;
    int c;
    int score;
    char *char_score;
    int fail;
    int life;
    int nb_miss;

    sfSprite *s_persorect;
    sfSprite *s_persorect2;

    sfVector2f pos_perso;
    sfVector2f pos_perso2;
    sfVector2i ipos_perso;
    sfVector2i ipos_perso2;

} persorect_t;

typedef struct texture_s
{
    sfTexture *t_background;
    sfSprite *s_back;

    sfTexture *t_tube_back;
    sfSprite *s_tube_back;

    sfText *text_score;

    sfText *text;
    sfFont *font;
    sfClock *clock_text;
    int hit_true;
    sfVector2f text_pos;
} texture_t;

typedef struct temp_s
{
    sfClock *clock2;
    sfTime time2;
    float sec2;

    sfClock *clock;
    sfTime time_clock;
    float sec;
} temp_t;

void game_hit(texture_t *tex, hunter_t *window);
void display_hit(texture_t *tex, hunter_t *hunter, persorect_t *persorect);
int move_perso(temp_t *time, persorect_t *persorect, perso_t *perso,
hunter_t *hunter);
int move_perso2(temp_t *time, persorect_t *persorect, perso_t *perso,
hunter_t *hunter);
void analyse_events(hunter_t *hunter, perso_t *perso, persorect_t *persorect,
texture_t *tex);
void window(hunter_t *hunter, texture_t *tex, perso_t *perso,
persorect_t *persorect, temp_t *time);
void create_sprite(hunter_t *window, texture_t *tex,
perso_t *perso, persorect_t *persorect);
void create_texture(texture_t *tex, perso_t *perso,
temp_t *time, hunter_t *hunter);
void set_texture(hunter_t *hunter, texture_t *tex, perso_t *perso,
persorect_t *persorect);
void draw_texture(hunter_t *hunter, texture_t *tex, perso_t *perso,
persorect_t *persorect);
void destroy_all(hunter_t *hunter, texture_t *tex, perso_t *perso,
persorect_t *persorect);
void malloc_struct(hunter_t **hunter, texture_t **tex, perso_t **perso,
persorect_t **persorect, temp_t **time);
void text_create(texture_t *tex);
void text_from(texture_t *tex);
void text_font(texture_t *tex);
void write_text(texture_t *tex,
persorect_t *persorect);
void size_text(texture_t *tex);
void set_text_color(texture_t *tex);
void draw_text(texture_t *tex, hunter_t *hunter);
int random_gen();
void score(texture_t *tex, hunter_t *hunter, persorect_t *persorect);
int shoot (hunter_t *hunter, perso_t *perso,
persorect_t *persorect, texture_t *tex);
void check_touch(hunter_t *hunter, persorect_t *persorect,
perso_t *perso, texture_t *tex);
void free_malloc(hunter_t **hunter, texture_t **tex, perso_t **perso,
persorect_t **persorect, temp_t **time);
void cursor(hunter_t *hunter, perso_t *perso, persorect_t *persorect);

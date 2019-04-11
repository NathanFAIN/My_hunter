/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** my structs
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct obj_bird_s
{
    sfClock *clock;
    sfTime time;
    float seconds;
    int compt;
    int heart;
    int death;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
} obj_bird_t;

typedef struct obj_gun_s
{
    sfClock *clock;
    sfTime time;
    float seconds;
    int compt;
    sfTexture *text_exp;
    sfSprite *spr_exp;
    sfVector2f pos_exp;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
} obj_gun_t;

typedef struct obj_heart_s
{
    int heart;
    int compt;
    sfIntRect rect;
    sfText *txt;
    sfTexture *text;
    sfSprite *sprite;
    sfVector2f position;
    sfMusic* gun1;
    sfMusic* gun2;
} obj_heart_t;

typedef struct obj_menu_s
{
    sfText *txt;
    char *score;
    sfTexture *text;
    sfTexture *text2;
    sfTexture *text3;
    sfSprite *spr_b1;
    sfSprite *spr_logo;
    sfVector2f position;
    sfVector2f pos_text;
    sfVector2f pos_logo;

} obj_menu_t;

typedef struct game_s
{
    obj_bird_t *b;
    obj_gun_t g;
    sfRenderWindow *w;
    obj_heart_t h;
    obj_menu_t m;
    sfTexture *text;
    sfSprite *sprite;
    sfEvent event;
    sfSprite *cursorSpr;
    int loop;
    int i;
    int bird;
    int score;
    int game;
} game_t;

#endif /* STRUCT_H_ */

/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** main.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include "struct.h"
#include "my.h"
#include <stdio.h>

int my_co_bird(int rect, int compt)
{
    rect = (compt == 5) ? 110 : rect;
    rect = (compt == 10) ? 220 : rect;
    rect = (compt == 15) ? 440 : rect;
    rect = (compt == 20) ? 330 : rect;
    rect = (compt == 25) ? 440 : rect;
    rect = (compt == 30) ? 220 : rect;
    return (rect);
}

game_t my_bird(game_t game)
{
    for (int i = 0; i < game.i; i++) {
        game.b[i].time = sfClock_getElapsedTime(game.b[i].clock);
        game.b[i].seconds = (game.b[i].time).microseconds / 10000.0;
        if (game.b[i].seconds > 1.0) {
            sfClock_restart(game.b[i].clock);
            (game.b[i].position).x += (game.b[i].death == 3) ? 6 : 0;
            (game.b[i].rect).left = my_co_bird(game.b[i].rect.left, \
            game.b[i].compt);
            game.b[i].compt = (game.b[i].compt >= 30) ? 0 : game.b[i].compt;
            game.b[i].compt++;
            game.b[i] = my_death_bird(game.b[i]);
        }
    }
    return (game);
}

void put_bird(game_t game)
{
    for (int i = 0; i < game.i; i++) {
        if (game.b[i].heart) {
            sfSprite_setTexture(game.b[i].sprite, game.b[i].texture, sfTrue);
            sfSprite_setTextureRect(game.b[i].sprite, game.b[i].rect);
            sfSprite_setPosition(game.b[i].sprite, game.b[i].position);
            sfRenderWindow_drawSprite(game.w, game.b[i].sprite, NULL);
        }
    }
}

obj_bird_t recreate_bird(obj_bird_t old)
{
    obj_bird_t bird;

    sfClock_destroy(old.clock);
    sfSprite_destroy(old.sprite);
    sfTexture_destroy(old.texture);
    return (create_bird(bird));
}

game_t spawn_bird(game_t game)
{
    game.i = (game.h.compt == 4) ? 2 : game.i;
    game.i = (game.h.compt == 10) ? 3 : game.i;
    game.i = (game.h.compt == 15) ? 4 : game.i;
    game.i = (game.h.compt == 30) ? 5 : game.i;
    return (game);
}

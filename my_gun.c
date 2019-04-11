/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** main.c
*/

#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include "my.h"
#include "struct.h"
#include <stdio.h>

obj_bird_t my_death_bird(obj_bird_t bird)
{
    int c = bird.death;

    if (c < 3) {
        bird.rect.width = 80;
        bird.rect.top = 110;
        bird.position.y += 2;
        bird.position.x += 1;
        bird.rect.left  = (c < 3 && c >= -5) ? 100 : bird.rect.left;
        bird.rect.left  = (c < -5 && c >= -13) ? 180 : bird.rect.left;
        bird.rect.left  = (c < -13 && c >= -21) ? 360 : bird.rect.left;
        bird.rect.left  = (c < -21) ? 460 : bird.rect.left;
        bird = (c == -29) ? recreate_bird(bird) : bird;
        bird.death = (bird.death == 3) ? bird.death : c - 1;
    }
    return (bird);
}

void my_gun_song(game_t game)
{
    if (rand() % 2)
        sfMusic_play(game.h.gun1);
    else
        sfMusic_play(game.h.gun2);
}

int my_shoot(obj_bird_t bird, sfRenderWindow *window)
{
    int x = sfMouse_getPositionRenderWindow(window).x;
    int y = sfMouse_getPositionRenderWindow(window).y;

    if ((bird.position).x + 100 > x && (bird.position).x < x && \
    bird.position.y + 100 > y && bird.position.y < y  && bird.death == 3)
        return (1);
    else
        return (0);
}

game_t my_gun(game_t game)
{
    game.g.time = sfClock_getElapsedTime(game.g.clock);
    game.g.seconds = game.g.time.microseconds / 100000.0;
    if (game.g.seconds > 1.0) {
        sfClock_restart(game.g.clock);
        game.g.compt = (game.g.compt) ? game.g.compt - 1 : 0;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && !game.g.compt) {
        my_gun_song(game);
        game.g.compt = 10;
        for (int i = 0; i < game.i; i++) {
            game.h.compt += my_shoot(game.b[i], game.w);
            game.b[i].death = (my_shoot(game.b[i], \
            game.w)) ? 2 : game.b[i].death;
        }
    }
    game = player_heart(game);
    put_bird(game);
    game = my_gun_hand(game);
    return (spawn_bird(game));
}

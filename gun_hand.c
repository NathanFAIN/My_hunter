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

void put_gun(game_t game)
{
    if (game.g.compt == 9) {
        game.g.pos_exp.x = sfMouse_getPositionRenderWindow(game.w).x - 100;
        sfSprite_setTexture(game.g.spr_exp, game.g.text_exp, sfTrue);
        sfSprite_setPosition(game.g.spr_exp, game.g.pos_exp);
        sfRenderWindow_drawSprite(game.w, game.g.spr_exp, NULL);
    }
    sfSprite_setTexture(game.g.sprite, game.g.texture, sfTrue);
    sfSprite_setTextureRect(game.g.sprite, game.g.rect);
    sfSprite_setPosition(game.g.sprite, game.g.position);
    sfRenderWindow_drawSprite(game.w, game.g.sprite, NULL);
}

int my_le_gun(int left, int compt)
{
    left = (compt == 2) ? 0 : left;
    left = (compt == 3) ? 130 : left;
    left = (compt == 4) ? 295 : left;
    left = (compt == 5) ? 460 : left;
    left = (compt == 6) ? 615 : left;
    left = (compt == 7) ? 460 : left;
    left = (compt == 8) ? 295 : left;
    left = (compt == 9) ? 130 : left;
    return (left);
}

int my_wi_gun(int left, int compt)
{
    left = (compt == 2) ? 130 : left;
    left = (compt == 3) ? 150 : left;
    left = (compt == 4) ? 165 : left;
    left = (compt == 5) ? 155 : left;
    left = (compt == 6) ? 145 : left;
    left = (compt == 7) ? 155 : left;
    left = (compt == 8) ? 165 : left;
    left = (compt == 9) ? 150 : left;
    return (left);
}

game_t my_gun_hand(game_t game)
{
    if (game.g.seconds > 1.0) {
        game.g.rect.left = my_le_gun(game.g.rect.left, game.g.compt);
        game.g.rect.width = my_wi_gun(game.g.rect.width, game.g.compt);
    }
    game.g.position.x = sfMouse_getPositionRenderWindow(game.w).x - 20;
    if (sfKeyboard_isKeyPressed(sfKeyC))
        game.i = game.bird;
    put_gun(game);
    return (game);
}

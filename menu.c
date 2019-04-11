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
#include "struct.h"
#include "my.h"

obj_menu_t create_menu(obj_menu_t menu)
{
    menu.position.x = 370;
    menu.position.y = 400;
    menu.pos_text.x = 1200;
    menu.pos_text.y = 0;
    menu.pos_logo.x = 0;
    menu.pos_logo.y = -20;
    menu.spr_logo = sfSprite_create();
    menu.spr_b1 = sfSprite_create();
    menu.text = sfTexture_createFromFile("resource/picture/play.png", NULL);
    menu.text2 = sfTexture_createFromFile("resource/picture/replay.png", NULL);
    menu.text3 = sfTexture_createFromFile("resource/picture/logo.png", NULL);
    menu.txt = sfText_create();
    sfText_setFont(menu.txt, sfFont_createFromFile("resource/picture/sc.ttf"));
    sfText_setColor(menu.txt, sfWhite);
    sfText_setCharacterSize(menu.txt, 100);
    sfSprite_setTexture(menu.spr_b1, menu.text, sfTrue);
    sfSprite_setTexture(menu.spr_logo, menu.text3, sfTrue);
    sfSprite_setPosition(menu.spr_logo, menu.pos_logo);
    menu.score = give_score();
    return (menu);
}

void menu(game_t game)
{
    int loop = 1;

    while (loop && sfRenderWindow_isOpen(game.w)) {
        my_draw_window(game);
        sfSprite_setTexture(game.m.spr_b1, game.m.text, sfTrue);
        sfSprite_setPosition(game.m.spr_b1, game.m.position);
        sfRenderWindow_drawSprite(game.w, game.m.spr_b1, NULL);
        sfRenderWindow_drawSprite(game.w, game.m.spr_logo, NULL);
        sfText_setString(game.m.txt, game.m.score);
        sfText_setPosition(game.m.txt, game.m.pos_text);
        sfRenderWindow_drawText(game.w, game.m.txt, NULL);
        loop = (sfKeyboard_isKeyPressed(sfKeyEscape)) ? 0 : loop;
        while (sfMouse_isButtonPressed(sfMouseLeft) && \
        sfMouse_getPositionRenderWindow(game.w).x > 370 && \
        sfMouse_getPositionRenderWindow(game.w).x < 988 && \
        sfMouse_getPositionRenderWindow(game.w).y > 400 && \
        sfMouse_getPositionRenderWindow(game.w).y < 555)
            loop = 0;
    }
    sfRenderWindow_setMouseCursorVisible(game.w, 0);
}

game_t recreate_game(game_t game)
{
    game.loop = 0;
    game.m = create_menu(game.m);
    game.game = 1;
    game.i = 1;
    game.bird = 100;
    game.b = malloc(sizeof(obj_bird_t) * game.bird);
    for (int i = 0; i < game.bird; i++)
        game.b[i] = create_bird(game.b[i]);
    game.g = create_gun(game.g);
    game.h = create_heart(game.h);
    game.text = sfTexture_createFromFile("resource/picture/foest.jpg", NULL);
    game.sprite = sfSprite_create();
    sfSprite_setTexture(game.sprite, game.text, sfTrue);
    game.cursorSpr = sfSprite_create();
    sfSprite_setTexture(game.cursorSpr, sfTexture_createFromFile(\
        "resource/picture/cursor.png", NULL), sfTrue);
    return (game);
}

void put_replay(game_t game)
{
    my_draw_window(game);
    sfSprite_setPosition(game.m.spr_b1, game.m.position);
    sfRenderWindow_drawSprite(game.w, game.m.spr_b1, NULL);
    sfText_setPosition(game.m.txt, game.m.pos_text);
    sfRenderWindow_drawText(game.w, game.m.txt, NULL);
}

game_t my_replay(game_t game)
{
    if (!game.game) {
        sfText_setString(game.m.txt, my_get_score(game.h.compt));
        sfRenderWindow_setMouseCursorVisible(game.w, 1);
        sfSprite_setTexture(game.m.spr_b1, game.m.text2, sfTrue);
    }
    while (!game.game && sfRenderWindow_isOpen(game.w)) {
        put_replay(game);
        game.game = (sfKeyboard_isKeyPressed(sfKeyEscape)) ? 1 : game.game;
        while (sfMouse_isButtonPressed(sfMouseLeft) && \
        sfMouse_getPositionRenderWindow(game.w).x > game.m.position.x && \
        sfMouse_getPositionRenderWindow(game.w).x < game.m.position.x + 618 && \
        sfMouse_getPositionRenderWindow(game.w).y > game.m.position.y && \
        sfMouse_getPositionRenderWindow(game.w).y < game.m.position.y + 155) {
            game.game = 1;
            game = recreate_game(game);
        }
    }
    sfRenderWindow_setMouseCursorVisible(game.w, 0);
    game = my_pause(game);
    return (game);
}

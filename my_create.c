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

obj_bird_t create_bird(obj_bird_t bird)
{
    bird.death = 3;
    bird.clock = sfClock_create();
    bird.seconds = 0;
    bird.compt = 0;
    bird.heart = 1;
    (bird.rect).height = 110;
    (bird.rect).width = 100;
    (bird.rect).top = 0;
    (bird.rect).left = 110;
    (bird.position).x = -110 - (rand() % 500 + 20);
    (bird.position).y = rand() % 300 + 20;
    bird.sprite = sfSprite_create();
    bird.texture = sfTexture_createFromFile("resource/picture/bird.png", NULL);
    sfSprite_setTexture(bird.sprite, bird.texture, sfTrue);
    return (bird);
}

obj_gun_t create_gun(obj_gun_t gun)
{
    gun.clock = sfClock_create();
    gun.seconds = 0;
    gun.compt = 0;
    (gun.rect).height = 174;
    (gun.rect).width = 130;
    (gun.rect).top = 0;
    (gun.rect).left = 0;
    (gun.position).x = 1000;
    (gun.position).y = 650;
    gun.sprite = sfSprite_create();
    gun.texture = sfTexture_createFromFile("resource/picture/gun.png", NULL);
    sfSprite_setTexture(gun.sprite, gun.texture, sfTrue);
    (gun.pos_exp).y = 600;
    gun.spr_exp = sfSprite_create();
    gun.text_exp = sfTexture_createFromFile("resource/picture/exp.png", NULL);
    sfSprite_setTexture(gun.spr_exp, gun.text_exp, sfTrue);
    return (gun);
}

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    srand(time(NULL));
    video_mode.width = 1380;
    video_mode.height = 820;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "Hunter", sfClose | \
    sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 50);
    sfRenderWindow_setIcon(window, 100, 100, \
    sfImage_getPixelsPtr(sfImage_createFromFile("resource/picture/icon.png")));
    return (window);
}

obj_heart_t create_heart(obj_heart_t heart)
{
    heart.compt = 0;
    heart.heart = 3;
    (heart.rect).height = 18;
    (heart.rect).width = 46;
    (heart.rect).top = 50;
    (heart.rect).left = 0;
    (heart.position).x = 1300;
    (heart.position).y = 20;
    heart.sprite = sfSprite_create();
    heart.text = sfTexture_createFromFile("resource/picture/heart.png", NULL);
    heart.txt = sfText_create();
    sfText_setFont(heart.txt, \
        sfFont_createFromFile("resource/picture/sc.ttf"));
    sfText_setColor(heart.txt, sfWhite);
    sfText_setCharacterSize(heart.txt, 30);
    heart.gun1 = sfMusic_createFromFile("resource/song/gun1.ogg");
    heart.gun2 = sfMusic_createFromFile("resource/song/gun2.ogg");
    return (heart);
}

game_t create_game(game_t game)
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
    game.w = create_window();
    game.h = create_heart(game.h);
    game.text = sfTexture_createFromFile("resource/picture/foest.jpg", NULL);
    game.sprite = sfSprite_create();
    sfSprite_setTexture(game.sprite, game.text, sfTrue);
    game.cursorSpr = sfSprite_create();
    sfSprite_setTexture(game.cursorSpr, sfTexture_createFromFile(\
        "resource/picture/cursor.png", NULL), sfTrue);
    return (game);
}

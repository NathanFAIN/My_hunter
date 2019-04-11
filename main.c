/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** main.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <time.h>
#include "my.h"
#include "struct.h"

void my_destroy(game_t game) {
    sfMusic_stop (game.h.gun1);
    for (int i = 0; i < game.i; i++) {
        sfClock_destroy(game.b[i].clock);
        sfSprite_destroy(game.b[i].sprite);
        sfTexture_destroy(game.b[i].texture);
    }
    sfClock_destroy(game.g.clock);
    sfSprite_destroy(game.g.sprite);
    sfTexture_destroy(game.g.text_exp);
    sfSprite_destroy(game.g.spr_exp);
    sfTexture_destroy(game.g.texture);
    sfSprite_destroy(game.h.sprite);
    sfTexture_destroy(game.h.text);
    sfText_destroy(game.h.txt);
    sfTexture_destroy(game.text);
    sfSprite_destroy(game.sprite);
    sfSprite_destroy(game.cursorSpr);
    sfMusic_destroy(game.h.gun2);
    sfMusic_destroy(game.h.gun1);
    sfRenderWindow_destroy(game.w);
}

int my_put_h(void)
{
    write(1, "Hunter: It's a video game based on the skills and shooting", 59);
    write(1, " accuracy.\n", 11);
    write(1, "        Presses on [ESC] to leave the game.\n", 44);
    write(1, "        Presses on [SPACE] to pause.\n", 37);
    write(1, "        Use [RIGHT CLICK] to shoot.\n", 36);
    return (0);
}

int main(int ac, char *av[])
{
    game_t game;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return (my_put_h());
    if (ac != 1)
        return (84);
    game = create_game();
    menu(game);
    while (sfRenderWindow_isOpen(game.w)) {
        my_draw_window(game);
        game = my_gun(game);
        game = my_bird(game);
        put_text(game);
        my_cursor(game);
        game = my_replay(game);
    }
    sfMusic_stop (game.h.gun2);
    my_score(game);
    my_destroy(game);
    return (0);
}

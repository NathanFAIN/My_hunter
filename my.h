/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** lib
*/

#include "struct.h"
#ifndef MY_H_
#define MY_H_

obj_bird_t my_death_bird(obj_bird_t bird);

game_t recreate_game(game_t game);

game_t my_pause(game_t game);

void put_gun(game_t game);

void put_bird(game_t game);

char *my_get_score(int nb);

game_t my_replay(game_t game);

void my_destroy(game_t game);

char *give_score();

void menu(game_t game);

game_t spawn_bird(game_t game);

void my_score(game_t game);

int my_put_nbr(int nb, int fd);

int my_getnbr(char const *str);

obj_bird_t create_bird(obj_bird_t bird);

obj_heart_t create_heart(obj_heart_t heart);

obj_gun_t create_gun();

obj_gun_t create_gun(obj_gun_t gun);

obj_bird_t create_bird(obj_bird_t bird);

obj_menu_t create_menu(obj_menu_t menu);

game_t player_heart(game_t game);

obj_bird_t recreate_bird(obj_bird_t old);

game_t my_gun_hand(game_t game);

sfRenderWindow *create_window(void);

game_t create_game();

game_t re_game(obj_bird_t b, obj_gun_t g, sfRenderWindow *w);

void put_bird(game_t game);

void put_heart(game_t game);

void put_text(game_t game);

void my_cursor(game_t game);

game_t my_bird(game_t game);

void my_draw_window(game_t game);

game_t my_gun(game_t game);

#endif /* MY_H_ */

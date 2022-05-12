##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile lib with project
##

SRC	=	sources/game/main_rpg.c	\
		sources/game/file_in_str.c	\
		sources/game/check_colli.c	\
		sources/game/create_text_rect_vect.c	\
		sources/menu/button_sprite.c	\
		sources/menu/button.c	\
		sources/menu/create_destroy_music.c	\
		sources/menu/frame_rate.c	\
		sources/menu/info_button.c	\
		sources/menu/menu_rpg.c	\
		sources/menu/menu.c	\
		sources/menu/settings.c	\
		sources/menu/sound_volume.c	\
		sources/menu/add_text_button_game.c	\
		sources/map/get_arr_sizes.c 		\
		sources/map/map_creator.c 			\
		sources/map/map_struct.c 			\
		sources/map/map_textures.c 			\
		sources/map/wall_textures.c 		\
		sources/map/dialogs.c 				\
		sources/map/map_destroyer.c 		\
		sources/game/francois_super_code/francois_super_code.c	\
		sources/game/francois_super_code/loop_display.c	\
		sources/game/francois_super_code/loop_events.c	\
		sources/game/francois_super_code/create_assets.c	\
		sources/game/francois_super_code/animate_player.c	\
		sources/game/francois_super_code/move_player.c	\
		sources/enemies/enemies.c	\
		sources/enemies/draw_enemies.c	\
		sources/fight/fight.c	\
		sources/fight/buttons.c	\
		sources/fight/character.c	\
		sources/fight/health.c	\
		sources/fight/attack.c	\
		sources/fight/enemy.c	\
		sources/fight/create_item.c	\
		sources/fight/create_attack.c	\
		sources/fight/manage_clock_fight.c	\
		sources/fight/display_fight.c	\
		sources/fight/event_fight.c	\
		sources/fight/attack_event.c 	\
		sources/enemies/rand_int.c	\
		sources/enemies/colli_enemies.c	\
		sources/game/francois_super_code/calc_error.c	\
		sources/game/francois_super_code/create_text_nb.c	\
		sources/game/francois_super_code/create_status.c	\
		sources/game/francois_super_code/destroy_text_nb.c	\
		sources/game/francois_super_code/event_status.c	\
		sources/game/francois_super_code/clear_save.c	\
		sources/game/francois_super_code/get_file_data.c	\
		sources/game/francois_super_code/read_file.c	\
		sources/enemies/create_pnj.c	\
		sources/enemies/draw_pnj.c	\
		sources/enemies/move_pnj.c	\
		sources/enemies/new_lvl.c	\
		sources/enemies/kill_an_enemy.c	\
		sources/logic/quests.c 			\
		sources/game/francois_super_code/save_data.c	\
		sources/game/francois_super_code/load_save.c	\
		sources/game/francois_super_code/manage_key.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CPPFLAGS	=	-I./include/

LDFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C libmy
	gcc $(OBJ) -L libmy/ -o $(NAME) -lmy $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	make clean -C libmy

fclean:	clean
	$(RM) $(NAME)
	make fclean -C libmy

re:	fclean all

tests_run:
	make
	./tests/mytest.sh

debug:		$(OBJ)
	make -C libmy
	gcc $(OBJ) -L libmy/ -o $(NAME) -lmy $(LDFLAGS) -Wall -Wextra -g3

.PHONY : all clean fclean re tests_run debug

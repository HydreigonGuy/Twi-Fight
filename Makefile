##
## Twi-Fight
##
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/next_scene.c	\
		src/error_handeling/handle_errors.c	\
		src/fill_structs/fill_game.c	\
		src/fill_structs/fill_mouse.c	\
		src/fill_structs/fill_game_time.c	\
		src/fill_structs/fill_sprite.c	\
		src/fill_structs/fill_background.c	\
		src/fill_structs/fill_btn.c	\
		src/fill_structs/fill_game_info.c	\
		src/fill_structs/fill_tower.c	\
		src/free_structs/free_game.c	\
		src/free_structs/free_game_time.c	\
		src/free_structs/free_sprite.c	\
		src/free_structs/free_scene.c	\
		src/free_structs/free_game_info.c	\
		src/rect_handeling/fill_rect.c	\
		src/rect_handeling/rerect_sprites.c	\
		src/rect_handeling/calculate_rect_number.c	\
		src/events/handle_events.c	\
		src/mouse/mouse_check.c	\
		src/mouse/mouse_on_button.c	\
		src/mouse/mouse_pressed_button.c	\
		src/mouse/mouse_released_on_button.c	\
		src/mouse/mouse_reset.c	\
		src/handle_placing_towers/handle_placing_towers.c	\
		src/handle_placing_towers/highlignt_selected_tower_btn.c	\
		src/handle_placing_towers/handle_selecting_tower.c	\
		src/handle_placing_towers/add_tower.c	\
		src/start_menu/start_menu.c	\
		src/start_menu/fill_start_menu_scene.c	\
		src/start_menu/display_start_menu.c	\
		src/start_menu/change_start_menu_game_state.c	\
		src/play_game/play_game.c	\
		src/play_game/display_play_game.c	\
		src/play_game/fill_play_game_scene.c	\
		adrien_lib/my_str_concat.c	\
		adrien_lib/my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	game

CFLAGS	=	-I include -l csfml-graphics -l csfml-system -l csfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

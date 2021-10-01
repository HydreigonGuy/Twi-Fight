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
		src/fill_structs/fill_enemy.c	\
		src/fill_structs/fill_attack.c	\
		src/fill_structs/attack_parameters/get_attack_size.c	\
		src/fill_structs/attack_parameters/get_attack_sprite.c	\
		src/fill_structs/tower_parameters/get_tower_atk.c	\
		src/fill_structs/tower_parameters/get_tower_max_cd.c	\
		src/fill_structs/tower_parameters/get_tower_path.c	\
		src/fill_structs/tower_parameters/get_tower_spd.c	\
		src/free_structs/free_game.c	\
		src/free_structs/free_game_time.c	\
		src/free_structs/free_sprite.c	\
		src/free_structs/free_scene.c	\
		src/free_structs/free_game_info.c	\
		src/free_structs/free_all_attacks.c	\
		src/free_structs/free_all_enemies.c	\
		src/free_structs/free_all_towers.c	\
		src/free_structs/free_one_attack.c	\
		src/free_structs/free_one_enemy.c	\
		src/rect_handeling/fill_rect.c	\
		src/rect_handeling/rerect_sprites.c	\
		src/rect_handeling/calculate_rect_number.c	\
		src/events/handle_events.c	\
		src/events/handle_ingame_events.c	\
		src/mouse/mouse_check.c	\
		src/mouse/mouse_on_button.c	\
		src/mouse/mouse_pressed_button.c	\
		src/mouse/mouse_released_on_button.c	\
		src/mouse/mouse_reset.c	\
		src/handle_placing_towers/handle_placing_towers.c	\
		src/handle_placing_towers/highlignt_selected_tower_btn.c	\
		src/handle_placing_towers/handle_selecting_tower.c	\
		src/handle_placing_towers/add_tower.c	\
		src/handle_placing_towers/check_if_can_place_tower.c	\
		src/handle_enemies/handle_enemies.c	\
		src/handle_enemies/spawn_enemies.c	\
		src/handle_enemies/spawn_enemy.c	\
		src/handle_enemies/move_enemies.c	\
		src/handle_enemies/fill_enemy_dialog.c	\
		src/handle_game_time/reset_game_time.c	\
		src/handle_game_time/update_clock.c	\
		src/handle_tower_attacks/handle_tower_attacks.c	\
		src/handle_tower_attacks/create_tower_attacks.c	\
		src/handle_tower_attacks/add_one_attack.c	\
		src/handle_tower_attacks/get_next_atk_crds.c	\
		src/handle_tower_attacks/remove_excess_attacks.c	\
		src/handle_tower_attacks/out_of_bounds.c	\
		src/handle_tower_attacks/find_furthest_enemy_x.c	\
		src/handle_tower_attacks/handle_atk_enemy_collision.c	\
		src/handle_tower_attacks/check_for_atk_colision.c	\
		src/start_menu/start_menu.c	\
		src/start_menu/fill_start_menu_scene.c	\
		src/start_menu/display_start_menu.c	\
		src/start_menu/change_start_menu_game_state.c	\
		src/play_game/play_game.c	\
		src/play_game/display_play_game.c	\
		src/play_game/fill_play_game_scene.c	\
		adrien_lib/my_square_root.c	\
		adrien_lib/my_vector_norm.c	\
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

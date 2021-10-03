/*
** EPITECH PROJECT, 2021
** 
** File description:
** game_structs
*/

#ifndef GAME_STRUCTS_H_
    #define GAME_STRUCTS_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>

    typedef struct sprite_s {
        sfTexture *txtr;
        sfSprite *spr;
        sfIntRect r;
        sfVector2f crds;
    } sprite_t;

    typedef struct button_s {
        sprite_t *spr;
        int state;
        struct button_s *next;
    } button_t;

    typedef struct background_s {
        sprite_t *spr;
        struct background_s *next;
        int x;
        int y;
    } background_t;

    typedef struct scene_s {
        background_t *bg;
        button_t *btn;
    } scene_t;

    typedef struct mouse_s{
        int x; // current coordonates
        int y;
        int p_x; // pressed coordonates
        int p_y;
        int r_x; // releassed coordonates
        int r_y;
    } mouse_t;

    typedef struct sound_s {
        sfSoundBuffer *buff;
        sfSound *sound;
        int id;
        struct sound_s *next;
    } sound_t;

    typedef struct extra_events_s {
        int space_bar_press;
    } extra_events_t;

    typedef struct music_s {
        sfMusic *music;
        int id;
        struct music_s *next;
    } music_t;

    typedef struct music_group_s {
        music_t *music;
        sound_t *sound;
        int volume;
        int music_playing;
        int sound_playing;
    } music_group_t;

    typedef struct game_time_s {
        sfClock *clock;
        sfTime time;
        int time_elapsed;
    } game_time_t;

    typedef struct game_s {
        mouse_t *mouse;
        music_group_t *music;
        sfRenderWindow *window;
        game_time_t *clock;
        int state;
    } game_t;

    typedef struct tower_s {
        sprite_t *spr;
        int id;
        int atk;
        int spd;
        int cooldown;
        int max_cooldown;
        struct tower_s *next;
    } tower_t;

    typedef struct enemy_s {
        sprite_t *spr;
        int hp;
        int spd;
        struct enemy_s *next;
    } enemy_t;

    typedef struct attack_s {
        sprite_t *spr;
        int id;
        int atk;
        int spd;
        int direction;
        struct attack_s *next;
    } attack_t;

    typedef struct wolf_btn_s {
        sprite_t *cd_spr;
        int cooldown;
        int last_shake;
        int shake_x;
        int reset_shake;
        int shake_y;
    } wolf_btn_t;

    typedef struct playing_s {
        int tower_selected;
        sprite_t **dialog;
        tower_t *tower;
        enemy_t *enemy;
        attack_t *atk;
        wolf_btn_t *wolf_btn;
        int spawn_var;
    } playing_t;

    #define FRAME_RATE  30
    #define WINDOW_NAME "Game"

    #define IMAGE_PATH  "assets/images/"

    #define ENEMY_SEPARATION    150
    #define ENEMY_Y             200

    #define ENEMY_COLLISION_TOLERENCE   15

    #define ENEMY_SPD_LIMITTER      50000
    #define ATTACK_SPD_LIMITTER     40000
    #define TOWER_CD_LIMITTER       30000

    // wolf button
    #define WOLF_BTN_CD         200
    #define MAP_SHAKE_TIME      30
    #define TIME_BETWEEN_SHAKES 3
    #define SHAKE_PIXEL_LIMIT   60

    // game states
    #define GAME_STATE_EXIT         -3
    #define GAME_STATE_START_MENU   1
    #define GAME_STATE_PLAY_GAME    2

    // error handeling
    int handle_errors(void);

    // fill structs
    game_t *fill_game(void);
    mouse_t *fill_mouse(void);
    game_time_t *fill_game_time(void);
    sprite_t *fill_sprite(char *file, int setx, int sety);
    void fill_background(background_t **bg, char *file, int x, int y);
    void fill_btn(button_t **btn, char *file, int x, int y);
    playing_t *fill_game_info(void);
    tower_t *fill_tower(int selected, int x, int y);
    enemy_t *fill_enemy(int id, int x);
    attack_t *fill_attack(tower_t *tower);
    wolf_btn_t *fill_wolf_btn(void);

    // attack parameters
    int get_attack_size(int id);
    char *get_attack_sprite(int id);

    // tower parameters
    int get_tower_spd(int i);
    char *get_tower_path(int i);
    int get_tower_max_cd(int i);
    int get_tower_atk(int i);

    // free structs
    void free_game(game_t *game);
    void free_game_time(game_time_t *clock);
    void free_sprite(sprite_t *spr);
    void free_scene(scene_t *scene);
    void free_game_info(playing_t *game_info);
    void free_all_attacks(attack_t *atk);
    void free_all_towers(tower_t *tower);
    void free_all_enemies(enemy_t *enemy);
    void free_one_attack(playing_t *game_info, attack_t *atk);
    void free_one_enemy(playing_t *game_info, enemy_t *enm);

    // next scene
    void next_scene(game_t *game);

    // mouse
    void mouse_check(button_t *btn, game_t *game);
    int mouse_on_button(mouse_t *m, button_t *btn);
    int mouse_pressed_button(mouse_t *m, button_t *btn);
    int mouse_released_on_button(mouse_t *m, button_t *btn);
    void mouse_reset(mouse_t *mouse);

    // rect handeling
    void fill_rect(sprite_t *spr, int x, int y);
    void rerect_sprites(sprite_t *spr, int rect_number);
    int calculate_rect_number(sfTime time);

    // event handeling
    extra_events_t handle_events(game_t *game);
    void handle_ingame_events(extra_events_t event, playing_t *game_info);

    // handle_placing_towers
    void handle_placing_towers(game_t *game, playing_t *game_info, button_t *btn);
    void highlignt_selected_tower_btn(int selected, button_t *btn);
    void handle_selecting_tower(int *state, playing_t *game_info);
    void add_tower(playing_t *game_info, int x, int y);
    int check_if_can_place_tower(mouse_t *mouse);

    // handle enemies
    void handle_enemies(int clock, playing_t *game_info);
    void spawn_enemies(playing_t *gi);
    void spawn_enemy(int id, int x, enemy_t **enemy);
    void move_enemies(int clock, playing_t *game_info);
    void fill_enemy_dialog(playing_t *game_info);

    // handle_game_time
    void reset_game_time(game_time_t *clock);
    void update_clock(game_time_t *clock);

    // handle tower attacks
    void handle_tower_attacks(game_t *game, playing_t *game_info);
    void create_tower_attacks(playing_t *game_info);
    void add_one_attack(attack_t **atk, tower_t *tower);
    void get_next_atk_crds(attack_t *atk, int e_time, int enemy_x);
    void remove_excess_attacks(attack_t **atk);
    int out_of_bounds(sprite_t *spr);
    int find_furthest_enemy_x(enemy_t *enemy);
    void handle_atk_enemy_collision(playing_t *game_info);
    int check_for_atk_colision(playing_t *gi, attack_t *attk, enemy_t *enmy);
    void handle_wolf_btn_press(mouse_t *mouse, playing_t *game_info, int time);
    void handle_wolf_map_shake(wolf_btn_t *btn, int time);

    //////////////////// scenes ////////////////////

    // start menu
    void start_menu(game_t *game);
    scene_t *fill_start_menu_scene(void);
    void display_start_menu(sfRenderWindow *window, scene_t *scene);
    void change_start_menu_game_state(game_t *game);

    // play game
    void play_game(game_t *game);
    scene_t *fill_play_game_scene(void);
    void display_play_game(sfRenderWindow *wdw, game_time_t *clk, scene_t *scn, playing_t *gi);
    void handle_map_shaking(playing_t *gi, scene_t *scn);

#endif /* !GAME_STRUCTS_H_ */

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
        int atk;
        int cooldown;
        int max_cooldown;
        struct tower_s *next;
    } tower_t;

    typedef struct playing_s {
        int tower_selected;
        tower_t *tower;
    } playing_t;

    #define FRAME_RATE  30
    #define WINDOW_NAME "Game"

    #define IMAGE_PATH  "assets/images/"

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

    // free structs
    void free_game(game_t *game);
    void free_game_time(game_time_t *clock);
    void free_sprite(sprite_t *spr);
    void free_scene(scene_t *scene);
    void free_game_info(playing_t *game_info);

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

    // event handeling
    void handle_events(game_t *game);

    // handle_placing_towers
    void handle_placing_towers(game_t *game, playing_t *game_info, button_t *btn);
    void highlignt_selected_tower_btn(int selected, button_t *btn);
    void handle_selecting_tower(int *state, playing_t *game_info);
    void add_tower(playing_t *game_info, int x, int y);

    //////////////////// scenes ////////////////////

    // start menu
    void start_menu(game_t *game);
    scene_t *fill_start_menu_scene(void);
    void display_start_menu(sfRenderWindow *window, scene_t *scene);
    void change_start_menu_game_state(game_t *game);

    // play game
    void play_game(game_t *game);
    scene_t *fill_play_game_scene(void);
    void display_play_game(sfRenderWindow *window, scene_t *scene, playing_t *gi);

#endif /* !GAME_STRUCTS_H_ */

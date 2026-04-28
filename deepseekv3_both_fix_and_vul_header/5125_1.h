#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef int Bool;
typedef unsigned long long u64;
typedef long long s64;
typedef unsigned int u32;

typedef struct {
    int type;
    union {
        struct {
            int key_code;
            int flags;
        } key;
        struct {
            int button;
            int x, y;
        } mouse;
        struct {
            int x, y;
            int relative;
            int align_x, align_y;
        } move;
        struct {
            int width, height;
        } size;
        struct {
            char *service;
            char *message;
            int error;
        } message;
        struct {
            double duration;
            Bool can_seek;
        } duration;
        struct {
            int progress_type;
            u32 done, total;
        } progress;
        struct {
            char *to_url;
        } navigate;
        struct {
            char *site_url;
            char *user;
            char *password;
        } auth;
        struct {
            int nb_files;
            char **files;
        } open_file;
        struct {
            Bool is_connected;
        } connect;
        struct {
            char *addon_url;
        } addon_connect;
    };
} GF_Event;

#define GF_EVENT_QUIT 1
#define GF_EVENT_KEYDOWN 2
#define GF_EVENT_KEYUP 3
#define GF_EVENT_MOUSEDOWN 4
#define GF_EVENT_MOUSEUP 5
#define GF_EVENT_MOUSEMOVE 6
#define GF_EVENT_DBLCLICK 7
#define GF_EVENT_MESSAGE 8
#define GF_EVENT_PROGRESS 9
#define GF_EVENT_DURATION 10
#define GF_EVENT_CONNECT 11
#define GF_EVENT_EOS 12
#define GF_EVENT_SIZE 13
#define GF_EVENT_SCENE_SIZE 14
#define GF_EVENT_METADATA 15
#define GF_EVENT_RELOAD 16
#define GF_EVENT_DROPFILE 17
#define GF_EVENT_DISCONNECT 18
#define GF_EVENT_MIGRATE 19
#define GF_EVENT_NAVIGATE_INFO 20
#define GF_EVENT_NAVIGATE 21
#define GF_EVENT_SET_CAPTION 22
#define GF_EVENT_AUTHORIZATION 23
#define GF_EVENT_ADDON_DETECTED 24
#define GF_EVENT_MOVE 25

#define GF_KEY_MOD_CTRL 1
#define GF_KEY_MOD_ALT 2
#define GF_KEY_MOD_SHIFT 4
#define VK_MOD 8

#define GF_MOUSE_RIGHT 2

#define GF_LOG_INFO 1
#define GF_LOG_ERROR 2
#define GF_LOG_CONSOLE 3

#define GF_SCRIPT_INFO 1

#define GF_TERM_WINDOWLESS 1

#define GF_OPT_FULLSCREEN 1
#define GF_OPT_MAIN_ADDON 2
#define GF_OPT_PLAY_STATE 3
#define GF_OPT_DRAW_MODE 4
#define GF_OPT_ASPECT_RATIO 5
#define GF_OPT_MULTIVIEW_MODE 6

#define GF_STATE_PLAYING 1
#define GF_STATE_PAUSED 2
#define GF_STATE_PLAY_LIVE 3
#define GF_STATE_STEP_PAUSE 4

#define GF_DRAW_MODE_DEFER 1
#define GF_DRAW_MODE_IMMEDIATE 2

#define GF_ASPECT_RATIO_4_3 1
#define GF_ASPECT_RATIO_16_9 2
#define GF_ASPECT_RATIO_FILL_SCREEN 3
#define GF_ASPECT_RATIO_KEEP 4

#define GF_KEY_C 1
#define GF_KEY_SPACE 2
#define GF_KEY_PAGEDOWN 3
#define GF_KEY_MEDIANEXTTRACK 4
#define GF_KEY_MEDIAPREVIOUSTRACK 5
#define GF_KEY_ESCAPE 6
#define GF_KEY_F 7
#define GF_KEY_T 8
#define GF_KEY_D 9
#define GF_KEY_4 10
#define GF_KEY_5 11
#define GF_KEY_6 12
#define GF_KEY_7 13
#define GF_KEY_O 14
#define GF_KEY_P 15
#define GF_KEY_S 16
#define GF_KEY_B 17
#define GF_KEY_M 18
#define GF_KEY_H 19
#define GF_KEY_L 20
#define GF_KEY_F5 21
#define GF_KEY_A 22
#define GF_KEY_UP 23
#define GF_KEY_DOWN 24
#define GF_KEY_LEFT 25

#define FIX_ONE 1
#define GF_FALSE 0
#define GF_TRUE 1

extern void *term;
extern int gui_mode;
extern int Run;
extern int shell_visible;
extern u64 Duration;
extern Bool CanSeek;
extern char *the_url;
extern Bool is_connected;
extern int last_error;
extern int be_quiet;
extern int bench_mode;
extern int bench_buffer;
extern int right_down;
extern int last_x, last_y;
extern struct {
    int init_flags;
} user;
extern int align_mode;
extern int forced_width, forced_height;
extern int playback_speed;
extern int request_next_playlist_item;
extern FILE *playlist;
extern int readonly_playlist;
extern int loop_at_end;
extern int restart;
extern int reload;
extern int addon_visible;
extern int enable_add_ons;
extern int no_mime_check;
extern int eos_seen;
extern int init_w, init_h;

void hide_shell(int);
void gf_term_set_option(void *, int, int);
int gf_term_get_option(void *, int);
void gf_term_process_shortcut(void *, GF_Event *);
void gf_term_user_event(void *, GF_Event *);
void gf_term_set_size(void *, int, int);
void gf_term_disconnect(void *);
int gf_term_is_supported_url(void *, const char *, int, int);
void gf_term_navigate_to(void *, const char *);
void gf_set_progress(const char *, u32, u32);
void switch_bench(int);
void do_set_speed(int);
void gf_term_set_speed(void *, int);
void ResetCaption();
void ViewODs(void *, int);
void gf_term_switch_quality(void *, int);
void gf_term_toggle_addons(void *, int);
void PrintTime(u64);
const char *gf_error_to_string(int);
void GF_LOG(int, int, const char *, ...);
void read_line_input(char *, int, int);
FILE *gf_temp_file_new(const char *);
void gf_fclose(FILE *);
float gf_term_get_framerate(void *, int);
u64 gf_term_get_time_in_ms(void *);
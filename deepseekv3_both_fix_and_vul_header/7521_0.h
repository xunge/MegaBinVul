#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <poll.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stddef.h>

#define LOG_ERROR 0
#define LOG_DEBUG 1
#define LOG_INFO 2
#define XKB_CONTEXT_NO_FLAGS 0
#define EAGAIN 11
#define EXIT_FAILURE 1

enum line_mode {
    LM_LINE,
    LM_INSIDE,
    LM_RING
};

enum background_mode {
    BACKGROUND_MODE_FILL,
    BACKGROUND_MODE_CENTER,
    BACKGROUND_MODE_TILE,
    BACKGROUND_MODE_FIT,
    BACKGROUND_MODE_SOLID_COLOR
};

struct swaylock_colors {
    uint32_t background;
    uint32_t bs_highlight;
    uint32_t key_highlight;
    uint32_t caps_lock_bs_highlight;
    uint32_t caps_lock_key_highlight;
    uint32_t separator;
    uint32_t inside;
    uint32_t line;
    uint32_t ring;
    uint32_t text;
    uint32_t layout_text;
    uint32_t caps_lock_text;
};

struct swaylock_args {
    enum background_mode mode;
    char *font;
    int font_size;
    int radius;
    int thickness;
    int indicator_x_position;
    int indicator_y_position;
    bool override_indicator_x_position;
    bool override_indicator_y_position;
    bool ignore_empty;
    bool show_indicator;
    bool show_caps_lock_indicator;
    bool show_caps_lock_text;
    bool show_keyboard_layout;
    bool hide_keyboard_layout;
    bool show_failed_attempts;
    bool indicator_idle_visible;
    bool daemonize;
    struct swaylock_colors colors;
};

struct swaylock_password {
    char buffer[1024];
};

struct wl_list {
    struct wl_list *prev;
    struct wl_list *next;
};

struct swaylock_surface {
    struct wl_list link;
    void *output;
    void *xdg_output;
};

struct swaylock_state {
    struct swaylock_args args;
    struct swaylock_password password;
    int failed_attempts;
    struct wl_list images;
    struct wl_list surfaces;
    void *display;
    void *compositor;
    void *layer_shell;
    void *shm;
    void *input_inhibit_manager;
    void *zxdg_output_manager;
    void *ext_session_lock_manager_v1;
    void *ext_session_lock_v1;
    struct {
        void *context;
    } xkb;
    void *eventloop;
    bool run_display;
};

static struct swaylock_state state;

struct wl_registry_listener {
    void (*global)(void *data, void *registry, uint32_t name,
                  const char *interface, uint32_t version);
    void (*global_remove)(void *data, void *registry, uint32_t name);
};

struct zxdg_output_v1_listener {
    void (*logical_position)(void *data, void *zxdg_output_v1,
                            int32_t x, int32_t y);
    void (*logical_size)(void *data, void *zxdg_output_v1,
                        int32_t width, int32_t height);
    void (*done)(void *data, void *zxdg_output_v1);
    void (*name)(void *data, void *zxdg_output_v1, const char *name);
    void (*description)(void *data, void *zxdg_output_v1, const char *description);
};

struct ext_session_lock_v1_listener {
    void (*locked)(void *data, void *ext_session_lock_v1);
    void (*finished)(void *data, void *ext_session_lock_v1);
};

static struct wl_registry_listener registry_listener;
static struct zxdg_output_v1_listener _xdg_output_listener;
static struct ext_session_lock_v1_listener ext_session_lock_v1_listener;

void swaylock_log_init(int level);
void initialize_pw_backend(int argc, char **argv);
void wl_list_init(struct wl_list *list);
void set_default_colors(struct swaylock_colors *colors);
int parse_options(int argc, char **argv, void *state, enum line_mode *mode, char **config_path);
char *get_config_path(void);
void swaylock_log(int level, const char *fmt, ...);
int load_config(const char *path, struct swaylock_state *state, enum line_mode *mode);
void *xkb_context_new(uint32_t flags);
void *wl_display_connect(const char *name);
void *wl_display_get_registry(void *display);
void wl_registry_add_listener(void *registry, struct wl_registry_listener *listener, void *data);
int wl_display_roundtrip(void *display);
void zwlr_input_inhibit_manager_v1_get_inhibitor(void *manager);
void *zxdg_output_manager_v1_get_xdg_output(void *manager, void *output);
void zxdg_output_v1_add_listener(void *output, struct zxdg_output_v1_listener *listener, void *data);
void create_layer_surface(void *surface);
void create_surface(void *surface);
void daemonize(void);
void *loop_create(void);
void loop_add_fd(void *loop, int fd, int events, void (*callback)(void *), void *data);
int wl_display_get_fd(void *display);
int get_comm_reply_fd(void);
int wl_display_flush(void *display);
void loop_poll(void *loop);
void display_in(void *data);
void comm_in(void *data);
void ext_session_lock_v1_unlock_and_destroy(void *lock);

#define wl_list_for_each(pos, head, member) \
    for (pos = (struct swaylock_surface*)((char*)(head)->next - offsetof(struct swaylock_surface, member)); \
         &pos->member != (head); \
         pos = (struct swaylock_surface*)((char*)pos->member.next - offsetof(struct swaylock_surface, member)))
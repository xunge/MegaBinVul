#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct wl_registry;
struct wl_compositor;
struct wl_subcompositor;
struct wl_shm;
struct wl_seat;
struct wl_output;
struct wl_display;
struct zwlr_layer_shell_v1;
struct zwlr_input_inhibit_manager_v1;
struct zxdg_output_manager_v1;
struct ext_session_lock_manager_v1;

struct wl_list {
    struct wl_list *prev;
    struct wl_list *next;
};

struct wl_interface {
    const char *name;
    int version;
};

extern struct wl_interface wl_compositor_interface;
extern struct wl_interface wl_subcompositor_interface;
extern struct wl_interface wl_shm_interface;
extern struct wl_interface wl_seat_interface;
extern struct wl_interface wl_output_interface;
extern struct wl_interface zwlr_layer_shell_v1_interface;
extern struct wl_interface zwlr_input_inhibit_manager_v1_interface;
extern struct wl_interface zxdg_output_manager_v1_interface;
extern struct wl_interface ext_session_lock_manager_v1_interface;

struct swaylock_state {
    struct wl_compositor *compositor;
    struct wl_subcompositor *subcompositor;
    struct wl_shm *shm;
    struct wl_seat *seat;
    struct zwlr_layer_shell_v1 *layer_shell;
    struct zwlr_input_inhibit_manager_v1 *input_inhibit_manager;
    struct zxdg_output_manager_v1 *zxdg_output_manager;
    struct ext_session_lock_manager_v1 *ext_session_lock_manager_v1;
    struct wl_display *display;
    bool run_display;
    struct wl_list surfaces;
};

struct swaylock_seat {
    struct swaylock_state *state;
};

struct swaylock_surface {
    struct swaylock_state *state;
    struct wl_output *output;
    uint32_t output_global_name;
    struct wl_list link;
};

extern const struct wl_seat_listener seat_listener;
extern const struct wl_output_listener _wl_output_listener;

void *wl_registry_bind(struct wl_registry *registry, uint32_t name, const struct wl_interface *interface, uint32_t version);
void wl_seat_add_listener(struct wl_seat *seat, const struct wl_seat_listener *listener, void *data);
void wl_output_add_listener(struct wl_output *output, const struct wl_output_listener *listener, void *data);
void wl_list_insert(struct wl_list *list, struct wl_list *elm);
void wl_display_roundtrip(struct wl_display *display);
void create_layer_surface(struct swaylock_surface *surface);
void create_surface(struct swaylock_surface *surface);
#include <stdlib.h>

struct wl_list {
    struct wl_list *prev;
    struct wl_list *next;
};

struct buffer {
    void *data;
    size_t size;
};

struct zwlr_layer_surface_v1;
struct ext_session_lock_surface_v1;
struct wl_surface;
struct wl_output;

struct swaylock_surface {
    struct wl_list link;
    struct zwlr_layer_surface_v1 *layer_surface;
    struct ext_session_lock_surface_v1 *ext_session_lock_surface_v1;
    struct wl_surface *surface;
    struct wl_output *output;
    struct buffer buffers[2];
    struct buffer indicator_buffers[2];
};

void wl_list_remove(struct wl_list *list);
void zwlr_layer_surface_v1_destroy(struct zwlr_layer_surface_v1 *surface);
void ext_session_lock_surface_v1_destroy(struct ext_session_lock_surface_v1 *surface);
void wl_surface_destroy(struct wl_surface *surface);
void wl_output_destroy(struct wl_output *output);
void destroy_buffer(struct buffer *buffer);
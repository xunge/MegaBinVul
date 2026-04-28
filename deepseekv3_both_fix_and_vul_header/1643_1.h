#include <stdint.h>
#include <errno.h>
#include <stddef.h>

#define WL_SERVER_ID_START 0xff000000
#define WL_MAP_MAX_OBJECTS 0xffffffff
#define WL_MAP_CLIENT_SIDE 0
#define WL_MAP_SERVER_SIDE 1

struct wl_array {
    size_t size;
    size_t alloc;
    void *data;
};

struct wl_map {
    int side;
    struct wl_array client_entries;
    struct wl_array server_entries;
};

union map_entry {
    void *data;
};

int wl_array_add(struct wl_array *array, size_t size);
#include <stdint.h>
#include <stddef.h>

struct wl_array {
    void *data;
};

struct wl_map {
    int side;
    struct wl_array client_entries;
    struct wl_array server_entries;
    uint32_t free_list;
};

union map_entry {
    void *data;
    uint32_t next;
};

#define WL_MAP_CLIENT_SIDE 0
#define WL_SERVER_ID_START 0
#define WL_MAP_MAX_OBJECTS 0

void *wl_array_add(struct wl_array *array, size_t size);
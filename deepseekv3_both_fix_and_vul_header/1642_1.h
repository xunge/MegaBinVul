#include <stdint.h>
#include <errno.h>
#include <stddef.h>

struct wl_array {
    size_t size;
    size_t alloc;
    void *data;
};

struct wl_map {
    struct wl_array client_entries;
    struct wl_array server_entries;
};

union map_entry {
    void *data;
    uint32_t next;
};

#define WL_SERVER_ID_START 0xff000000
#define WL_MAP_MAX_OBJECTS 0xfffffff

int wl_array_add(struct wl_array *array, size_t size);
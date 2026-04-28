#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct MemoryRegion MemoryRegion;
typedef struct Object Object;
typedef struct DeviceState DeviceState;

#define TYPE_DEVICE "device"
#define OBJECT(obj) ((Object *)(obj))

struct MemoryRegion {
    uint64_t size;
    char *name;
    Object *owner;
    DeviceState *dev;
    void *ram_block;
};

struct Object {
    // minimal definition
};

struct DeviceState {
    // minimal definition
};

static inline uint64_t int128_make64(uint64_t v) {
    return v;
}

static inline uint64_t int128_2_64(void) {
    return UINT64_MAX;
}

static char *memory_region_escape_name(const char *name) {
    char *escaped = malloc(strlen(name) + 1);
    strcpy(escaped, name);
    return escaped;
}

static char *g_strdup(const char *s) {
    return strdup(s);
}

static char *g_strdup_printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    char *buf;
    vasprintf(&buf, fmt, args);
    va_end(args);
    return buf;
}

static void g_free(void *ptr) {
    free(ptr);
}

static Object *container_get(Object *root, const char *path) {
    return NULL;
}

static Object *qdev_get_machine(void) {
    return NULL;
}

static void object_property_add_child(Object *parent, const char *name, Object *child) {
}

static void object_unref(Object *obj) {
}

static Object *object_dynamic_cast(Object *obj, const char *type) {
    return NULL;
}
#include <stdlib.h>
#include <stdint.h>

#define AUTH_END_INIT_OFFSET 0

typedef struct {
    void *client_side;
    void *bus_side;
    void *auth_buffer;
    void *rewrite_reply;
    void *get_owner_reply;
    void *unique_id_policy;
    uint32_t auth_end_offset;
} FlatpakProxyClient;

static void init_side(FlatpakProxyClient *client, void **side);

static uint32_t g_direct_hash(const void *v) { return (uintptr_t)v; }
static int g_direct_equal(const void *v1, const void *v2) { return v1 == v2; }
static uint32_t g_str_hash(const void *v) { return 0; }
static int g_str_equal(const void *v1, const void *v2) { return 0; }
static void g_object_unref(void *obj) {}
static void g_free(void *p) { free(p); }
static void *g_hash_table_new_full(uint32_t (*hash_func)(const void *),
                                  int (*key_equal_func)(const void *, const void *),
                                  void (*key_destroy_func)(void *),
                                  void (*value_destroy_func)(void *)) { return NULL; }
static void *g_byte_array_new(void) { return NULL; }
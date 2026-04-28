#include <stddef.h>
#include <stdio.h>

typedef char gchar;
typedef int gint;
typedef unsigned int guint;

#define ENC_ASCII 0
#define TVBPARSE_DEBUG 1
#define TVBPARSE_DEBUG_HASH 1
#define TVBPARSE_MAX_RECURSION_DEPTH 100

struct tvbuff_t;
typedef struct tvbuff_t tvbuff_t;

struct wmem_allocator_t;
typedef struct wmem_allocator_t wmem_allocator_t;

struct tvbparse_elem_t {
    int id;
    tvbuff_t* tvb;
    int offset;
    int len;
    struct tvbparse_elem_t* sub;
    struct tvbparse_elem_t* last;
    struct tvbparse_elem_t* next;
};
typedef struct tvbparse_elem_t tvbparse_elem_t;

struct tvbparse_wanted_t {
    struct {
        struct {
            struct tvbparse_wanted_t* key;
            void* table;
            struct tvbparse_wanted_t* other;
        } hash;
    } control;
    int (*condition)(void*, int, struct tvbparse_wanted_t*, tvbparse_elem_t**);
};
typedef struct tvbparse_wanted_t tvbparse_wanted_t;

struct tvbparse_t {
    int end_offset;
    int recursion_depth;
};
typedef struct tvbparse_t tvbparse_t;

extern gchar* tvb_get_string_enc(wmem_allocator_t *alloc, tvbuff_t *tvb, const gint offset, gint length, const guint encoding);
extern tvbparse_elem_t* new_tok(tvbparse_t* tt, int id, int offset, int len, const tvbparse_wanted_t* wanted);
extern void* wmem_map_lookup(void* table, const gchar* key);
extern wmem_allocator_t* wmem_packet_scope(void);
extern void g_warning(const char *format, ...);
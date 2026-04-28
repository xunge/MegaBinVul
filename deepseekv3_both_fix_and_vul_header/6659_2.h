#include <stdlib.h>
#include <string.h>

typedef char gchar;

typedef struct tvbparse_elem_t {
    int id;
    void* tvb;
    int offset;
    int len;
    struct tvbparse_elem_t* sub;
    struct tvbparse_elem_t* last;
    struct tvbparse_elem_t* next;
} tvbparse_elem_t;

typedef struct tvbparse_wanted_t {
    struct {
        struct {
            struct tvbparse_wanted_t* key;
            void* table;
            struct tvbparse_wanted_t* other;
        } hash;
    } control;
    int (*condition)(void*, int, struct tvbparse_wanted_t*, tvbparse_elem_t**);
} tvbparse_wanted_t;

typedef struct tvbparse_t {
    int end_offset;
    int recursion_depth;
} tvbparse_t;

#define TVBPARSE_DEBUG 0
#define TVBPARSE_DEBUG_HASH 0
#define TVBPARSE_MAX_RECURSION_DEPTH 100
#define ENC_ASCII 0

void* wmem_packet_scope();
char* tvb_get_string_enc(void* pool, void* tvb, int offset, int len, int encoding);
void* wmem_map_lookup(void* table, const char* key);
void g_warning(const char* format, ...);
tvbparse_elem_t* new_tok(tvbparse_t* tt, int id, int offset, int len, const tvbparse_wanted_t* wanted);
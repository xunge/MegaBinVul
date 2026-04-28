#include <stdlib.h>
#include <string.h>

typedef int gint;
typedef double gdouble;

typedef struct RsvgDash {
    gdouble *dash;
    gint n_dash;
} RsvgDash;

typedef struct RsvgState {
    struct RsvgState *parent;
    char *mask;
    char *font_family;
    char *lang;
    void *fill;
    void *stroke;
    void *styles;
    RsvgDash dash;
} RsvgState;

char* g_strdup(const char* str);
void* g_new(size_t size, size_t count);
#define g_new(type, count) ((type*)g_new(sizeof(type), (count)))
void* g_hash_table_ref(void* table);
void rsvg_state_finalize(RsvgState *state);
void rsvg_paint_server_ref(void *paint_server);
#include <stdlib.h>

typedef struct RsvgState RsvgState;
typedef struct RsvgDash RsvgDash;

struct RsvgDash {
    int n_dash;
    double *dash;
};

struct RsvgState {
    char *mask;
    char *font_family;
    char *lang;
    void *fill;
    void *stroke;
    RsvgDash dash;
    void *styles;
};

void g_free(void *ptr);
void rsvg_paint_server_unref(void *server);
void g_hash_table_unref(void *hash_table);
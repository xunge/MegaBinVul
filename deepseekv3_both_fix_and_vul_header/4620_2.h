#include <stdlib.h>
#include <string.h>

typedef struct _GString {
    char *str;
    size_t len;
    size_t allocated_len;
} GString;

typedef struct _cairo_path {
    int dummy;  // Placeholder for incomplete type
} cairo_path_t;

typedef unsigned int guint;
typedef int gboolean;

#define G_ASCII_DTOSTR_BUF_SIZE (39)
#define TRUE 1
#define FALSE 0

extern double *rsvg_css_parse_number_list(const char *value, guint *length);
extern cairo_path_t *rsvg_parse_path(const char *d);
extern GString *g_string_new(const char *init);
extern void g_string_free(GString *string, gboolean free_segment);
extern void g_string_append(GString *string, const char *val);
extern void g_string_append_c(GString *string, char c);
extern char *g_ascii_dtostr(char *buffer, int buf_len, double d);
extern void g_free(void *mem);
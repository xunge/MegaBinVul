#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

typedef struct _RSFilter RSFilter;
typedef struct _GString {
    char *str;
    size_t len;
} GString;

#define RS_IS_FILTER(filter) (1)
#define g_return_if_fail(expr) do { if (!(expr)) return; } while(0)
#define g_warning(msg) fprintf(stderr, "Warning: %s\n", msg)
#define TRUE 1
#define FALSE 0
#define gchar char

void rs_filter_graph_helper(GString *str, RSFilter *filter);

GString* g_string_new(const char *init);
void g_string_free(GString *string, int free_segment);
void g_string_append_printf(GString *string, const char *format, ...);
char* g_strdup_printf(const char *format, ...);
int g_file_set_contents(const char *filename, const char *contents, size_t length, void* unused);
void g_free(void *ptr);
unsigned int g_random_int(void);
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    void **pdata;
    unsigned int len;
} GPtrArray;

typedef struct {
    char *str;
    size_t len;
    size_t allocated_len;
} GString;

#define g_autoptr(type) __attribute__((cleanup(g_autoptr_cleanup))) type *
#define g_autofree __attribute__((cleanup(g_autofree_cleanup)))
#define FLATPAK_ESCAPE_DEFAULT 0

void g_autoptr_cleanup(void *p);
void g_autofree_cleanup(void *p);
GString* g_string_new(const char *init);
void g_string_append_printf(GString *string, const char *format, ...);
void g_print(const char *format, ...);
char *flatpak_escape_string(void *data, int flags);
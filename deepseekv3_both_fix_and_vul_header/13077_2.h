#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct _GHashTable GHashTable;
typedef struct _GError {
    int domain;
    int code;
    char* message;
} GError;

typedef int gboolean;
typedef size_t gsize;

#define TRUE 1
#define FALSE 0

GHashTable* g_hash_table_new_full(unsigned int (*hash_func)(const void*),
                                 int (*key_equal_func)(const void*, const void*),
                                 void (*key_destroy_func)(void*),
                                 void (*value_destroy_func)(void*));
unsigned int g_str_hash(const void* v);
int g_str_equal(const void* v1, const void* v2);
void g_free(void* p);
gboolean g_file_get_contents(const char* filename, char** contents, gsize* length, GError** error);
void g_info(const char* format, ...);
void g_hash_table_add(GHashTable* hash_table, void* key);
char* g_strndup(const char* str, size_t n);

#define g_autofree __attribute__((cleanup(g_free_pointer)))
#define g_autoptr(type) __attribute__((cleanup(g_autoptr_cleanup))) type*
static inline void g_free_pointer(void* p) { free(*(void**)p); }
static inline void g_autoptr_cleanup(void* p) { free(*(void**)p); }
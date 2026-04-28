#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include <libgen.h>

typedef void* gpointer;
typedef unsigned int guint32;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef struct _MonoClass MonoClass;
typedef struct _MonoMethod MonoMethod;
typedef struct _MonoMethodPInvoke MonoMethodPInvoke;
typedef struct _MonoImage MonoImage;
typedef struct _MonoTableInfo MonoTableInfo;
typedef struct _MonoDynamicImage MonoDynamicImage;
typedef struct _MonoReflectionMethodAux MonoReflectionMethodAux;
typedef struct _MonoDl MonoDl;

struct _MonoClass {
    MonoImage *image;
};

struct _MonoMethod {
    MonoClass *klass;
    guint32 flags;
    MonoMethodPInvoke *pinvoke;
};

struct _MonoMethodPInvoke {
    gpointer addr;
    guint32 implmap_idx;
    guint32 piflags;
};

struct _MonoImage {
    char *name;
    gboolean dynamic;
    MonoTableInfo *tables;
};

struct _MonoTableInfo {
    guint32 dummy;
};

struct _MonoDynamicImage {
    MonoImage image;
    void *method_aux_hash;
};

struct _MonoReflectionMethodAux {
    const char *dll;
    const char *dllentry;
};

#define METHOD_ATTRIBUTE_PINVOKE_IMPL 0x2000
#define MONO_TABLE_IMPLMAP 0
#define MONO_TABLE_MODULEREF 1
#define MONO_IMPLMAP_SIZE 4
#define MONO_IMPLMAP_FLAGS 0
#define MONO_IMPLMAP_NAME 1
#define MONO_IMPLMAP_SCOPE 2
#define MONO_MODULEREF_NAME 0
#define PINVOKE_ATTRIBUTE_NO_MANGLE 0x0001
#define PINVOKE_ATTRIBUTE_CHAR_SET_MASK 0x0006
#define PINVOKE_ATTRIBUTE_CHAR_SET_UNICODE 0x0002
#define PINVOKE_ATTRIBUTE_CHAR_SET_AUTO 0x0004
#define PINVOKE_ATTRIBUTE_CHAR_SET_ANSI 0x0000
#define MONO_DL_LAZY 1
#define G_LOG_LEVEL_INFO 1
#define G_LOG_LEVEL_WARNING 2
#define MONO_TRACE_DLLIMPORT 1

#define g_assert(expr) assert(expr)
#define g_free(ptr) free(ptr)
#define g_strdup(str) strdup(str)
#define g_strdup_printf(fmt, ...) ({ \
    char *buf; \
    int len = snprintf(NULL, 0, fmt, ##__VA_ARGS__); \
    buf = malloc(len + 1); \
    sprintf(buf, fmt, ##__VA_ARGS__); \
    buf; \
})
#define g_ascii_strcasecmp(s1, s2) strcasecmp(s1, s2)
#define g_path_get_dirname(path) strdup(dirname(path))
#define g_strconcat(...) ({ \
    char *buf; \
    int len = snprintf(NULL, 0, __VA_ARGS__); \
    buf = malloc(len + 1); \
    sprintf(buf, __VA_ARGS__); \
    buf; \
})

void mono_metadata_decode_row(MonoTableInfo *table, guint32 idx, guint32 *res, guint32 count);
guint32 mono_metadata_decode_row_col(MonoTableInfo *table, guint32 idx, guint32 col);
const char* mono_metadata_string_heap(MonoImage *image, guint32 idx);
void mono_dllmap_lookup(MonoImage *image, const char *dll, const char *func, const char **mapped_dll, const char **mapped_func);
void mono_trace(int level, guint32 domain, const char *format, ...);
MonoDl* mono_dl_open(const char *name, int flags, char **error_msg);
char* mono_dl_build_path(const char *dir, const char *name, void **iter);
MonoDl* cached_module_load(const char *name, int flags, char **error_msg);
char* mono_dl_symbol(MonoDl *module, const char *name, gpointer *symbol);
void* g_hash_table_lookup(void *hash, void *key);
#include <stdlib.h>
#include <string.h>

typedef char gchar;

struct _GpgCtx {
    int mode;
    void *recipients;
};

#define GPG_CTX_MODE_ENCRYPT 0
#define GPG_CTX_MODE_EXPORT 1

typedef struct {
    void **pdata;
    unsigned int len;
    unsigned int alloc;
} GPtrArray;

GPtrArray *g_ptr_array_new(void);
void g_ptr_array_add(GPtrArray *array, void *data);
char *g_strdup(const char *str);
#include <stdlib.h>

typedef struct _VipsObject VipsObject;

struct _VipsObject {
    void (*postclose)(VipsObject *);
    size_t local_memory;
};

typedef void (*GCallback)(void);
void* g_malloc(size_t size);
void g_signal_connect(VipsObject *object, const char *signal, GCallback callback, void *data);
void vips_malloc_cb(VipsObject *object, void *buf);

#define G_CALLBACK(f) ((GCallback)(f))
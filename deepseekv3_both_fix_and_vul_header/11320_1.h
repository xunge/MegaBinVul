#include <sys/types.h>
#include <stdlib.h>
#include <assert.h>

typedef struct QIOChannel QIOChannel;

#define MIN(a, b) ((a) < (b) ? (a) : (b))

extern ssize_t read_sync(QIOChannel *ioc, void *buffer, size_t size);

#define g_malloc malloc
#define g_free free
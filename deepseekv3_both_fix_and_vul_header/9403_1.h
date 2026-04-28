#include <stdlib.h>

typedef struct SimpleSpiceDisplay {
    int mouse_x;
    int mouse_y;
    int num_surfaces;
    size_t bufsize;
    void *buf;
    struct {
        int lock;
    } lock;
    struct {
        void *updates;
    } updates;
} SimpleSpiceDisplay;

#define QTAILQ_INIT(head) do { } while (0)
void qemu_mutex_init(int *mutex);
void *g_malloc(size_t size);
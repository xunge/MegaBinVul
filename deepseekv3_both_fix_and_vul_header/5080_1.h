#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <pthread.h>

extern void vips_tracked_init(void);
extern size_t vips_tracked_mem;
extern size_t vips_tracked_mem_highwater;
extern int vips_tracked_allocs;
extern pthread_mutex_t *vips_tracked_mutex;
extern void vips_error(const char *domain, const char *fmt, ...);
extern void VIPS_GATE_MALLOC(size_t size);

void *g_try_malloc(size_t size);
void g_warning(const char *format, ...);
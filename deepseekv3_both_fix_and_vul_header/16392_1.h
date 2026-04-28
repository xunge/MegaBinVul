#include <stdint.h>
#include <stddef.h>

typedef unsigned int guint;
typedef int gint;
typedef uint64_t guint64;

extern void *wmem_packet_scope(void);
extern void *wmem_alloc0(void *scope, size_t size);
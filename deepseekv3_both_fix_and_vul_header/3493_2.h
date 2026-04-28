#include <stddef.h>
#include <stdint.h>

#define XEN_GUEST_HANDLE_PARAM(type) type*
#define ENOENT 2
#define ENOMEM 12
#define EFAULT 14

#define xmalloc_array(type, size) xmalloc_bytes((size) * sizeof(type))

void *xmalloc_bytes(size_t size);
void xfree(void *ptr);
int copy_from_guest(void *dest, void *src, size_t size);
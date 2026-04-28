#include <stddef.h>
#include <stdint.h>

#define ASSERT(cond) ((void)0)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define __init

extern int xen_guest;
extern const unsigned long reserved_pages[1];
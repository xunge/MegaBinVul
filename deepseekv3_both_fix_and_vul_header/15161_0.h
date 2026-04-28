#include <stddef.h>
#include <string.h>

typedef unsigned char u8;

static inline const u8 *find_ie(u8 num, const u8 *ies, size_t len);
static inline size_t min(size_t a, size_t b);
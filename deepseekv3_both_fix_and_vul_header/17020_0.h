#include <string.h>
#include <stddef.h>

#define IS_SYN33(syn33, c) ((syn33) & (1U << ((c) % 32)))
#define IS_EXCLUDED(c, m32, m64, m96) \
    ((c) < 32 ? (m32) & (1U << (c)) : \
     (c) < 64 ? (m64) & (1U << ((c) - 32)) : \
     (m96) & (1U << ((c) - 64)))
#define IS_HEX(c) ( \
    ((c) >= '0' && (c) <= '9') || \
    ((c) >= 'a' && (c) <= 'f') || \
    ((c) >= 'A' && (c) <= 'F'))
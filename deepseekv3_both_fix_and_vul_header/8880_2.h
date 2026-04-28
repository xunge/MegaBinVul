#include <stdint.h>

#define CRYPTO_ALG_INTERNAL 0x00002000
#define IS_ERR(x) ((unsigned long)(x) >= (unsigned long)-4095)

typedef uint32_t u32;

struct rtattr;
struct crypto_attr_type {
    u32 type;
    u32 mask;
};

struct crypto_attr_type *crypto_get_attr_type(struct rtattr **tb);
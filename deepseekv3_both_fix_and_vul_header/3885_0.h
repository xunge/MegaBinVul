#include <stdint.h>

#define AT91_SECURE_MAGIC 0x5A1A2A3A

typedef struct {
    uint32_t magic;
    uint32_t file_size;
} at91_secure_header_t;

extern int secure_decrypt(void *data, unsigned int size, int flag);
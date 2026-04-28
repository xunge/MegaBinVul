#include <stdlib.h>
#include <stdint.h>

typedef struct RngBackend {
    void *requests;
} RngBackend;

typedef struct RngEgd RngEgd;
typedef struct RngRequest RngRequest;
typedef void (*EntropyReceiveFunc)(void *opaque, const void *data, size_t size);

struct RngRequest {
    size_t offset;
    size_t size;
    EntropyReceiveFunc *receive_entropy;
    void *opaque;
    uint8_t *data;
};

struct RngEgd {
    RngBackend parent;
    void *chr;
};

#define RNG_EGD(obj) ((RngEgd *)obj)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void *g_malloc(size_t size);
void *g_slist_append(void *list, void *data);
void qemu_chr_fe_write(void *chr, const uint8_t *buf, size_t len);
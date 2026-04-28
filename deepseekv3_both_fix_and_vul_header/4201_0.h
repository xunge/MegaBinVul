#include <unistd.h>
#include <errno.h>
#include <stdint.h>

typedef struct RngRequest RngRequest;
typedef struct RndRandom RndRandom;

struct RngRequest {
    void *opaque;
    uint8_t *data;
    size_t size;
    void (*receive_entropy)(void *opaque, uint8_t *data, ssize_t len);
};

struct RndRandom {
    struct {
        RngRequest *requests;
    } parent;
    int fd;
    size_t size;
    void *opaque;
    void (*receive_func)(void *opaque, uint8_t *data, ssize_t len);
};

#define RNG_RANDOM(obj) ((RndRandom *)(obj))

void g_assert(int condition);
void qemu_set_fd_handler(int fd, void *io_read, void *io_write, void *opaque);
void rng_backend_finalize_request(void *backend, RngRequest *req);
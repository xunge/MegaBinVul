#include <stddef.h>

typedef struct RngBackend {
    void *opaque;
    struct RngRequest *requests;
} RngBackend;

typedef struct RndRandom RndRandom;
typedef struct RngRequest RngRequest;
typedef void (*EntropyReceiveFunc)(void *opaque, void *data, size_t size);

struct RndRandom {
    RngBackend parent;
    int fd;
    EntropyReceiveFunc receive_func;
    void *opaque;
    size_t size;
};

static inline RndRandom *RNG_RANDOM(RngBackend *b) {
    return (RndRandom *)b;
}

void qemu_set_fd_handler(int fd, void (*read)(void *), void (*write)(void *), void *opaque);
void entropy_available(void *opaque);
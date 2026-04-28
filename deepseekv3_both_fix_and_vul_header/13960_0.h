#include <stdlib.h>

struct mspack_system {
    void (*free)(void *);
};

struct lzxd_stream {
    struct mspack_system *sys;
    void *inbuf;
    void *window;
};
#include <stddef.h>
#include <sys/types.h>
#include <string.h>

struct mspack_file;

struct mspack_system {
    void *(*alloc)(struct mspack_system *, size_t);
    void (*free)(void *);
    int (*seek)(struct mspack_file *, off_t, int);
    int (*read)(struct mspack_file *, void *, int);
};

struct mschmd_header {
    unsigned int num_chunks;
    unsigned int chunk_size;
    off_t dir_offset;
    unsigned char **chunk_cache;
};

struct mschm_decompressor_p {
    struct mspack_system *system;
    int error;
};

#define MSPACK_ERR_NOMEMORY 1
#define MSPACK_ERR_SEEK 2
#define MSPACK_ERR_READ 3
#define MSPACK_SYS_SEEK_START 0
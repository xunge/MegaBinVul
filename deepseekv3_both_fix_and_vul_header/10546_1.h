#include <stddef.h>

typedef int boolean;
#define FALSE 0
#define TRUE 1

struct jpeg_source_mgr {
    unsigned char *next_input_byte;
    size_t bytes_in_buffer;
};

struct jpeg_decompress_struct {
    struct jpeg_source_mgr *src;
};

struct iodescr {
    int (*read_fn)(void*, struct iodescr*, unsigned char*, size_t, size_t*);
};

struct iwjpegrcontext {
    struct jpeg_source_mgr pub;
    void *ctx;
    struct iodescr *iodescr;
    unsigned char *buffer;
    size_t buffer_len;
};

typedef struct jpeg_decompress_struct *j_decompress_ptr;
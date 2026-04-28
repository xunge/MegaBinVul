#include <stddef.h>

struct jpeg_decompress_struct {
    struct {
        struct iwjpegrcontext *src;
    } *src;
};

struct iwjpegrcontext {
    struct {
        const unsigned char *next_input_byte;
        size_t bytes_in_buffer;
    } pub;
    void *ctx;
    struct {
        int (*read_fn)(void*, void*, unsigned char*, size_t, size_t*);
    } *iodescr;
    unsigned char *buffer;
    size_t buffer_len;
};

typedef struct jpeg_decompress_struct *j_decompress_ptr;
#include <sys/types.h>
#include <stddef.h>

#define MSPACK_ERR_ARGS     (-1)
#define MSPACK_ERR_WRITE    (-2)
#define MSPACK_ERR_DECRUNCH (-3)
#define MSPACK_ERR_OK       0

#define LZX_FRAME_SIZE 32768
#define LZX_NUM_CHARS 256
#define LZX_NUM_PRIMARY_LENGTHS 7
#define LZX_MIN_MATCH 2
#define LZX_MAX_MATCH 257
#define LZX_NUM_SECONDARY_LENGTHS 249
#define LZX_BLOCKTYPE_VERBATIM 1
#define LZX_BLOCKTYPE_ALIGNED 2
#define LZX_BLOCKTYPE_UNCOMPRESSED 3

struct lzxd_stream {
    int error;
    unsigned char *o_ptr, *o_end;
    off_t offset;
    unsigned char *window;
    unsigned int window_size;
    unsigned int window_posn;
    unsigned int frame_posn;
    unsigned int frame;
    unsigned int reset_interval;
    unsigned int R0, R1, R2;
    int block_type;
    unsigned int block_length;
    unsigned int block_remaining;
    unsigned char ALIGNED_len[8];
    unsigned char MAINTREE_len[256 + 8*256];
    int LENGTH_empty;
    int is_delta;
    int header_read;
    unsigned int intel_filesize;
    int intel_started;
    unsigned char e8_buf[LZX_FRAME_SIZE];
    signed int intel_curpos;
    off_t length;
    size_t ref_data_size;
    struct mspack_system *sys;
    void *output;
};

struct mspack_system {
    int (*write)(void *, void *, size_t);
    void *(*copy)(void *, void *, size_t);
};

static unsigned int position_base[51];
static unsigned char extra_bits[51];

#define RESTORE_BITS
#define ENSURE_BITS(n)
#define REMOVE_BITS(n)
#define PEEK_BITS(n) 0
#define READ_BITS(v, n)
#define READ_HUFFSYM(t, v)
#define READ_LENGTHS(t, a, b)
#define BUILD_TABLE(t)
#define BUILD_TABLE_MAYBE_EMPTY(t)
#define READ_IF_NEEDED
#define STORE_BITS
#define D(x)
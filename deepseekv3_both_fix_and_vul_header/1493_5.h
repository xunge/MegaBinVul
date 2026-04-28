#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define RZ_NEWS0(type, n) ((type *)calloc(n, sizeof(type)))
#define RZ_NEW0(type) ((type *)calloc(1, sizeof(type)))
#define RZ_FREE(x) free(x)
#define PFMT64x "llx"

typedef uint8_t ut8;
typedef uint16_t ut16;
typedef uint32_t ut32;
typedef uint64_t ut64;

struct dyld_info_command {
    ut32 bind_off;
    ut32 bind_size;
};

struct mach0_segment {
    ut64 vmsize;
};

struct rz_dyld_chained_starts_in_segment {
    ut32 pointer_format;
    ut32 page_size;
    ut32 page_count;
    ut16 *page_start;
};

struct MACH0_obj_t {
    struct dyld_info_command *dyld_info;
    size_t nsegs;
    size_t nchained_starts;
    struct rz_dyld_chained_starts_in_segment **chained_starts;
    size_t size;
    void *b;
    struct mach0_segment *segs;
};

#define BIND_IMMEDIATE_MASK 0x0f
#define BIND_OPCODE_MASK 0xf0

enum {
    BIND_OPCODE_DONE = 0x00,
    BIND_OPCODE_SET_DYLIB_ORDINAL_IMM = 0x10,
    BIND_OPCODE_SET_DYLIB_ORDINAL_ULEB = 0x20,
    BIND_OPCODE_SET_DYLIB_SPECIAL_IMM = 0x30,
    BIND_OPCODE_SET_SYMBOL_TRAILING_FLAGS_IMM = 0x40,
    BIND_OPCODE_SET_TYPE_IMM = 0x50,
    BIND_OPCODE_SET_ADDEND_SLEB = 0x60,
    BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB = 0x70,
    BIND_OPCODE_ADD_ADDR_ULEB = 0x80,
    BIND_OPCODE_DO_BIND = 0x90,
    BIND_OPCODE_DO_BIND_ADD_ADDR_ULEB = 0xa0,
    BIND_OPCODE_DO_BIND_ADD_ADDR_IMM_SCALED = 0xb0,
    BIND_OPCODE_DO_BIND_ULEB_TIMES_SKIPPING_ULEB = 0xc0,
    BIND_OPCODE_THREADED = 0xd0
};

enum {
    BIND_SUBOPCODE_THREADED_SET_BIND_ORDINAL_TABLE_SIZE_ULEB = 0x00,
    BIND_SUBOPCODE_THREADED_APPLY = 0x01
};

#define DYLD_CHAINED_PTR_ARM64E 1

static size_t get_word_size(struct MACH0_obj_t *bin);
static ut64 read_uleb128(const ut8 **p, const ut8 *end);
static int rz_sleb128(const ut8 **p, const ut8 *end);
static int rz_buf_read_at(void *b, ut64 addr, ut8 *buf, size_t len);
static void bprintf(const char *fmt, ...);

#define MACH0_(name) MACH0_##name
typedef struct MACH0_obj_t MACH0_(obj_t);
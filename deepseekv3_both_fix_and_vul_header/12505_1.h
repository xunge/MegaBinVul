#include <stdbool.h>
#include <stdint.h>

typedef uint64_t ut64;
typedef uint16_t ut16;
typedef uint8_t ut8;

#define MACH0_(x) x
#define DYLD_CHAINED_PTR_START_NONE 0xFFFF
#define IS_PTR_AUTH(x) ((x) & (1ULL << 63))
#define IS_PTR_BIND(x) ((x) & (1ULL << 62))
#define R_MAX(a, b) ((a) > (b) ? (a) : (b))
#define R_MIN(a, b) ((a) < (b) ? (a) : (b))

struct MACH0_(obj_t) {
    bool rebasing_buffer;
    int nsegs;
    struct {
        ut64 fileoff;
        ut64 filesize;
    } *segs;
    struct {
        ut64 page_size;
        ut64 page_count;
        ut16 *page_start;
    } **chained_starts;
    void *b;
    ut64 baddr;
};

struct dyld_chained_ptr_arm64e_auth_bind {
    ut64 next;
};

struct dyld_chained_ptr_arm64e_bind {
    ut64 next;
};

struct dyld_chained_ptr_arm64e_auth_rebase {
    ut64 target;
    ut64 next;
};

struct dyld_chained_ptr_arm64e_rebase {
    ut64 target;
    ut64 high8;
    ut64 next;
};

typedef struct RIODesc RIODesc;

static int r_buf_read_at(void *b, ut64 cursor, ut8 *tmp, int size);
static ut64 r_read_le64(ut8 *tmp);
static void r_write_le64(ut8 *buf, ut64 value);
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef uint32_t u32;
typedef uint16_t u16;

#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)
#define IS_ALIGNED(x, y) (((x) & ((y)-1)) == 0)
#define Add2Ptr(p, o) ((void *)((uint8_t *)(p) + (o)))
#define PtrOffset(p, q) ((size_t)((uint8_t *)(q) - (uint8_t *)(p)))
#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))

struct ATTRIB {
    uint32_t type;
    uint32_t size;
    uint8_t non_res;
    uint8_t name_len;
    uint16_t name_off;
    union {
        struct {
            uint16_t data_off;
            uint32_t data_size;
        } res;
        struct {
            uint16_t run_off;
            uint8_t c_unit;
            uint8_t svcn;
        } nres;
    };
};

struct MFT_REC {
    uint32_t used;
    uint32_t total;
    uint16_t attr_off;
};

struct mft_inode {
    struct MFT_REC *mrec;
};

enum ATTR_TYPE {
    ATTR_END
};

#define MFTRECORD_FIXUP_OFFSET_1 0x30
#define SIZEOF_RESIDENT 24
#define SIZEOF_NONRESIDENT 64
#define SIZEOF_NONRESIDENT_EX 72

static inline int is_rec_inuse(const struct MFT_REC *rec) { return 1; }
static inline int is_attr_ext(const struct ATTRIB *attr) { return 0; }
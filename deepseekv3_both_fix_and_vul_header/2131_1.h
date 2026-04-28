#include <stdint.h>

#define IV3_BAD_DATA     -1
#define IV3_BAD_RLE      -2
#define IV3_BAD_COUNTER  -3
#define IV3_UNSUPPORTED  -4
#define IV3_NOERR        0

#define RLE_ESC_FC 252
#define RLE_ESC_FD 253
#define RLE_ESC_FE 254
#define RLE_ESC_FF 255
#define RLE_ESC_FB 251
#define RLE_ESC_F9 249
#define RLE_ESC_FA 250

#define FFSWAP(type, a, b) do { type SWAP_tmp = b; b = a; a = SWAP_tmp; } while (0)

#define BUFFER_PRECHECK if (*data_ptr >= last_ptr) return IV3_BAD_DATA
#define bytestream_get_byte(p) (*((*p)++))

#define RLE_BLOCK_COPY memcpy(dst, ref, 16)
#define RLE_BLOCK_COPY_8 memcpy(dst, ref, 32)
#define APPLY_DELTA_4 do { \
    *(uint32_t*)dst = *(uint32_t*)ref + (dyad1 << 16 | dyad2); \
} while (0)
#define APPLY_DELTA_8 do { \
    *(uint64_t*)dst = *(uint64_t*)ref + ((uint64_t)dyad1 << 32 | dyad2); \
} while (0)
#define APPLY_DELTA_1011_INTER do { \
    *(uint64_t*)dst = (*(uint64_t*)ref & 0xF0F0F0F0F0F0F0F0ULL) + \
                     ((dyad1 & 0xF0F0F0F0) << 32 | (dyad2 & 0xF0F0F0F0)); \
} while (0)
#define RLE_LINES_COPY do { \
    for (int i = 0; i < num_lines; i++) \
        memcpy(dst + i * row_offset, ref + i * row_offset, 4); \
} while (0)
#define RLE_LINES_COPY_M10 do { \
    for (int i = 0; i < num_lines; i++) \
        memcpy(dst + i * row_offset, ref + i * row_offset, 8); \
} while (0)

typedef struct vqEntry {
    int num_dyads;
    int quad_exp;
} vqEntry;

typedef struct Cell {
    int width;
    int height;
    uint8_t *mv_ptr;
} Cell;
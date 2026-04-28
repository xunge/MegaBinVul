#include <stdbool.h>
#include <stdint.h>

typedef uint8_t u8;

#define MAGIC_VMDB 0x564D4442
#define BUG_ON(condition) do { if (condition) {} } while (0)

struct vmdb {
    uint16_t ver_major;
    uint16_t ver_minor;
    uint32_t vblk_size;
    uint32_t vblk_offset;
    uint32_t last_vblk_seq;
};

static inline uint32_t get_unaligned_be32(const u8 *p) {
    return ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) |
           ((uint32_t)p[2] << 8) | p[3];
}

static inline uint16_t get_unaligned_be16(const u8 *p) {
    return (p[0] << 8) | p[1];
}

static void ldm_crit(const char *msg) {}
static void ldm_error(const char *msg, ...) {}
static void ldm_debug(const char *msg) {}
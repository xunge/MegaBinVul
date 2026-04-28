#include <stddef.h>
#include <stdint.h>

typedef uint16_t __le16;
typedef uint32_t __le32;
typedef uint16_t __u16;
typedef uint32_t __u32;
typedef uint8_t __u8;

struct super_block {
    void *s_fs_info;
};

struct ext4_group_desc {
    __u16 bg_checksum;
};

struct ext4_sb_info {
    struct super_block *s_sb;
    __u32 s_csum_seed;
    __u16 s_desc_size;
    struct ext4_super_block *s_es;
};

struct ext4_super_block {
    __u8 s_uuid[16];
    __le16 s_desc_size;
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb)->s_fs_info)
#define cpu_to_le16(x) (x)
#define cpu_to_le32(x) (x)
#define le16_to_cpu(x) (x)

static inline int ext4_has_metadata_csum(struct super_block *sb) { return 0; }
static inline int ext4_has_feature_gdt_csum(struct super_block *sb) { return 0; }
static inline int ext4_has_feature_64bit(struct super_block *sb) { return 0; }
static inline uint32_t ext4_chksum(struct ext4_sb_info *sbi, uint32_t seed, const __u8 *data, size_t len) { return 0; }
static inline uint16_t crc16(uint16_t crc, const void *buffer, size_t len) { return 0; }
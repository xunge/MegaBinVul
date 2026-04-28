#include <stddef.h>
#include <stdint.h>

typedef uint8_t __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;
typedef uint16_t __le16;
typedef uint32_t __le32;

struct super_block {
    void *s_fs_info;
};

struct ext4_super_block {
    __u8 s_uuid[16];
    __le16 s_desc_size;
};

struct ext4_sb_info {
    struct super_block *s_sb;
    __u32 s_csum_seed;
    __u16 s_desc_size;
    struct ext4_super_block *s_es;
};

struct ext4_group_desc {
    __u16 bg_checksum;
};

#define EXT4_SB(sb) ((struct ext4_sb_info *)((sb)->s_fs_info))
#define cpu_to_le16(x) (x)
#define cpu_to_le32(x) (x)
#define le16_to_cpu(x) (x)

static inline int ext4_has_metadata_csum(struct super_block *sb) { return 0; }
static inline int ext4_has_feature_gdt_csum(struct super_block *sb) { return 0; }
static inline int ext4_has_feature_64bit(struct super_block *sb) { return 0; }
static inline __u32 ext4_chksum(struct ext4_sb_info *sbi, __u32 crc, const __u8 *data, size_t len) { return 0; }
static inline __u16 crc16(__u16 crc, const __u8 *buffer, size_t len) { return 0; }
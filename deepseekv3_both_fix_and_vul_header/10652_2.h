#include <stdint.h>
#include <stdlib.h>

#define EXT4_EXTENTS_FLAG 0x80000
#define INDIRECT_BLOCKS 12
#define GRUB_ERR_BAD_FS 1
#define GRUB_ERR_NOT_IMPLEMENTED_YET 2

typedef uint64_t grub_disk_addr_t;
typedef uint32_t grub_uint32_t;
typedef uint16_t grub_uint16_t;

struct grub_ext2_data {
    void* disk;
    int log2_blksz;
};

struct grub_ext2_inode {
    grub_uint32_t flags;
    union {
        grub_uint32_t dir_blocks[15];
        struct {
            grub_uint32_t indir_block;
            grub_uint32_t double_indir_block;
            grub_uint32_t triple_indir_block;
        };
    } blocks;
};

struct grub_ext4_extent_header {
    grub_uint16_t entries;
};

struct grub_ext4_extent {
    grub_uint32_t block;
    grub_uint16_t len;
    grub_uint16_t start_hi;
    grub_uint32_t start;
};

struct grub_fshelp_node {
    struct grub_ext2_data* data;
    struct grub_ext2_inode inode;
};
typedef struct grub_fshelp_node* grub_fshelp_node_t;

#define EXT2_BLOCK_SIZE(data) (1 << LOG2_EXT2_BLOCK_SIZE(data))
#define LOG2_EXT2_BLOCK_SIZE(data) (10 + (data)->log2_blksz)

static inline uint32_t grub_le_to_cpu32(uint32_t x) { return x; }
static inline uint16_t grub_le_to_cpu16(uint16_t x) { return x; }

void* grub_malloc(size_t size);
void grub_free(void* ptr);
int grub_error(int err, const char* msg);
int grub_errno;
int grub_disk_read(void* disk, grub_disk_addr_t sector, unsigned offset, unsigned size, void* buf);
struct grub_ext4_extent_header* grub_ext4_find_leaf(struct grub_ext2_data* data, void* buf, struct grub_ext4_extent_header* extents, grub_disk_addr_t fileblock);
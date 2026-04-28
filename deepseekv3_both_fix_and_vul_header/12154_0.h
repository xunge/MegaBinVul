#include <stdint.h>
#include <string.h>

#define EXFAT_FILE 1
#define EXFAT_STREAM 2
#define EXFAT_NAME 3
#define EXFAT_SF_CONTIGUOUS 0x01
#define MAX_NAME_DENTRIES 255
#define ENTRY_NAME_MAX 15
#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct exfat_dentry {
    uint8_t type;
    uint16_t file_attr;
    uint8_t file_num_ext;
    uint32_t stream_start_clu;
    uint8_t stream_flags;
    uint64_t stream_size;
    uint16_t name_unicode[ENTRY_NAME_MAX];
};

struct exfat_inode {
    uint16_t file_attr;
    uint32_t first_clus;
    int is_contiguous;
    uint64_t size;
    uint16_t name[(MAX_NAME_DENTRIES + 1) * ENTRY_NAME_MAX];
};

struct exfat_de_iter;

static inline uint16_t le16_to_cpu(uint16_t val) { return val; }
static inline uint32_t le32_to_cpu(uint32_t val) { return val; }
static inline uint64_t le64_to_cpu(uint64_t val) { return val; }

int exfat_de_iter_get(struct exfat_de_iter *iter, int index, struct exfat_dentry **dentry);
void exfat_debug(const char *fmt, ...);
struct exfat_inode *exfat_alloc_inode(uint16_t attr);
void exfat_free_inode(struct exfat_inode *node);

#define EINVAL 22
#define ENOMEM 12
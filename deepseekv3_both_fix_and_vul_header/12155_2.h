#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#define EXFAT_FILE 1
#define EXFAT_STREAM 2
#define EXFAT_NAME 3
#define EXFAT_DELETE 0x80
#define EXFAT_SF_CONTIGUOUS 0x01

#define MAX_NAME_DENTRIES 255
#define ENTRY_NAME_MAX 15

#define ER_DE_CHECKSUM 1
#define ER_DE_SECONDARY_COUNT 2
#define ER_DE_STREAM 3
#define ER_DE_NAME 4
#define ER_FILE_VALID_SIZE 5

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct exfat_dentry {
    uint8_t type;
    uint16_t file_checksum;
    uint8_t file_num_ext;
    uint16_t file_attr;
    uint8_t name_unicode[30];
    uint32_t stream_start_clu;
    uint8_t stream_flags;
    uint8_t stream_name_len;
    uint64_t stream_size;
    uint64_t stream_valid_size;
};

struct exfat_inode {
    uint16_t file_attr;
    uint32_t first_clus;
    bool is_contiguous;
    uint64_t size;
    char name[MAX_NAME_DENTRIES * ENTRY_NAME_MAX + 1];
};

struct exfat_de_iter {
    int dummy;
};

static uint16_t file_calc_checksum(struct exfat_de_iter *iter);
static bool repair_file_ask(struct exfat_de_iter *iter, struct exfat_inode *node, int err, const char *fmt, ...);
static int exfat_de_iter_get(struct exfat_de_iter *iter, int idx, struct exfat_dentry **dentry);
static void exfat_de_iter_get_dirty(struct exfat_de_iter *iter, int idx, struct exfat_dentry **dentry);
static struct exfat_inode *exfat_alloc_inode(uint16_t attr);
static void exfat_free_inode(struct exfat_inode *node);
static int check_name_dentry_set(struct exfat_de_iter *iter, struct exfat_inode *node);
static int handle_dot_dotdot_filename(struct exfat_de_iter *iter, struct exfat_dentry *dentry, uint8_t name_len);
static void exfat_err(const char *msg);

#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)
#define le64_to_cpu(x) (x)
#define PRIu64 "llu"
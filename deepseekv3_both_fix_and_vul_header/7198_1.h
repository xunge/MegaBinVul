#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef uint16_t le16;
typedef uint32_t le32;
typedef uint64_t le64;

#define AT_END 0xFFFFFFFF
#define IGNORE_CASE 0
#define CASE_SENSITIVE 1
#define ENOENT 2
#define EIO 5

#define unlikely(x) (x)
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

typedef uint32_t ATTR_TYPE;
typedef uint16_t ntfschar;
typedef bool IGNORE_CASE_BOOL;

typedef struct {
    le32 type;
    le32 length;
    le16 name_offset;
    u8 name_length;
    struct {
        struct {
            le32 value_offset;
            le32 value_length;
        } resident;
    } data;
} ATTR_RECORD;

typedef struct {
    le32 bytes_allocated;
} MFT_RECORD;

typedef struct {
    u32 upcase_len;
    ntfschar *upcase;
    void *sb;
} ntfs_volume;

typedef struct {
    ntfs_volume *vol;
} ntfs_inode;

typedef struct {
    ntfs_inode *ntfs_ino;
    MFT_RECORD *mrec;
    ATTR_RECORD *attr;
    bool is_first;
} ntfs_attr_search_ctx;

static inline le32 le32_to_cpu(le32 x) { return x; }
static inline le16 le16_to_cpu(le16 x) { return x; }

static int ntfs_are_names_equal(const ntfschar *name1, u32 name1_len,
                              const ntfschar *name2, u32 name2_len,
                              IGNORE_CASE_BOOL ic,
                              ntfschar *upcase, u32 upcase_len);

static int ntfs_collate_names(const ntfschar *name1, u32 name1_len,
                             const ntfschar *name2, u32 name2_len,
                             int err_val, IGNORE_CASE_BOOL ic,
                             ntfschar *upcase, u32 upcase_len);

static void ntfs_error(void *sb, const char *message);
static void NVolSetErrors(ntfs_volume *vol);
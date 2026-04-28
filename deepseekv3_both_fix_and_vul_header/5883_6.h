#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#define EIO 5
#define ESTALE 116

struct buffer_head {
    void *b_data;
};

struct inode {
    unsigned long i_ino;
    struct super_block *i_sb;
    unsigned int i_uid;
    unsigned int i_gid;
    unsigned int i_mode;
    unsigned long i_size;
    unsigned long i_blocks;
    unsigned int i_nlink;
    struct timespec i_atime;
    struct timespec i_mtime;
    struct timespec i_ctime;
    unsigned long i_generation;
    void *i_private;
    void *i_op;
    void *i_fop;
    struct {
        void *a_ops;
    } i_data;
    int s_blocksize_bits;
    int s_blocksize;
};

struct super_block {
    void *s_fs_info;
    int s_blocksize;
    int s_blocksize_bits;
};

struct kernel_lb_addr {
    uint32_t logicalBlockNum;
    uint16_t partitionReferenceNum;
};

struct long_ad {
    struct kernel_lb_addr extLocation;
    uint32_t extLength;
};

struct udf_inode_info {
    struct kernel_lb_addr i_location;
    unsigned int i_strat4096:1;
    unsigned int i_alloc_type:3;
    unsigned int i_efe:1;
    unsigned int i_use:1;
    uint64_t i_unique;
    uint32_t i_lenEAttr;
    uint32_t i_lenExtents;
    uint32_t i_lenAlloc;
    uint32_t i_next_alloc_block;
    uint32_t i_next_alloc_goal;
    uint32_t i_checkpoint;
    struct timespec i_crtime;
    union {
        void *i_sad;
        void *i_lad;
        uint8_t *i_data;
    } i_ext;
};

struct udf_sb_info {
    uint32_t s_uid;
    uint32_t s_gid;
    unsigned int s_fmode;
    unsigned int s_dmode;
    unsigned int s_umask;
    struct timespec s_record_time;
    uint32_t s_flags;
    struct udf_part_map *s_partmaps;
    struct {
        int dummy;
    } s_cred_lock;
};

struct udf_part_map {
    uint32_t s_partition_len;
};

struct tag {
    uint16_t tagIdent;
};

struct icbtag {
    uint16_t strategyType;
    uint16_t flags;
    uint8_t fileType;
};

struct timestamp {
    uint16_t typeAndTimezone;
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t centiseconds;
    uint8_t hundredsOfMicroseconds;
    uint8_t microseconds;
};

struct fileEntry {
    struct tag descTag;
    struct icbtag icbTag;
    uint32_t uid;
    uint32_t gid;
    uint32_t permissions;
    uint16_t fileLinkCount;
    uint8_t recordFormat;
    uint8_t recordDisplayAttr;
    uint32_t recordLength;
    uint64_t informationLength;
    uint64_t logicalBlocksRecorded;
    struct timestamp accessTime;
    struct timestamp modificationTime;
    struct timestamp attrTime;
    uint32_t checkpoint;
    uint32_t extendedAttrICB;
    uint32_t lengthAllocDescs;
    uint32_t lengthExtendedAttr;
    uint64_t uniqueID;
    uint8_t allocDescs[0];
};

struct extendedFileEntry {
    struct tag descTag;
    struct icbtag icbTag;
    uint32_t uid;
    uint32_t gid;
    uint32_t permissions;
    uint16_t fileLinkCount;
    uint8_t recordFormat;
    uint8_t recordDisplayAttr;
    uint32_t recordLength;
    uint64_t informationLength;
    uint64_t logicalBlocksRecorded;
    struct timestamp accessTime;
    struct timestamp modificationTime;
    struct timestamp createTime;
    struct timestamp attrTime;
    uint32_t checkpoint;
    uint32_t extendedAttrICB;
    uint32_t lengthAllocDescs;
    uint32_t lengthExtendedAttr;
    uint64_t uniqueID;
    uint8_t allocDescs[0];
};

struct indirectEntry {
    struct tag descTag;
    struct icbtag icbTag;
    struct long_ad indirectICB;
};

struct unallocSpaceEntry {
    struct tag descTag;
    uint32_t lengthAllocDescs;
    uint8_t allocDescs[0];
};

struct deviceSpec {
    uint32_t majorDeviceIdent;
    uint32_t minorDeviceIdent;
};

struct udf_dir_inode_operations {};
struct udf_dir_operations {};
struct udf_adinicb_aops {};
struct udf_aops {};
struct udf_file_inode_operations {};
struct udf_file_operations {};
struct udf_symlink_aops {};
struct udf_symlink_inode_operations {};

#define UDF_MAX_ICB_NESTING 1024
#define UDF_SB(sb) ((struct udf_sb_info *)((sb)->s_fs_info))
#define UDF_I(inode) ((struct udf_inode_info *)((inode)->i_private))
#define UDF_QUERY_FLAG(sb, flag) (UDF_SB(sb)->s_flags & (flag))
#define UDF_FLAG_UID_IGNORE 0x0001
#define UDF_FLAG_UID_SET 0x0002
#define UDF_FLAG_GID_IGNORE 0x0004
#define UDF_FLAG_GID_SET 0x0008
#define UDF_INVALID_MODE ((unsigned int)-1)

#define ICBTAG_FLAG_AD_MASK 0x0007
#define ICBTAG_FLAG_AD_IN_ICB 0x0001
#define ICBTAG_FILE_TYPE_DIRECTORY 4
#define ICBTAG_FILE_TYPE_REALTIME 5
#define ICBTAG_FILE_TYPE_REGULAR 1
#define ICBTAG_FILE_TYPE_UNDEF 0
#define ICBTAG_FILE_TYPE_VAT20 20
#define ICBTAG_FILE_TYPE_BLOCK 6
#define ICBTAG_FILE_TYPE_CHAR 7
#define ICBTAG_FILE_TYPE_FIFO 8
#define ICBTAG_FILE_TYPE_SOCKET 9
#define ICBTAG_FILE_TYPE_SYMLINK 10
#define ICBTAG_FILE_TYPE_MAIN 254
#define ICBTAG_FILE_TYPE_MIRROR 253
#define ICBTAG_FILE_TYPE_BITMAP 252

#define TAG_IDENT_FE 0x0100
#define TAG_IDENT_EFE 0x0101
#define TAG_IDENT_USE 0x0102
#define TAG_IDENT_IE 0x0103

#define S_IRWXUGO 0777
#define MKDEV(ma,mi) (((ma) << 20) | (mi))

static inline uint16_t cpu_to_le16(uint16_t x) { return x; }
static inline uint16_t le16_to_cpu(uint16_t x) { return x; }
static inline uint32_t cpu_to_le32(uint32_t x) { return x; }
static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
static inline uint64_t cpu_to_le64(uint64_t x) { return x; }
static inline uint64_t le64_to_cpu(uint64_t x) { return x; }
static inline struct kernel_lb_addr lelb_to_cpu(struct kernel_lb_addr x) { return x; }

static inline void i_uid_write(struct inode *inode, uint32_t uid) { inode->i_uid = uid; }
static inline void i_gid_write(struct inode *inode, uint32_t gid) { inode->i_gid = gid; }
static inline int uid_valid(uint32_t uid) { return 1; }
static inline int gid_valid(uint32_t gid) { return 1; }
static inline void set_nlink(struct inode *inode, unsigned int nlink) { inode->i_nlink = nlink; }
static inline void inc_nlink(struct inode *inode) { inode->i_nlink++; }
static inline void brelse(struct buffer_head *bh) {}
static inline void init_special_inode(struct inode *inode, unsigned int mode, unsigned int dev) {}
static inline void read_lock(void *lock) {}
static inline void read_unlock(void *lock) {}

extern struct buffer_head *udf_read_ptagged(struct super_block *, struct kernel_lb_addr *, int, uint16_t *);
extern int udf_alloc_i_data(struct inode *, int);
extern void *udf_get_extendedattr(struct inode *, int, int);
extern int udf_disk_stamp_to_time(struct timespec *, struct timestamp);
extern unsigned int udf_convert_permissions(struct fileEntry *);
extern void udf_debug(const char *, ...);
extern void udf_err(struct super_block *, const char *, ...);

/* Define dummy operations structures */
static struct udf_dir_inode_operations udf_dir_inode_operations;
static struct udf_dir_operations udf_dir_operations;
static struct udf_adinicb_aops udf_adinicb_aops;
static struct udf_aops udf_aops;
static struct udf_file_inode_operations udf_file_inode_operations;
static struct udf_file_operations udf_file_operations;
static struct udf_symlink_aops udf_symlink_aops;
static struct udf_symlink_inode_operations udf_symlink_inode_operations;
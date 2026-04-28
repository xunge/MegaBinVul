#include <stdint.h>
#include <string.h>

struct super_block {
    unsigned int s_blocksize;
    unsigned int s_blocksize_bits;
};

struct inode {
    unsigned long i_ino;
    struct super_block *i_sb;
    unsigned int i_mode;
    unsigned int i_uid;
    unsigned int i_gid;
    unsigned int i_flags;
    unsigned int i_state;
    unsigned int i_count;
    unsigned int i_nlink;
    void *i_op;
    void *i_fop;
    struct {
        void *a_ops;
    } i_data;
    long i_size;
    long i_blocks;
    long i_atime;
    long i_mtime;
    long i_ctime;
};

struct buffer_head {
    void *b_data;
};

struct kernel_lb_addr {
    uint32_t logicalBlockNum;
    uint16_t partitionReferenceNum;
};

struct fileEntry {
    struct {
        uint16_t strategyType;
        uint16_t flags;
        uint8_t fileType;
    } icbTag;
    struct {
        uint16_t tagIdent;
    } descTag;
    uint32_t uid;
    uint32_t gid;
    uint16_t fileLinkCount;
    uint64_t informationLength;
    uint64_t logicalBlocksRecorded;
    uint32_t accessTime;
    uint32_t modificationTime;
    uint32_t attrTime;
    uint64_t uniqueID;
    uint32_t lengthExtendedAttr;
    uint32_t lengthAllocDescs;
    uint32_t checkpoint;
};

struct extendedFileEntry {
    struct {
        uint16_t strategyType;
        uint16_t flags;
        uint8_t fileType;
    } icbTag;
    struct {
        uint16_t tagIdent;
    } descTag;
    uint32_t uid;
    uint32_t gid;
    uint16_t fileLinkCount;
    uint64_t informationLength;
    uint64_t logicalBlocksRecorded;
    uint32_t accessTime;
    uint32_t modificationTime;
    uint32_t createTime;
    uint32_t attrTime;
    uint64_t uniqueID;
    uint32_t lengthExtendedAttr;
    uint32_t lengthAllocDescs;
    uint32_t checkpoint;
};

struct indirectEntry {
    struct {
        struct kernel_lb_addr extLocation;
        uint32_t extLength;
    } indirectICB;
};

struct unallocSpaceEntry {
    uint32_t lengthAllocDescs;
};

struct deviceSpec {
    uint32_t majorDeviceIdent;
    uint32_t minorDeviceIdent;
};

struct udf_inode_info {
    struct kernel_lb_addr i_location;
    unsigned int i_strat4096;
    unsigned int i_alloc_type;
    unsigned int i_efe;
    unsigned int i_use;
    uint64_t i_unique;
    uint32_t i_lenEAttr;
    uint32_t i_lenExtents;
    uint32_t i_lenAlloc;
    uint32_t i_next_alloc_block;
    uint32_t i_next_alloc_goal;
    uint32_t i_checkpoint;
    struct {
        void *i_data;
    } i_ext;
    uint64_t i_crtime;
};

struct udf_sb_info {
    unsigned int s_umask;
    unsigned int s_fmode;
    unsigned int s_dmode;
    uint64_t s_record_time;
    uint32_t s_uid;
    uint32_t s_gid;
    void *s_cred_lock;
};

struct udf_dir_inode_operations {
};

struct udf_dir_operations {
};

struct udf_file_inode_operations {
};

struct udf_file_operations {
};

struct udf_symlink_inode_operations {
};

struct udf_adinicb_aops {
};

struct udf_aops {
};

struct udf_symlink_aops {
};

#define TAG_IDENT_FE 0x0100
#define TAG_IDENT_EFE 0x0101
#define TAG_IDENT_USE 0x0102
#define TAG_IDENT_IE 0x0103

#define ICBTAG_FLAG_AD_MASK 0x0007
#define ICBTAG_FLAG_AD_IN_ICB 0x0001

#define UDF_FLAG_UID_IGNORE 0x0001
#define UDF_FLAG_UID_SET 0x0002
#define UDF_FLAG_GID_IGNORE 0x0004
#define UDF_FLAG_GID_SET 0x0008

#define UDF_INVALID_MODE 0xFFFF
#define UDF_MAX_ICB_NESTING 10

#define S_IFMT  0170000
#define S_IFDIR 0040000
#define S_IFREG 0100000
#define S_IFBLK 0060000
#define S_IFCHR 0020000
#define S_IFIFO 0010000
#define S_IFSOCK 0140000
#define S_IFLNK 0120000
#define S_IRWXUGO 0777

#define ICBTAG_FILE_TYPE_DIRECTORY 4
#define ICBTAG_FILE_TYPE_REALTIME 5
#define ICBTAG_FILE_TYPE_REGULAR 1
#define ICBTAG_FILE_TYPE_UNDEF 0
#define ICBTAG_FILE_TYPE_VAT20 20
#define ICBTAG_FILE_TYPE_BLOCK 6
#define ICBTAG_FILE_TYPE_CHAR 3
#define ICBTAG_FILE_TYPE_FIFO 7
#define ICBTAG_FILE_TYPE_SOCKET 8
#define ICBTAG_FILE_TYPE_SYMLINK 2
#define ICBTAG_FILE_TYPE_MAIN 9
#define ICBTAG_FILE_TYPE_MIRROR 10
#define ICBTAG_FILE_TYPE_BITMAP 11

#define MKDEV(ma,mi) ((ma)<<8 | (mi))

static inline uint16_t cpu_to_le16(uint16_t x) { return x; }
static inline uint32_t cpu_to_le32(uint32_t x) { return x; }
static inline uint64_t cpu_to_le64(uint64_t x) { return x; }
static inline uint16_t le16_to_cpu(uint16_t x) { return x; }
static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
static inline uint64_t le64_to_cpu(uint64_t x) { return x; }
static inline struct kernel_lb_addr lelb_to_cpu(struct kernel_lb_addr x) { return x; }

#define UDF_I(inode) ((struct udf_inode_info *)(inode))
#define UDF_SB(sb) ((struct udf_sb_info *)(sb))

static inline int S_ISCHR(unsigned int mode) { return (mode & S_IFMT) == S_IFCHR; }
static inline int S_ISBLK(unsigned int mode) { return (mode & S_IFMT) == S_IFBLK; }

static inline void read_lock(void *lock) {}
static inline void read_unlock(void *lock) {}
static inline void i_uid_write(struct inode *inode, unsigned int uid) { inode->i_uid = uid; }
static inline void i_gid_write(struct inode *inode, unsigned int gid) { inode->i_gid = gid; }
static inline int uid_valid(unsigned int uid) { return 1; }
static inline int gid_valid(unsigned int gid) { return 1; }
static inline int UDF_QUERY_FLAG(void *sb, unsigned int flag) { return 0; }
static inline void set_nlink(struct inode *inode, unsigned int nlink) { inode->i_nlink = nlink; }
static inline void inc_nlink(struct inode *inode) { inode->i_nlink++; }
static inline void make_bad_inode(struct inode *inode) {}
static inline void brelse(struct buffer_head *bh) {}
static inline void init_special_inode(struct inode *inode, unsigned int mode, unsigned int dev) {}
static inline void udf_debug(const char *fmt, ...) {}
static inline void udf_err(void *sb, const char *fmt, ...) {}

struct buffer_head *udf_read_ptagged(void *sb, struct kernel_lb_addr *loc, int offset, uint16_t *ident) { return NULL; }
int udf_alloc_i_data(struct inode *inode, unsigned int size) { return 0; }
int udf_disk_stamp_to_time(long *time, uint32_t stamp) { return 0; }
int udf_convert_permissions(struct fileEntry *fe) { return 0; }
void *udf_get_extendedattr(struct inode *inode, int type, int subtype) { return NULL; }

extern struct udf_dir_inode_operations udf_dir_inode_operations;
extern struct udf_dir_operations udf_dir_operations;
extern struct udf_file_inode_operations udf_file_inode_operations;
extern struct udf_file_operations udf_file_operations;
extern struct udf_symlink_inode_operations udf_symlink_inode_operations;
extern struct udf_adinicb_aops udf_adinicb_aops;
extern struct udf_aops udf_aops;
extern struct udf_symlink_aops udf_symlink_aops;
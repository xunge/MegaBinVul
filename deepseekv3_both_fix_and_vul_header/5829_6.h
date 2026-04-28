#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <sys/stat.h>

#define UDF_MAX_ICB_NESTING 5
#define TAG_IDENT_FE 0x0100
#define TAG_IDENT_EFE 0x0101
#define TAG_IDENT_USE 0x0102
#define TAG_IDENT_IE 0x0103
#define ICBTAG_FLAG_AD_MASK 0x7
#define ICBTAG_FLAG_AD_IN_ICB 0x1
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
#define ICBTAG_FILE_TYPE_MAIN 11
#define ICBTAG_FILE_TYPE_MIRROR 12
#define ICBTAG_FILE_TYPE_BITMAP 13
#define UDF_INVALID_MODE 0
#define EIO 5
#define ESTALE 116
#define UDF_FLAG_UID_IGNORE 0x01
#define UDF_FLAG_UID_SET 0x02
#define UDF_FLAG_GID_IGNORE 0x04
#define UDF_FLAG_GID_SET 0x08

#define S_IRWXUGO (S_IRWXU|S_IRWXG|S_IRWXO)

struct buffer_head {
    void *b_data;
};

struct address_space {
    void *a_ops;
};

struct super_block {
    unsigned int s_blocksize;
    unsigned int s_blocksize_bits;
};

struct inode {
    long i_ino;
    struct super_block *i_sb;
    unsigned int i_blocks;
    unsigned long i_size;
    unsigned int i_mode;
    unsigned int i_uid;
    unsigned int i_gid;
    struct timespec i_atime;
    struct timespec i_mtime;
    struct timespec i_ctime;
    unsigned int i_generation;
    struct address_space i_data;
    void *i_op;
    void *i_fop;
};

struct kernel_lb_addr {
    uint32_t logicalBlockNum;
    uint16_t partitionReferenceNum;
};

struct udf_part_map {
    uint32_t s_partition_len;
};

struct rwlock {
    int lock;
};

struct udf_sb_info {
    struct udf_part_map *s_partmaps;
    struct rwlock s_cred_lock;
    unsigned int s_umask;
    unsigned int s_gid;
    unsigned int s_uid;
    unsigned int s_fmode;
    unsigned int s_dmode;
    struct timespec s_record_time;
};

struct udf_inode_info {
    struct kernel_lb_addr i_location;
    unsigned int i_lenEAttr;
    unsigned int i_lenAlloc;
    unsigned int i_lenExtents;
    unsigned int i_next_alloc_block;
    unsigned int i_next_alloc_goal;
    unsigned int i_strat4096 : 1;
    unsigned int i_alloc_type : 3;
    unsigned int i_efe : 1;
    unsigned int i_use : 1;
    unsigned int i_unique;
    unsigned int i_checkpoint;
    struct timespec i_crtime;
    union {
        void *i_sad;
        void *i_lad;
        uint8_t *i_data;
    } i_ext;
};

struct timestamp {
    uint16_t typeAndTimezone;
    int16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t centiseconds;
    uint8_t hundredsOfMicroseconds;
    uint8_t microseconds;
};

struct lb_addr {
    uint32_t logicalBlockNum;
    uint16_t partitionReferenceNum;
};

struct long_ad {
    uint32_t extLength;
    struct lb_addr extLocation;
};

struct descTag {
    uint16_t tagIdent;
    uint16_t descVersion;
    uint8_t tagChecksum;
    uint8_t reserved;
    uint16_t tagSerialNum;
    uint16_t descCRC;
    uint16_t descCRCLength;
    uint32_t tagLocation;
};

struct icbTag {
    uint32_t priorRecordedNumDirectEntries;
    uint16_t strategyType;
    uint16_t strategyParameter;
    uint16_t numEntries;
    uint8_t reserved;
    uint8_t fileType;
    struct lb_addr parentICBLocation;
    uint16_t flags;
};

struct fileEntry {
    struct descTag descTag;
    struct icbTag icbTag;
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
    struct long_ad allocDescs;
    uint64_t uniqueID;
    uint32_t lengthExtendedAttr;
    uint32_t lengthAllocDescs;
    uint8_t implementationUse[0];
};

struct extendedFileEntry {
    struct descTag descTag;
    struct icbTag icbTag;
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
    uint64_t uniqueID;
    uint32_t lengthExtendedAttr;
    uint8_t allocDescs[0];
};

struct indirectEntry {
    struct descTag descTag;
    struct icbTag icbTag;
    struct long_ad indirectICB;
};

struct unallocSpaceEntry {
    struct descTag descTag;
    struct icbTag icbTag;
    uint32_t lengthAllocDescs;
    uint8_t allocDescs[0];
};

struct deviceSpec {
    uint32_t majorDeviceIdent;
    uint32_t minorDeviceIdent;
};

struct udf_dir_inode_operations {
    // dummy structure
};

struct udf_dir_operations {
    // dummy structure
};

struct udf_adinicb_aops {
    // dummy structure
};

struct udf_aops {
    // dummy structure
};

struct udf_file_inode_operations {
    // dummy structure
};

struct udf_file_operations {
    // dummy structure
};

struct udf_symlink_aops {
    // dummy structure
};

struct udf_symlink_inode_operations {
    // dummy structure
};

static inline uint16_t le16_to_cpu(uint16_t x) { return x; }
static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
static inline uint64_t le64_to_cpu(uint64_t x) { return x; }
static inline struct kernel_lb_addr lelb_to_cpu(struct lb_addr x) { 
    struct kernel_lb_addr ret;
    ret.logicalBlockNum = x.logicalBlockNum;
    ret.partitionReferenceNum = x.partitionReferenceNum;
    return ret;
}
static inline uint16_t cpu_to_le16(uint16_t x) { return x; }
static inline void read_lock(struct rwlock *lock) { (void)lock; }
static inline void read_unlock(struct rwlock *lock) { (void)lock; }
static inline void brelse(struct buffer_head *bh) { (void)bh; }
static inline void set_nlink(struct inode *inode, unsigned int nlink) { (void)inode; (void)nlink; }
static inline void inc_nlink(struct inode *inode) { (void)inode; }
static inline void i_uid_write(struct inode *inode, unsigned int uid) { (void)inode; (void)uid; }
static inline void i_gid_write(struct inode *inode, unsigned int gid) { (void)inode; (void)gid; }
static inline int uid_valid(unsigned int uid) { (void)uid; return 1; }
static inline int gid_valid(unsigned int gid) { (void)gid; return 1; }
static inline void init_special_inode(struct inode *inode, unsigned int mode, unsigned int dev) { (void)inode; (void)mode; (void)dev; }
static inline struct udf_inode_info *UDF_I(struct inode *inode) { return (struct udf_inode_info *)inode; }
static inline struct udf_sb_info *UDF_SB(struct super_block *sb) { return (struct udf_sb_info *)sb; }
static inline int udf_disk_stamp_to_time(struct timespec *time, struct timestamp ts) { (void)time; (void)ts; return 0; }
static inline unsigned int udf_convert_permissions(struct fileEntry *fe) { (void)fe; return 0; }
static inline int udf_alloc_i_data(struct inode *inode, int size) { (void)inode; (void)size; return 0; }
static inline int udf_file_entry_alloc_offset(struct inode *inode) { (void)inode; return 0; }
static inline void *udf_get_extendedattr(struct inode *inode, int type, int subtype) { (void)inode; (void)type; (void)subtype; return NULL; }
static inline struct buffer_head *udf_read_ptagged(struct super_block *sb, struct kernel_lb_addr *loc, int offset, uint16_t *ident) { (void)sb; (void)loc; (void)offset; (void)ident; return NULL; }
static inline void udf_debug(const char *fmt, ...) { (void)fmt; }
static inline void udf_err(struct super_block *sb, const char *fmt, ...) { (void)sb; (void)fmt; }
static inline int UDF_QUERY_FLAG(struct super_block *sb, int flag) { (void)sb; (void)flag; return 0; }
#define MKDEV(ma,mi) ((ma)<<8 | (mi))

static struct udf_dir_inode_operations udf_dir_inode_operations;
static struct udf_dir_operations udf_dir_operations;
static struct udf_adinicb_aops udf_adinicb_aops;
static struct udf_aops udf_aops;
static struct udf_file_inode_operations udf_file_inode_operations;
static struct udf_file_operations udf_file_operations;
static struct udf_symlink_aops udf_symlink_aops;
static struct udf_symlink_inode_operations udf_symlink_inode_operations;
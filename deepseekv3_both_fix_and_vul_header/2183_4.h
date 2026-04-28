#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef uint64_t sector_t;
typedef uint16_t __le16;
typedef uint16_t u16;

struct super_block {
    unsigned long s_blocksize;
    void *s_fs_info;
};

struct buffer_head {
    char *b_data;
};

struct kernel_lb_addr {
    uint16_t logicalBlockNum;
    uint16_t partitionReferenceNum;
    uint32_t extLength;
};

struct udf_sb_info {
    int s_partitions;
    struct udf_part_map *s_partmaps;
};

struct udf_meta_data {
    uint32_t s_meta_file_loc;
    uint32_t s_mirror_file_loc;
    uint32_t s_bitmap_file_loc;
    uint32_t s_alloc_unit_size;
    uint16_t s_align_unit_size;
    uint16_t s_flags;
};

struct udf_part_map {
    int s_partition_type;
    uint16_t s_volumeseqnum;
    uint16_t s_partition_num;
    void *s_partition_func;
    union {
        struct {
            uint16_t s_packet_len;
            struct buffer_head *s_spar_map[8];
        } s_sparing;
        struct udf_meta_data s_metadata;
    } s_type_specific;
};

struct logicalVolDesc {
    uint32_t mapTableLength;
    uint32_t numPartitionMaps;
    char partitionMaps[0];
    char logicalVolContentsUse[0];
    struct kernel_lb_addr integritySeqExt;
};

struct genericPartitionMap {
    uint8_t partitionMapType;
    uint8_t partitionMapLength;
};

struct genericPartitionMap1 {
    uint8_t partitionMapType;
    uint8_t partitionMapLength;
    uint16_t volSeqNum;
    uint16_t partitionNum;
};

struct udfPartitionMap2 {
    uint8_t partitionMapType;
    uint8_t partitionMapLength;
    uint16_t volSeqNum;
    uint16_t partitionNum;
    struct {
        char ident[23];
        char identSuffix[8];
    } partIdent;
};

struct sparablePartitionMap {
    uint8_t partitionMapType;
    uint8_t partitionMapLength;
    uint16_t packetLength;
    uint8_t numSparingTables;
    uint32_t locSparingTable[4];
};

struct sparingTable {
    struct {
        char ident[23];
    } sparingIdent;
};

struct metadataPartitionMap {
    uint8_t partitionMapType;
    uint8_t partitionMapLength;
    uint16_t partitionNum;
    uint32_t metadataFileLoc;
    uint32_t metadataMirrorFileLoc;
    uint32_t metadataBitmapFileLoc;
    uint32_t allocUnitSize;
    uint16_t alignUnitSize;
    uint8_t flags;
    struct {
        char ident[23];
        char identSuffix[8];
    } partIdent;
};

struct long_ad {
    struct kernel_lb_addr extLocation;
};

#define UDF_SB(sb) ((struct udf_sb_info *)((sb)->s_fs_info))
#define TAG_IDENT_LVD 0x0006
#define UDF_ID_VIRTUAL "NSR02"
#define UDF_ID_SPARABLE "*UDF Sparable Partition"
#define UDF_ID_METADATA "*UDF Metadata Partition"
#define UDF_ID_SPARING "*UDF Sparing Table"
#define UDF_TYPE1_MAP15 1
#define UDF_VIRTUAL_MAP15 2
#define UDF_VIRTUAL_MAP20 3
#define UDF_SPARABLE_MAP15 4
#define UDF_METADATA_MAP25 5
#define MF_DUPLICATE_MD 0x01

#define BUG_ON(condition) do { if (condition) abort(); } while (0)

static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
static inline uint16_t le16_to_cpu(uint16_t x) { return x; }
static inline uint16_t cpu_to_le16(uint16_t x) { return x; }

static inline struct kernel_lb_addr lelb_to_cpu(struct kernel_lb_addr in) {
    struct kernel_lb_addr out;
    out.logicalBlockNum = le16_to_cpu(in.logicalBlockNum);
    out.partitionReferenceNum = le16_to_cpu(in.partitionReferenceNum);
    out.extLength = le32_to_cpu(in.extLength);
    return out;
}

static inline struct kernel_lb_addr leea_to_cpu(struct kernel_lb_addr in) {
    return lelb_to_cpu(in);
}

extern int udf_sb_alloc_partition_maps(struct super_block *sb, uint32_t count);
extern struct buffer_head *udf_read_tagged(struct super_block *sb, sector_t block,
                                         sector_t dest, uint16_t *ident);
extern void udf_load_logicalvolint(struct super_block *sb, struct kernel_lb_addr loc);
extern void udf_err(struct super_block *sb, const char *fmt, ...);
extern void udf_debug(const char *fmt, ...);
extern int udf_get_pblock_virt15(struct super_block *sb, long block, int partition);
extern int udf_get_pblock_virt20(struct super_block *sb, long block, int partition);
extern int udf_get_pblock_spar15(struct super_block *sb, long block, int partition);
extern int udf_get_pblock_meta25(struct super_block *sb, long block, int partition);
extern void brelse(struct buffer_head *bh);
#include <stdint.h>
#include <string.h>

typedef uint32_t sector_t;
typedef uint16_t u16;
typedef uint16_t __le16;

struct super_block {
    void *s_fs_info;
    unsigned long s_blocksize;
};

struct udf_sb_info {
    int s_partitions;
    struct udf_part_map *s_partmaps;
};

struct buffer_head {
    void *b_data;
};

struct kernel_lb_addr {
    uint32_t logicalBlockNum;
    uint16_t partitionReferenceNum;
};

struct extent_ad {
    uint32_t extLength;
};

struct udf_meta_data {
    uint32_t s_meta_file_loc;
    uint32_t s_mirror_file_loc;
    uint32_t s_bitmap_file_loc;
    uint32_t s_alloc_unit_size;
    uint16_t s_align_unit_size;
    uint16_t s_flags;
};

struct logicalVolDesc {
    uint32_t numPartitionMaps;
    uint32_t mapTableLength;
    uint8_t partitionMaps[0];
    uint8_t logicalVolContentsUse[0];
    struct extent_ad integritySeqExt;
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
        uint8_t identSuffix[0];
    } partIdent;
};

struct udf_part_map {
    int s_partition_type;
    uint16_t s_volumeseqnum;
    uint16_t s_partition_num;
    void *s_partition_func;
    union {
        struct {
            uint16_t s_packet_len;
            struct buffer_head *s_spar_map[0];
        } s_sparing;
        struct udf_meta_data s_metadata;
    } s_type_specific;
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
        uint8_t identSuffix[0];
    } partIdent;
};

struct sparablePartitionMap {
    uint8_t partitionMapType;
    uint8_t partitionMapLength;
    uint16_t packetLength;
    uint8_t numSparingTables;
    uint32_t locSparingTable[0];
};

struct sparingTable {
    struct {
        char ident[23];
    } sparingIdent;
};

struct long_ad {
    struct kernel_lb_addr extLocation;
};

struct extent_position {
    uint32_t dummy;
};

#define UDF_SB(sb) ((struct udf_sb_info *)((sb)->s_fs_info))
#define TAG_IDENT_LVD 0x0006
#define UDF_TYPE1_MAP15 1
#define UDF_VIRTUAL_MAP15 2
#define UDF_VIRTUAL_MAP20 3
#define UDF_SPARABLE_MAP15 4
#define UDF_METADATA_MAP25 5
#define UDF_ID_VIRTUAL "*UDF Virtual Partition"
#define UDF_ID_SPARABLE "*UDF Sparable Partition"
#define UDF_ID_METADATA "*UDF Metadata Partition"
#define UDF_ID_SPARING "*UDF Sparing Table"
#define MF_DUPLICATE_MD 0x01
#define BUG_ON(cond) do { if (cond) {} } while (0)

static inline uint32_t le32_to_cpu(uint32_t val) { return val; }
static inline uint16_t le16_to_cpu(uint16_t val) { return val; }
static inline struct kernel_lb_addr lelb_to_cpu(struct kernel_lb_addr in) { return in; }
static inline struct extent_position leea_to_cpu(struct extent_ad in) { struct extent_position pos = {0}; return pos; }

static inline void brelse(struct buffer_head *bh) {}
static inline void udf_debug(const char *fmt, ...) {}
static inline void *udf_get_pblock_virt15(struct super_block *sb, uint32_t block, uint16_t partition, uint32_t offset) { return NULL; }
static inline void *udf_get_pblock_virt20(struct super_block *sb, uint32_t block, uint16_t partition, uint32_t offset) { return NULL; }
static inline void *udf_get_pblock_spar15(struct super_block *sb, uint32_t block, uint16_t partition, uint32_t offset) { return NULL; }
static inline void *udf_get_pblock_meta25(struct super_block *sb, uint32_t block, uint16_t partition, uint32_t offset) { return NULL; }
static inline int udf_sb_alloc_partition_maps(struct super_block *sb, uint32_t num) { return 0; }
static inline void udf_load_logicalvolint(struct super_block *sb, struct extent_position pos) {}
static inline struct buffer_head *udf_read_tagged(struct super_block *sb, sector_t block1, sector_t block2, uint16_t *ident) { return NULL; }
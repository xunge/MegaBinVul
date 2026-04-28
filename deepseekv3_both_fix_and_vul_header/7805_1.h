#include <stdint.h>
#include <string.h>

struct buffer_head {
    uint8_t *b_data;
};

struct udf_fileident_bh {
    struct buffer_head *sbh;
    struct buffer_head *ebh;
    int soffset;
    int eoffset;
};

struct tag {
    uint16_t descCRC;
    uint16_t descCRCLength;
    uint8_t tagChecksum;
};

struct fileIdentDesc {
    struct tag descTag;
    uint16_t lengthOfImpUse;
    uint8_t lengthFileIdent;
    uint8_t impUse[0];
};

struct inode;
struct udf_inode_info {
    int i_alloc_type;
};

#define UDF_I(inode) ((struct udf_inode_info *)(inode))
#define ICBTAG_FLAG_AD_IN_ICB 0

static inline uint16_t le16_to_cpu(uint16_t val) { return val; }
static inline uint16_t cpu_to_le16(uint16_t val) { return val; }

uint16_t crc_itu_t(uint16_t crc, const uint8_t *buffer, size_t len);
uint8_t udf_tag_checksum(struct tag *t);
uint8_t *udf_get_fi_ident(struct fileIdentDesc *fi);

void mark_inode_dirty(struct inode *inode);
void mark_buffer_dirty_inode(struct buffer_head *bh, struct inode *inode);
void inode_inc_iversion(struct inode *inode);
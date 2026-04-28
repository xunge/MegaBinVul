#include <stdint.h>

typedef uint32_t __u32;

struct kernel_lb_addr {
    uint32_t logicalBlockNum;
    uint16_t partitionReferenceNum;
};

struct inode {
    unsigned long i_generation;
};

struct udf_inode_info {
    struct kernel_lb_addr i_location;
};

struct fid {
    struct {
        uint32_t block;
        uint16_t partref;
        uint32_t generation;
        uint32_t parent_block;
        uint16_t parent_partref;
        uint32_t parent_generation;
    } udf;
};

#define UDF_I(inode) ((struct udf_inode_info *)(inode))
#define FILEID_UDF_WITHOUT_PARENT 0
#define FILEID_UDF_WITH_PARENT 1
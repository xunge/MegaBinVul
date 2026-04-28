#include <stdint.h>
#include <sys/stat.h>

typedef int64_t loff_t;

struct ext4_inode {
    uint16_t i_mode;
    uint32_t i_size_lo;
    uint32_t i_size_high;
};

#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)
#include <stddef.h>
#include <stdint.h>

typedef uint8_t u8;

extern size_t ecryptfs_max_decoded_size(size_t src_size);
extern unsigned char filename_rev_map[];
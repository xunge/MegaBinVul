#include <stddef.h>
#include <errno.h>

struct super_block;
extern size_t romfs_maxsize(struct super_block *sb);
#ifdef CONFIG_ROMFS_ON_MTD
extern int romfs_mtd_read(struct super_block *sb, unsigned long pos, void *buf, size_t buflen);
#endif
#ifdef CONFIG_ROMFS_ON_BLOCK
extern int romfs_blk_read(struct super_block *sb, unsigned long pos, void *buf, size_t buflen);
#endif

#define EIO 5
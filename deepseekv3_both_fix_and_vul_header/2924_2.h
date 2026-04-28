#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>

#define BDEVNAME_SIZE 32
#define FMODE_READ 1
#define FMODE_WRITE 2
#define FMODE_EXCL 4
#define KERN_ERR 3

struct block_device;
struct super_block;

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

static struct block_device *blkdev_get_by_dev(dev_t dev, int mode, struct super_block *sb);
static void ext3_msg(struct super_block *sb, int level, const char *fmt, ...);
static char *__bdevname(dev_t dev, char *buf);
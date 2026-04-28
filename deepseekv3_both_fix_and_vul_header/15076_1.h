#include <stddef.h>
#include <sys/types.h>

#define FMODE_WRITE 0x1
#define REQ_TYPE_BLOCK_PC 0
#define BLK_DEFAULT_SG_TIMEOUT (60 * 1000)
#define BLK_MIN_SG_TIMEOUT (1 * 1000)
#define EFAULT 14
#define EPERM 1

typedef unsigned int fmode_t;

struct request_queue {
    void *cmd_filter;
    unsigned long sg_timeout;
};

struct request {
    unsigned char *cmd;
    unsigned int cmd_len;
    int cmd_type;
    unsigned long timeout;
};

struct sg_io_hdr {
    unsigned char *cmdp;
    unsigned int cmd_len;
    unsigned int timeout;
};

unsigned long msecs_to_jiffies(unsigned int msecs);
int blk_verify_command(void *cmd_filter, unsigned char *cmd, int write);
int copy_from_user(void *to, const void *from, unsigned long n);
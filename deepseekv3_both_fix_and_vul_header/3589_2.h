#include <stddef.h>
#include <string.h>

struct floppy_raw_cmd {
    struct floppy_raw_cmd *next;
    unsigned long flags;
    unsigned int cmd_count;
    unsigned char cmd[16];
    unsigned int length;
    unsigned char reply[16];
    int resultcode;
    unsigned int buffer_length;
    char *kernel_data;
    unsigned char rate;
    unsigned char data[];
};

#define GFP_USER 0
#define ENOMEM 1
#define EFAULT 2
#define EINVAL 3

#define FD_RAW_READ 0x01
#define FD_RAW_WRITE 0x02
#define FD_RAW_MORE 0x04

static void *kmalloc(size_t size, int flags);
static int copy_from_user(void *to, const void *from, size_t n);
static void *fd_dma_mem_alloc(unsigned int length);
static void fallback_on_nodma_alloc(char **ptr, unsigned int length);
static int fd_copyin(void *user, void *kernel, size_t length);

#define __user
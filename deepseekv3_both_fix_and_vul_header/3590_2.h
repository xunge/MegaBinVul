#include <string.h>

struct floppy_raw_cmd {
    unsigned int flags;
    unsigned int buffer_length;
    int length;
    void *data;
    void *kernel_data;
    struct floppy_raw_cmd *next;
};

#define FD_RAW_READ 0x01
#define EFAULT 14

#define __user
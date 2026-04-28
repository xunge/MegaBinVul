#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define DM_MAX_TARGETS 1024
#define DM_MAX_TARGET_PARAMS 1024
#define DM_SECURE_DATA_FLAG (1 << 0)
#define DM_WIPE_BUFFER (1 << 1)
#define DM_PARAMS_MALLOC (1 << 2)
#define IOCTL_FLAGS_NO_PARAMS (1 << 0)
#define GFP_NOIO 0
#define __GFP_HIGH 0
#define unlikely(x) (x)

#define EFAULT 1
#define EINVAL 2
#define ENOMEM 3

struct dm_ioctl {
    unsigned int version;
    unsigned int data_size;
    unsigned int flags;
    char data[];
};

#define __user

void DMERR(const char *fmt, ...);
void free_params(struct dm_ioctl *dmi, int size, int flags);
void *kvmalloc(size_t size, int flags);
int copy_from_user(void *to, const void *from, size_t n);
int clear_user(void *to, size_t n);
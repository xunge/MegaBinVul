#include <stddef.h>
#include <sys/uio.h>

typedef struct SCSIRequest {
    /* dummy definition since actual content is unknown */
    int dummy;
} SCSIRequest;

typedef struct SCSIDiskReq {
    SCSIRequest req;
    struct iovec iov;
} SCSIDiskReq;

#define DO_UPCAST(type, field, obj) \
    ((type *) ((char *)(obj) - offsetof(type, field)))

extern void qemu_vfree(void *ptr);
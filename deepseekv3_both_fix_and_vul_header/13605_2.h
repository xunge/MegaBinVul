#include <sys/ipc.h>
#include <sys/shm.h>
#include <stddef.h>

typedef struct XShmSegmentInfo {
    int shmid;
    char *shmaddr;
    int readOnly;
} XShmSegmentInfo;

struct xlib_displaytarget {
    XShmSegmentInfo shminfo;
};

#define False 0
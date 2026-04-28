#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/time.h>
#include <limits.h>
#include <string.h>

typedef int Status;
typedef unsigned long CARD32;
typedef unsigned int XvPortID;

typedef struct {
    int tz_minuteswest;
    int tz_dsttime;
} timezone;

typedef struct {
    long tv_sec;
    long tv_usec;
} timeval;

typedef struct {
    int major;
    int minor;
    int patchLevel;
    int isLocal;
    unsigned int length;
    unsigned int nameLen;
    unsigned int busIDLen;
} xvmcGetDRInfoReply;

typedef struct {
    XvPortID port;
    CARD32 magic;
    int shmKey;
} xvmcGetDRInfoReq;

typedef struct _XExtDisplayInfo {
    /* Placeholder structure */
} XExtDisplayInfo;

typedef struct _Display {
    /* Placeholder structure */
} Display;

typedef struct {
    /* Placeholder for xReply structure */
} xReply;

#define BadImplementation 0
#define Success 1
#define xFalse 0
#define GetDRInfo 0
#define IPC_CREAT 01000

extern XExtDisplayInfo *xvmc_find_display(Display *dpy);
extern void XvMCCheckExtension(Display *dpy, XExtDisplayInfo *info, int status);
extern void LockDisplay(Display *dpy);
extern void UnlockDisplay(Display *dpy);
extern void SyncHandle(void);
extern void XvMCGetReq(int request, xvmcGetDRInfoReq *req);
extern int _XReply(Display *dpy, xReply *reply, int extra, int discard);
extern void _XRead(Display *dpy, char *data, unsigned long length);
extern void _XEatDataWords(Display *dpy, unsigned long length);
extern void *Xmalloc(size_t size);
extern void XFree(void *ptr);
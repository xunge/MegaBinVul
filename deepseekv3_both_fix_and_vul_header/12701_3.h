#include <stdbool.h>
#include <limits.h>
#include <string.h>

typedef struct _XDisplay Display;
typedef unsigned short CARD16;
typedef unsigned int Bool;
#define _Xconst const

typedef struct {
    char pad[24];
    int major_opcode;
    int first_event;
    int first_error;
    Bool present;
} xQueryExtensionReply;

typedef struct {
    CARD16 nbytes;
    unsigned length;
} xQueryExtensionReq;

typedef struct {
    char pad[24];
} xReply;

#define QueryExtension 98
#define xTrue 1

void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);
void GetReq(int type, xQueryExtensionReq *req);
void _XSend(Display *dpy, const char *name, long length);
int _XReply(Display *dpy, xReply *rep, int extra, Bool discard);
void SyncHandle(void);
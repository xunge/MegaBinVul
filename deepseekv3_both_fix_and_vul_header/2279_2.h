#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct _ClientRec {
    void *requestBuffer;
    unsigned int sequence;
    unsigned int requestLength;
    int errorValue;
} *ClientPtr;

typedef struct _ShmDescRec *ShmDescPtr;

typedef struct _ShmDescRec {
    int is_fd;
    void *addr;
    int refcnt;
    int writable;
    size_t size;
    void *busfault;
    ShmDescPtr next;
} ShmDescRec;

typedef struct {
    int type;
    int nfd;
    unsigned int sequenceNumber;
    unsigned int length;
} xShmCreateSegmentReply;

typedef struct {
    int readOnly;
    size_t size;
    int shmseg;
} xShmCreateSegmentReq;

#define X_Reply 1
#define xTrue 1
#define xFalse 0
#define BadValue 2
#define BadAlloc 3
#define BadAccess 4
#define BadLength 5
#define Success 0
#define RT_NONE 0
#define TRUE 1
#define PROT_READ 0x1
#define PROT_WRITE 0x2
#define MAP_SHARED 0x01
#define ShmSegType 1

extern int shm_tmpfile(void);
extern void *busfault_register_mmap(void *addr, size_t size, void (*notify)(void *), void *priv);
extern void ShmBusfaultNotify(void *);
extern ShmDescPtr Shmsegs;
extern int AddResource(int id, int type, void *value);
extern void FreeResource(int id, int type);
extern int WriteFdToClient(ClientPtr client, int fd, int closeit);
extern int WriteToClient(ClientPtr client, size_t size, void *data);

#define REQUEST(x) x *stuff = (x *) client->requestBuffer
#define REQUEST_SIZE_MATCH(x) \
    if (client->requestLength != sizeof(x)) { \
        client->errorValue = client->requestLength; \
        return BadLength; \
    }
#include <stddef.h>
#include <stdint.h>

#define MAXDEVICES 256
#define BadLength 0
#define Success 0
#define XIAddMaster 1
#define XIRemoveMaster 2
#define XIDetachSlave 3
#define XIAttachSlave 4

typedef struct {
    int type;
    int length;
} xXIAnyHierarchyChangeInfo;

typedef struct {
    int name_len;
} xXIAddMasterInfo;

typedef struct {
    int dummy;
} xXIRemoveMasterInfo;

typedef struct {
    int dummy;
} xXIDetachSlaveInfo;

typedef struct {
    int dummy;
} xXIAttachSlaveInfo;

typedef struct {
    int length;
    int num_changes;
    char data[];
} xXIChangeHierarchyReq;

typedef struct ClientRec {
    void *data;
} *ClientPtr;

#define REQUEST(type) type *stuff = (type *)(client->data)
#define REQUEST_AT_LEAST_SIZE(type) (void)0
#define SWAPIF(expr) (void)0
#define swaps(ptr) (*(ptr))

int add_master(ClientPtr client, xXIAddMasterInfo *c, int *flags);
int remove_master(ClientPtr client, xXIRemoveMasterInfo *r, int *flags);
int detach_slave(ClientPtr client, xXIDetachSlaveInfo *c, int *flags);
int attach_slave(ClientPtr client, xXIAttachSlaveInfo *c, int *flags);
void XISendDeviceHierarchyEvent(int *flags);
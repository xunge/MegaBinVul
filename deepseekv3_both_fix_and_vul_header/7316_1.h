#include <stdlib.h>
#include <string.h>

typedef struct _virStoragePoolObj virStoragePoolObj;
typedef struct _virStoragePoolDef {
    char *name;
    char *uuid;
} virStoragePoolDef;
typedef struct _virStoragePool virStoragePool;
typedef virStoragePool *virStoragePoolPtr;
typedef struct _virConnect virConnect;
typedef virConnect *virConnectPtr;

extern virStoragePoolObj *virStoragePoolObjListSearch(void *pools, 
                                                     int (*callback)(void *, void *), 
                                                     void *data);
extern virStoragePoolDef *virStoragePoolObjGetDef(virStoragePoolObj *obj);
extern int virStoragePoolLookupByTargetPathEnsureACL(virConnectPtr conn, virStoragePoolDef *def);
extern virStoragePoolPtr virGetStoragePool(virConnectPtr conn, const char *name, 
                                          const char *uuid, void *opaque1, void *opaque2);
extern void virStoragePoolObjEndAPI(virStoragePoolObj **obj);
extern void virReportError(int code, const char *fmt, ...);
extern char *virFileSanitizePath(const char *path);

#define STREQ(a, b) (strcmp(a, b) == 0)
#define _(_s) _s

typedef struct {
    void *pools;
} driver_t;
extern driver_t *driver;

#define g_autofree __attribute__((cleanup(free)))

#define VIR_ERR_NO_STORAGE_POOL 123

int storagePoolLookupByTargetPathCallback(void *data, void *userdata);
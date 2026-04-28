#include <stdlib.h>

typedef struct qemuMonitor *qemuMonitorPtr;

struct virDomainDef {
    char *name;
};

struct virDomainObj {
    struct virDomainDef *def;
    void *privateData;
};
typedef struct virDomainObj *virDomainObjPtr;

struct virQEMUDriver {
    void *workerPool;
};
typedef struct virQEMUDriver *virQEMUDriverPtr;

struct qemuDomainObjPrivate {
    int beingDestroyed;
};
typedef struct qemuDomainObjPrivate *qemuDomainObjPrivatePtr;

struct qemuProcessEvent {
    int eventType;
    virDomainObjPtr vm;
};

#define QEMU_PROCESS_EVENT_MONITOR_EOF 0

#define VIR_DEBUG(fmt, ...)
#define virObjectLock(obj)
#define virObjectUnlock(obj)
#define virObjectRef(obj) (obj)
#define virObjectUnref(obj)
#define g_new0(type, n) calloc(n, sizeof(type))
#define virThreadPoolSendJob(pool, flags, data) 0

static void qemuMonitorUnregister(qemuMonitorPtr mon) {}
static void qemuDomainDestroyNamespace(virQEMUDriverPtr driver, virDomainObjPtr vm) {}
static void qemuProcessEventFree(struct qemuProcessEvent *event) { free(event); }
#include <stdint.h>

typedef struct _virConnect virConnect;
typedef virConnect *virConnectPtr;

typedef struct _virConnectDriver virConnectDriver;

struct _virConnect {
    unsigned int flags;
    virConnectDriver *driver;
};

struct _virConnectDriver {
    int (*domainGetTime)(void *dom, long long *seconds,
                         unsigned int *nseconds, unsigned int flags);
};

struct _virDomain {
    virConnectPtr conn;
};

typedef struct _virDomain virDomain;
typedef virDomain *virDomainPtr;

#define VIR_DOMAIN_DEBUG(dom, ...)
#define virResetLastError()
#define virCheckDomainReturn(dom, retval)
#define virCheckReadOnlyGoto(flags, label)
#define virReportUnsupportedError()
#define virDispatchError(conn)
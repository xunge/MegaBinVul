#include <stdlib.h>
#include <string.h>

#define VIR_ERR_INTERNAL_ERROR 1
#define _(x) x

typedef struct virSecurityManager virSecurityManager;
typedef struct virSecuritySELinuxData virSecuritySELinuxData;

struct virSecuritySELinuxData {
    void *mcs;
};

extern void *virHashLookup(void *hash, const char *key);
extern virSecuritySELinuxData *virSecurityManagerGetPrivateData(virSecurityManager *mgr);
extern int virRandomInt(int upper_bound);
extern void virReportError(int code, const char *fmt, ...);
extern void VIR_DEBUG(const char *fmt, ...);
extern void VIR_FREE(void *ptr);
extern char *g_strdup_printf(const char *fmt, ...);
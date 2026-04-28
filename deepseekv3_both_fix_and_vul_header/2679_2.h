#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <grp.h>
#include <errno.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

enum nss_status {
    NSS_STATUS_SUCCESS,
    NSS_STATUS_NOTFOUND,
    NSS_STATUS_UNAVAIL,
    NSS_STATUS_TRYAGAIN
};

typedef struct sd_bus sd_bus;
typedef struct sd_bus_error {
    const char *name;
    const char *message;
    int _need_free;
} sd_bus_error;
typedef struct sd_bus_message sd_bus_message;

#define _cleanup_bus_error_free_ 
#define _cleanup_bus_message_unref_ 
#define _cleanup_bus_flush_close_unref_ 
#define SD_BUS_ERROR_NULL {0}
#define BUS_ERROR_NO_SUCH_GROUP_MAPPING "org.freedesktop.machine1.NoSuchGroupMapping"
#define GID_MAX UINT32_MAX

static inline const char *startswith(const char *s, const char *prefix) {
    size_t l = strlen(prefix);
    return strncmp(s, prefix, l) == 0 ? s + l : NULL;
}

static inline int parse_gid(const char *s, uid_t *ret) {
    unsigned long gid;
    char *end;
    gid = strtoul(s, &end, 10);
    if (*end != '\0' || gid > GID_MAX)
        return -EINVAL;
    *ret = (uid_t) gid;
    return 0;
}

static inline bool machine_name_is_valid(const char *s) {
    return s && *s;
}

static inline char *strndupa(const char *s, size_t n) {
    char *d = alloca(n + 1);
    strncpy(d, s, n);
    d[n] = '\0';
    return d;
}

static inline void memzero(void *p, size_t l) {
    memset(p, 0, l);
}

int sd_bus_open_system(sd_bus **bus) { return -1; }
int sd_bus_call_method(sd_bus *bus, const char *destination, const char *path, 
                      const char *interface, const char *method, 
                      sd_bus_error *error, sd_bus_message **reply, 
                      const char *types, ...) { return -1; }
int sd_bus_message_read(sd_bus_message *m, const char *types, ...) { return -1; }
int sd_bus_error_has_name(const sd_bus_error *e, const char *name) { return 0; }
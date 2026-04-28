#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <alloca.h>

#define HOST_NAME_MAX 64

enum nss_status {
    NSS_STATUS_SUCCESS,
    NSS_STATUS_NOTFOUND,
    NSS_STATUS_TRYAGAIN,
    NSS_STATUS_UNAVAIL
};

#define BUS_ERROR_NO_SUCH_USER_MAPPING "org.freedesktop.machine1.NoSuchUserMapping"

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

#define SD_BUS_ERROR_NULL { .name = NULL, .message = NULL, ._need_free = 0 }

static inline const char *startswith(const char *s, const char *prefix) {
    size_t l = strlen(prefix);
    return strncmp(s, prefix, l) == 0 ? s + l : NULL;
}

static inline char *strndupa(const char *s, size_t n) {
    char *d = alloca(n + 1);
    memcpy(d, s, n);
    d[n] = 0;
    return d;
}

static inline bool machine_name_is_valid(const char *name) {
    return true;
}

static inline int parse_uid(const char *s, uid_t *ret) {
    return 0;
}

static inline int sd_bus_open_system(sd_bus **bus) {
    return -1;
}

static inline int sd_bus_call_method(sd_bus *bus, const char *destination, 
                                    const char *path, const char *interface,
                                    const char *method, sd_bus_error *error,
                                    sd_bus_message **reply, const char *types, ...) {
    return -1;
}

static inline bool sd_bus_error_has_name(sd_bus_error *error, const char *name) {
    return false;
}

static inline int sd_bus_message_read(sd_bus_message *m, const char *types, ...) {
    return -1;
}
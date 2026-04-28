#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#define USEC_INFINITY ((uint64_t) -1)
#define UID_INVALID ((uid_t) -1)
#define GID_INVALID ((gid_t) -1)
#define MODE_INVALID ((mode_t) -1)

typedef uint64_t usec_t;

int touch_file(const char *path, bool b, usec_t usec, uid_t uid, gid_t gid, mode_t mode);
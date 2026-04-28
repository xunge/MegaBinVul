#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>

#define MODE_INVALID ((mode_t)-1)
#define UID_INVALID ((uid_t)-1)
#define GID_INVALID ((gid_t)-1)
#define USEC_INFINITY ((usec_t)-1)

typedef unsigned long long usec_t;

#define _cleanup_close_ __attribute__((cleanup(close_fd)))
static inline void close_fd(int *fd) { if (*fd >= 0) close(*fd); }

int mkdir_parents(const char *path, mode_t mode);
void timespec_store(struct timespec *ts, usec_t u);
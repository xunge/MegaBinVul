#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define streq(a,b) (strcmp((a),(b)) == 0)

static inline void close_nointr_nofail(int fd) {
    (void) close(fd);
}
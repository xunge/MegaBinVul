#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

typedef struct Server {
    struct {
        char *path;
        void *metrics;
    } system_storage;
    struct {
        int enabled;
        size_t threshold_bytes;
    } compress;
    int seal;
    void *user_journals;
    void *mmap;
    void *deferred_closes;
} Server;

typedef struct JournalFile JournalFile;
typedef struct dirent dirent;

#define _cleanup_closedir_ __attribute__((cleanup(cleanup_closedir)))
#define _cleanup_free_ __attribute__((cleanup(cleanup_free)))
#define _cleanup_close_ __attribute__((cleanup(cleanup_close)))

#define JOURNAL_LOG_RATELIMIT 0
#define LOG_DEBUG 0
#define LOG_WARNING 0
#define JOURNAL_COMPRESS 0
#define JOURNAL_SEAL 0

#define UID_TO_PTR(x) ((void*)(uintptr_t)(x))
#define TAKE_FD(x) (x)
#define TAKE_PTR(x) (x)
#define IN_SET(x, ...) 0

static inline void cleanup_closedir(DIR **d) { if (*d) closedir(*d); }
static inline void cleanup_free(void *p) { free(*(void**)p); }
static inline void cleanup_close(int *fd) { if (*fd >= 0) close(*fd); }
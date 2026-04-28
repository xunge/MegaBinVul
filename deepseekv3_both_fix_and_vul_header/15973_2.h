#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/prctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <features.h>

#define _cleanup_close_pair_ 
#define _cleanup_(x)
#define _cleanup_free_ 
#define _cleanup_fclose_ 

typedef struct JsonVariant JsonVariant;
#define json_variant_unrefp

#define RET_NERRNO(x) (-(x))
#define COREDUMP_PIPE_MAX (1024 * 1024)
#define FORK_RESET_SIGNALS 0
#define FORK_CLOSE_ALL_FDS 0
#define FORK_NEW_MOUNTNS 0
#define FORK_MOUNTNS_SLAVE 0
#define FORK_NEW_USERNS 0
#define FORK_WAIT 0
#define FORK_REOPEN_LOG 0
#define PR_SET_DUMPABLE 4
#define JSON_FORMAT_FLUSH 0
#define F_SETPIPE_SZ 1031

#define TAKE_PTR(x) (x)
#define safe_close(x) (close(x), -1)
#define take_fdopen(x, y) fdopen(*(x), y)
#define safe_fork_full(a, b, c, d, e, f, g, h) (-1)
#define loop_write(a, b, c, d) (-1)
#define read_full_stream(a, b, c) (-1)
#define json_parse_file(a, b, c, d, e, f) (-1)
#define json_variant_dump(a, b, c, d) (-1)
#define log_warning(...)
#define log_warning_errno(...)

static inline int pipe2(int pipefd[2], int flags) { return -1; }
static inline int dlopen_dw(void) { return -1; }
static inline int dlopen_elf(void) { return -1; }
static inline int parse_elf(int fd, const char *executable, char **buf, JsonVariant **package_metadata) { return -1; }
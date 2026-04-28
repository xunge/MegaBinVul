#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

#define LOG_INFO 6

typedef struct thread_t thread_t;
typedef struct notify_fifo_t {
    char *name;
    int fd;
    bool created_fifo;
    char *script;
} notify_fifo_t;

extern thread_t *master;
extern void log_message(int level, const char *fmt, ...);
extern void notify_fifo_exec(thread_t *master, int (*script_exit)(thread_t *), notify_fifo_t *fifo, char *script);
#define FREE(ptr) free(ptr)
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

typedef struct {
    int __used;
    int __allocated;
    struct __spawn_action *__actions;
} posix_spawn_file_actions_t;

enum {
    spawn_do_open
};

struct __spawn_action {
    int tag;
    union {
        struct {
            int fd;
            const char *path;
            int oflag;
            mode_t mode;
        } open_action;
    } action;
};

extern long int __sysconf (int name);
extern int __posix_spawn_file_actions_realloc (posix_spawn_file_actions_t *file_actions);
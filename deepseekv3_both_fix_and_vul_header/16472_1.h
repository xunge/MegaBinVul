#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

typedef void* gpointer;

typedef struct {
    int from;
    int to;
    int final;
} FdMapEntry;

typedef struct {
    FdMapEntry *fd_map;
    int fd_map_len;
    int instance_id_fd;
    int env_fd;
    int set_tty;
    int tty;
} ChildSetupData;

extern void flatpak_close_fds_workaround(int n);
extern void drop_cloexec(int fd);
extern void g_warning(const char *format, ...);
extern void g_debug(const char *format, ...);
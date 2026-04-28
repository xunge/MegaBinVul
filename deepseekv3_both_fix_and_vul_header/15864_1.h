#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/input.h>
#include <stdint.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define SYNTHETIC_ERRNO(e) (e)

typedef struct Button Button;
typedef struct Manager Manager;

struct Button {
    char *name;
    int fd;
    Manager *manager;
    void *io_event_source;
};

struct Manager {
    void *event;
};

int safe_close(int fd);
int button_suitable(Button *b);
int button_set_mask(Button *b);
int button_dispatch(void *userdata);
int sd_event_add_io(void *event, void **source, int fd, uint32_t events, int (*callback)(void *), void *userdata);
char *strjoina(const char *s1, const char *s2);
int log_warning_errno(int errno_, const char *format, ...);
int log_debug_errno(int errno_, const char *format, ...);
int log_error_errno(int errno_, const char *format, ...);
int log_info(const char *format, ...);
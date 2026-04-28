#include <sys/types.h>
#include <unistd.h>
#include <string.h>

typedef int ret_t;

struct cherokee_buffer {
    char *buf;
    int len;
};
typedef struct cherokee_buffer cherokee_buffer_t;

typedef struct cherokee_logger_writer cherokee_logger_writer_t;
typedef struct cherokee_services_fdmap cherokee_services_fdmap_t;

#define CHEROKEE_BUF_INIT { NULL, 0 }
#define CHEROKEE_MUTEX_TRY_LOCK(x) 0
#define CHEROKEE_MUTEX_UNLOCK(x)
#define TRACE(a, b, c)
#define unlikely(x) (x)

enum {
    service_id_spawn_request,
    service_id_spawn_reply,
    service_magic_executable,
    service_magic_uid_gid,
    service_magic_chroot,
    service_magic_chdir,
    service_magic_environment,
    service_magic_error_log,
    service_magic_pid,
    service_magic_fdmap
};

enum {
    ret_deny,
    ret_eagain,
    ret_ok,
    ret_error
};

static int _fd = -1;
static struct {
    int dummy;
} client_mutex;

#define SERVICES_MESSAGE_MAX_SIZE 4096

static ret_t cherokee_services_send(int fd, cherokee_buffer_t *buf, cherokee_services_fdmap_t *fd_map);
static ret_t cherokee_services_receive(int fd, cherokee_buffer_t *buf, void *null);
static void cherokee_buffer_ensure_size(cherokee_buffer_t *buf, int size);
static void cherokee_buffer_add(cherokee_buffer_t *buf, char *data, int size);
static void cherokee_buffer_add_buffer(cherokee_buffer_t *buf, cherokee_buffer_t *src);
static void cherokee_buffer_add_char(cherokee_buffer_t *buf, char c);
static void cherokee_buffer_mrproper(cherokee_buffer_t *buf);
static void write_logger(cherokee_buffer_t *buf, cherokee_logger_writer_t *writer);
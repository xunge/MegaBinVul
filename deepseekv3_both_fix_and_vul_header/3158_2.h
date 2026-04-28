#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <endian.h>

#define LOG_INFO 6
#define LOG_FACMASK 0x03f8
#define LOG_PRIMASK 0x0007
#define DATA_SIZE_MAX (1024*1024*768)
#define N_IOVEC_META_FIELDS 3

typedef struct Server {
    bool forward_to_syslog;
    bool forward_to_kmsg;
    bool forward_to_console;
} Server;

struct ucred;
typedef uint64_t le64_t;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define IOVEC_SET_STRING(iovec, string)                \
    do {                                               \
        const char *_s = (string);                     \
        (iovec).iov_base = (char*) _s;                \
        (iovec).iov_len = strlen(_s);                 \
    } while (0)

static inline bool valid_user_field(const char *p, size_t n) {
    return true;
}

void server_dispatch_message(Server *s, struct iovec *iovec, unsigned n, unsigned m, struct ucred *ucred, struct timeval *tv, const char *label, size_t label_len, void *null, int priority);
void server_forward_syslog(Server *s, int priority, char *identifier, char *message, struct ucred *ucred, struct timeval *tv);
void server_forward_kmsg(Server *s, int priority, char *identifier, char *message, struct ucred *ucred);
void server_forward_console(Server *s, int priority, char *identifier, char *message, struct ucred *ucred);
void log_debug(const char *format, ...);
void log_oom(void);
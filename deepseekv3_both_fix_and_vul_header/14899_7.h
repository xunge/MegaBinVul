#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdarg.h>
#include <syslog.h>

#define NEW_ALLOW 1
#define TRUNK_CALL_START 100
#define MIN_REUSE_TIME 60
#define DEFAULT_RETRY_TIME 2000
#define IAX_NOTRANSFER 0x01
#define IAX_TRANSFERMEDIA 0x02
#define IAX_USEJITTERBUF 0x04
#define IAX_FORCEJITTERBUF 0x08
#define LOG_WARNING 4
#define LOG_DEBUG 7

extern int maxnontrunkcall;
extern int maxtrunkcall;
extern struct iax *iaxs[];
extern pthread_mutex_t iaxsl[];
extern struct timeval lastused[];
extern struct sched *sched;
extern int ping_time;
extern int lagrq_time;
extern int min_reg_expire;
extern int amaflags;
extern int globalflags;
extern char accountcode[];
extern char mohinterpret[];
extern char mohsuggest[];
extern int option_debug;
extern int iaxdebug;

struct iax {
    int sockfd;
    struct sockaddr_in addr;
    unsigned short peercallno;
    unsigned short callno;
    int pingtime;
    int expiry;
    void *pingid;
    void *lagid;
    int amaflags;
    char accountcode[256];
    char mohinterpret[256];
    char mohsuggest[256];
};

struct sched {
    void *data;
};

static inline void ast_mutex_lock(pthread_mutex_t *mutex) {
    pthread_mutex_lock(mutex);
}

static inline void ast_mutex_unlock(pthread_mutex_t *mutex) {
    pthread_mutex_unlock(mutex);
}

static inline struct timeval ast_tvnow(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv;
}

static inline char *ast_inet_ntoa(struct in_addr in) {
    return inet_ntoa(in);
}

static inline int ast_random(void) {
    return rand();
}

static inline void ast_log(int level, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
}

static inline void ast_copy_flags(struct iax *dst, int *src, int flags) {
    dst->amaflags = (*src & flags);
}

static inline void ast_string_field_set(struct iax *dst, char *field, char *value) {
    strncpy(field, value, 255);
    field[255] = '\0';
}

static inline void *iax2_sched_add(struct sched *sched, int timeout, void (*callback)(void *), void *data) {
    return NULL;
}

static inline int iax2_getpeername(struct sockaddr_in sin, char *host, int len) {
    return 0;
}

static inline struct iax *new_iax(struct sockaddr_in *sin, char *host) {
    return malloc(sizeof(struct iax));
}

static inline void update_max_nontrunk(void) {
}

static inline void send_ping(void *data) {
}

static inline void send_lagrq(void *data) {
}

static inline int match(struct sockaddr_in *sin, unsigned short callno, unsigned short dcallno, struct iax *iax, ...) {
    int full_frame = 0;
    va_list ap;
    va_start(ap, iax);
    full_frame = va_arg(ap, int);
    va_end(ap);
    return 0;
}
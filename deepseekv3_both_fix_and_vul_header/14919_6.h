#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdarg.h>

#define NEW_ALLOW 0
#define TRUNK_CALL_START 100
#define MIN_REUSE_TIME 60
#define DEFAULT_RETRY_TIME 1000
#define IAX_NOTRANSFER (1 << 0)
#define IAX_TRANSFERMEDIA (1 << 1)
#define IAX_USEJITTERBUF (1 << 2)
#define IAX_FORCEJITTERBUF (1 << 3)
#define LOG_WARNING 4

extern int maxnontrunkcall;
extern int maxtrunkcall;
extern int iaxdebug;
extern int min_reg_expire;
extern int ping_time;
extern int lagrq_time;
extern int amaflags;
extern char accountcode[];
extern char mohinterpret[];
extern char mohsuggest[];
extern char default_parkinglot[];
extern struct iax2_sched *sched;
extern struct iax_flags globalflags;

typedef pthread_mutex_t ast_mutex;

struct iax2_sched;
struct iax_flags;

struct iax_call {
    int sockfd;
    struct sockaddr_in addr;
    unsigned short peercallno;
    unsigned short callno;
    int pingtime;
    int expiry;
    int pingid;
    int lagid;
    int amaflags;
    char *accountcode;
    char *mohinterpret;
    char *mohsuggest;
    char *parkinglot;
};

extern struct iax_call *iaxs[];
extern ast_mutex iaxsl[];
extern struct timeval lastused[];

static inline struct timeval ast_tvnow(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv;
}

static inline char *ast_inet_ntoa(struct in_addr in) {
    return inet_ntoa(in);
}

static inline void ast_mutex_lock(ast_mutex *mutex) {
    pthread_mutex_lock(mutex);
}

static inline void ast_mutex_unlock(ast_mutex *mutex) {
    pthread_mutex_unlock(mutex);
}

static inline void ast_copy_flags(struct iax_call *dst, struct iax_flags *src, int flags) {}

static inline void ast_string_field_set(struct iax_call *call, const char *field, const char *value) {
    if (strcmp(field, "accountcode") == 0) call->accountcode = strdup(value);
    else if (strcmp(field, "mohinterpret") == 0) call->mohinterpret = strdup(value);
    else if (strcmp(field, "mohsuggest") == 0) call->mohsuggest = strdup(value);
    else if (strcmp(field, "parkinglot") == 0) call->parkinglot = strdup(value);
}

static inline void ast_log(int level, const char *fmt, ...) {}
static inline void ast_debug(int level, const char *fmt, ...) {}
static inline int ast_random(void) { return rand(); }
static inline int iax2_getpeername(struct sockaddr_in sin, char *host, int len) { return 0; }
static inline int match(struct sockaddr_in *sin, unsigned short callno, unsigned short dcallno, struct iax_call *call, ...) { 
    va_list args;
    va_start(args, call);
    int full_frame = va_arg(args, int);
    va_end(args);
    return 0; 
}
static inline struct iax_call *new_iax(struct sockaddr_in *sin, char *host) { return NULL; }
static inline void update_max_nontrunk(void) {}
static inline int iax2_sched_add(struct iax2_sched *sched, int timeout, void (*callback)(void *), void *data) { return 0; }
static inline void send_ping(void *data) {}
static inline void send_lagrq(void *data) {}

#define parkinglot "parkinglot"
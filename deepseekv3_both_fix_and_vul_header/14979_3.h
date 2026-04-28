#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#include <syslog.h>
#include <unistd.h>
#include <stdarg.h>

#define NEW_ALLOW 0
#define TRUNK_CALL_START 0
#define MIN_REUSE_TIME 0
#define DEFAULT_RETRY_TIME 0
#define IAX_NOTRANSFER 0
#define IAX_TRANSFERMEDIA 0
#define IAX_USEJITTERBUF 0
#define IAX_FORCEJITTERBUF 0

struct iax_session {
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

struct iax_flags {
    int flags;
};

struct iax_sched;

extern int maxnontrunkcall;
extern int maxtrunkcall;
extern struct iax_session *iaxs[];
extern pthread_mutex_t iaxsl[];
extern struct timeval lastused[];
extern int iaxdebug;
extern struct iax_sched *sched;
extern int ping_time;
extern int lagrq_time;
extern int min_reg_expire;
extern int amaflags;
extern struct iax_flags globalflags;
extern char accountcode[];
extern char mohinterpret[];
extern char mohsuggest[];
extern char default_parkinglot[];
extern char parkinglot[];

static int match(struct sockaddr_in *sin, unsigned short callno, unsigned short dcallno, struct iax_session *s, ...) { 
    va_list ap;
    int full_frame = 0;
    va_start(ap, s);
    full_frame = va_arg(ap, int);
    va_end(ap);
    return 0; 
}
static struct iax_session *new_iax(struct sockaddr_in *sin, char *host) { return NULL; }
static void update_max_nontrunk(void) {}
static int iax2_getpeername(struct sockaddr_in sin, char *host, int len) { return 0; }
static char *ast_inet_ntoa(struct in_addr in) { return inet_ntoa(in); }
static struct timeval ast_tvnow(void) { struct timeval tv; gettimeofday(&tv, NULL); return tv; }
static void ast_mutex_lock(pthread_mutex_t *mutex) { pthread_mutex_lock(mutex); }
static void ast_mutex_unlock(pthread_mutex_t *mutex) { pthread_mutex_unlock(mutex); }
static void ast_log(int level, const char *fmt, ...) {}
static void ast_debug(int level, const char *fmt, ...) {}
static int iax2_sched_add(struct iax_sched *sched, int timeout, void (*callback)(void *), void *data) { return 0; }
static void send_ping(void *data) {}
static void send_lagrq(void *data) {}
static void ast_copy_flags(struct iax_session *dest, struct iax_flags *src, int flags) {}
static void ast_string_field_set(struct iax_session *s, char *field, const char *value) {}
static int ast_random(void) { return rand(); }
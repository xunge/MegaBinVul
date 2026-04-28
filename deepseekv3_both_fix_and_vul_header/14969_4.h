#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>
#include <syslog.h>
#include <stdarg.h>

#define NEW_ALLOW 0
#define TRUNK_CALL_START 0
#define MIN_REUSE_TIME 0
#define DEFAULT_RETRY_TIME 0
#define IAX_NOTRANSFER 0
#define IAX_TRANSFERMEDIA 0
#define IAX_USEJITTERBUF 0
#define IAX_FORCEJITTERBUF 0

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
    char accountcode[80];
    char mohinterpret[80];
    char mohsuggest[80];
    char parkinglot[80];
};

static int maxnontrunkcall;
static int maxtrunkcall;
static struct iax *iaxs[100];
static pthread_mutex_t iaxsl[100];
static struct timeval lastused[100];
static int iaxdebug;
static void *sched;
static int ping_time;
static int lagrq_time;
static int amaflags;
static int globalflags;
static char accountcode[80];
static char mohinterpret[80];
static char mohsuggest[80];
static char default_parkinglot[80];
static int min_reg_expire;

static int match(struct sockaddr_in *sin, unsigned short callno, unsigned short dcallno, struct iax *iax, ...) {
    va_list ap;
    va_start(ap, iax);
    int full_frame = va_arg(ap, int);
    va_end(ap);
    return 0;
}
static int iax2_getpeername(struct sockaddr_in sin, char *host, int size) { return 0; }
static struct timeval ast_tvnow(void) { struct timeval tv = {0}; return tv; }
static void ast_log(int level, const char *fmt, ...) {}
static void ast_debug(int level, const char *fmt, ...) {}
static struct iax *new_iax(struct sockaddr_in *sin, char *host) { return NULL; }
static void update_max_nontrunk(void) {}
static void *iax2_sched_add(void *sched, int time, void (*func)(void *), void *data) { return NULL; }
static void send_ping(void *data) {}
static void send_lagrq(void *data) {}
static void ast_copy_flags(struct iax *iax, int *flags, int mask) {}
static void ast_string_field_set(struct iax *iax, const char *field, const char *value) {}
static char *ast_inet_ntoa(struct in_addr in) { return ""; }
static unsigned int ast_random(void) { return 0; }

#define ast_mutex_lock pthread_mutex_lock
#define ast_mutex_unlock pthread_mutex_unlock
#define parkinglot "parkinglot"
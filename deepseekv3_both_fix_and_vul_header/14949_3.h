#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <syslog.h>
#include <pthread.h>

#define NEW_ALLOW 0
#define TRUNK_CALL_START 100
#define MIN_REUSE_TIME 60
#define DEFAULT_RETRY_TIME 1000
#define IAX_NOTRANSFER 0x01
#define IAX_TRANSFERMEDIA 0x02
#define IAX_USEJITTERBUF 0x04
#define IAX_FORCEJITTERBUF 0x08
#define LOG_WARNING 4

struct iax {
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

struct ast_mutex {
    pthread_mutex_t mutex;
};

extern int maxnontrunkcall;
extern int maxtrunkcall;
extern int iaxdebug;
extern int min_reg_expire;
extern int ping_time;
extern int lagrq_time;
extern int amaflags;
extern char *accountcode;
extern char *mohinterpret;
extern char *mohsuggest;
extern char *default_parkinglot;
extern char *parkinglot;

extern struct iax *iaxs[];
extern struct ast_mutex iaxsl[];
extern struct timeval lastused[];
extern struct sched *sched;
extern struct iax_flags globalflags;

struct timeval ast_tvnow();
int ast_random();
void ast_mutex_lock(struct ast_mutex *mutex);
void ast_mutex_unlock(struct ast_mutex *mutex);
int ast_log(int level, const char *format, ...);
int ast_debug(int level, const char *format, ...);
char *ast_inet_ntoa(struct in_addr in);
void ast_copy_flags(struct iax *dst, struct iax_flags *src, int flags);
void ast_string_field_set(struct iax *dst, const char *field, const char *value);
int iax2_getpeername(struct sockaddr_in sin, char *host, int len);
int iax2_sched_add(struct sched *sched, int time, void (*callback)(void *), void *data);
int match(struct sockaddr_in *sin, unsigned short callno, unsigned short dcallno, struct iax *iax, ...);
struct iax *new_iax(struct sockaddr_in *sin, char *host);
void update_max_nontrunk();
void send_ping(void *data);
void send_lagrq(void *data);
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/time.h>
#include <syslog.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

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
    int pingid;
    int lagid;
    int amaflags;
    char accountcode[80];
    char mohinterpret[80];
    char mohsuggest[80];
    char parkinglot[80];
};

struct sched;

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
extern int globalflags;

extern struct iax *iaxs[];
extern struct timeval lastused[];
extern pthread_mutex_t iaxsl[];
extern struct sched *sched;
extern int (*match)(struct sockaddr_in *, unsigned short, unsigned short, struct iax *, ...);
extern int (*iax2_getpeername)(struct sockaddr_in, char *, int);
extern char *(*ast_inet_ntoa)(struct in_addr);
extern struct timeval (*ast_tvnow)(void);
extern void (*ast_mutex_lock)(pthread_mutex_t *);
extern void (*ast_mutex_unlock)(pthread_mutex_t *);
extern void (*ast_log)(int, const char *, ...);
extern void (*ast_debug)(int, const char *, ...);
extern struct iax *(*new_iax)(struct sockaddr_in *, const char *);
extern void (*update_max_nontrunk)(void);
extern int (*iax2_sched_add)(struct sched *, int, void (*)(void *), void *);
extern void (*send_ping)(void *);
extern void (*send_lagrq)(void *);
extern void (*ast_copy_flags)(struct iax *, int *, int);
extern void (*ast_string_field_set)(struct iax *, char *, const char *);
extern long ast_random(void);

#define parkinglot iaxs[x]->parkinglot
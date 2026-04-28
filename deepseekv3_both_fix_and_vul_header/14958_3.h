#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

struct ast_channel {
    int nativeformats;
    int readformat;
    int writeformat;
    char *name;
    int maxtime;
    char *host;
};

struct parsed_dial_string {
    char *peer;
    char *port;
};

struct create_addr_info {
    int capability;
    int sockfd;
    int maxtime;
    int found;
    unsigned int flags;
};

extern int iax2_capability;
extern struct create_addr_info globalflags;
extern struct ast_channel *iaxs[];
extern pthread_mutex_t iaxsl[];

enum {
    IAX_NOTRANSFER,
    IAX_TRANSFERMEDIA,
    IAX_USEJITTERBUF,
    IAX_FORCEJITTERBUF,
    IAX_TRUNK,
    IAX_SENDANI
};

enum {
    AST_CAUSE_UNREGISTERED,
    AST_CAUSE_CONGESTION
};

enum {
    AST_STATE_DOWN
};

#define NEW_FORCE 0
#define LOG_WARNING 0

#define ast_strlen_zero(str) (!(str) || !*(str))
#define ast_strdupa(str) strdup(str)
#define ast_copy_flags(dst, src, flags) memcpy(dst, src, sizeof(*dst))
#define ast_test_flag(obj, flag) ((obj)->flags & (flag))
#define ast_string_field_set(obj, field, value) ((obj)->field = strdup(value))
#define ast_log(level, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define ast_iax2_new(callno, state, capability) malloc(sizeof(struct ast_channel))
#define ast_getformatname(format) ""
#define ast_translator_best_choice(fmt, native) 0
#define ast_best_codec(format) 0
#define ast_hangup(channel) free(channel)
#define ast_mutex_unlock(mutex) pthread_mutex_unlock(mutex)

static int find_callno_locked(int a, int b, struct sockaddr_in *sin, int flag, int sockfd, ...) { 
    va_list args;
    va_start(args, sockfd);
    va_end(args);
    return 1; 
}
static int make_trunk(int callno, int flag) { return callno; }
static int parse_dial_string(char *str, struct parsed_dial_string *pds) { return 0; }
static int create_addr(const char *peer, void *arg, struct sockaddr_in *sin, struct create_addr_info *cai) { return 0; }
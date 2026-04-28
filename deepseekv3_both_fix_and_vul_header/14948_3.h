#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

struct ast_channel {
    int nativeformats;
    int readformat;
    int writeformat;
    char *name;
    unsigned int flags;
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

#define IAX_NOTRANSFER (1 << 0)
#define IAX_TRANSFERMEDIA (1 << 1)
#define IAX_USEJITTERBUF (1 << 2)
#define IAX_FORCEJITTERBUF (1 << 3)
#define IAX_TRUNK (1 << 4)
#define IAX_SENDANI (1 << 5)

enum {
    AST_CAUSE_UNREGISTERED,
    AST_CAUSE_CONGESTION
};

enum {
    AST_STATE_DOWN
};

#define NEW_FORCE 0
#define LOG_WARNING 0

#define ast_strlen_zero(s) (!(s) || !*(s))
#define ast_strdupa(s) strdup(s)
#define ast_copy_flags(dst, src, mask) ((dst)->flags = (src)->flags & (mask))
#define ast_test_flag(ptr, flag) ((ptr)->flags & (flag))
#define ast_string_field_set(ptr, field, value) ((ptr)->field = strdup(value))
#define ast_log(level, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define ast_iax2_new(callno, state, capability) malloc(sizeof(struct ast_channel))
#define ast_getformatname(format) ""
#define ast_translator_best_choice(fmt, native) 0
#define ast_best_codec(format) 0
#define ast_hangup(channel) free(channel)
#define ast_mutex_unlock(mutex) pthread_mutex_unlock(mutex)

static int create_addr(const char *peer, const char *port, struct sockaddr_in *sin, struct create_addr_info *cai) { return 0; }
static int find_callno_locked(int arg1, int arg2, struct sockaddr_in *sin, int new_force, int sockfd, ...) { return 0; }
static int make_trunk(int callno, int arg) { return 0; }
static void parse_dial_string(char *str, struct parsed_dial_string *pds) {
    pds->peer = str;
    pds->port = NULL;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <syslog.h>

struct ast_channel {
    int nativeformats;
    int readformat;
    int writeformat;
    char *name;
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

struct iax2_channel {
    int maxtime;
    char *host;
    unsigned int flags;
};

extern int iax2_capability;
extern struct iax2_channel **iaxs;
extern pthread_mutex_t *iaxsl;
extern unsigned int globalflags;

enum {
    AST_CAUSE_UNREGISTERED,
    AST_CAUSE_CONGESTION
};

enum {
    IAX_NOTRANSFER = 1 << 0,
    IAX_TRANSFERMEDIA = 1 << 1,
    IAX_USEJITTERBUF = 1 << 2,
    IAX_FORCEJITTERBUF = 1 << 3,
    IAX_TRUNK = 1 << 4,
    IAX_SENDANI = 1 << 5
};

enum {
    AST_STATE_DOWN,
    NEW_FORCE
};

#define LOG_WARNING 4
#define ast_strlen_zero(s) (!(s) || !*(s))
#define host "host"

char *ast_strdupa(const char *s);
int parse_dial_string(char *str, struct parsed_dial_string *pds);
void ast_log(int level, const char *fmt, ...);
void ast_copy_flags(void *dest, const void *src, int flags);
int create_addr(const char *peer, const char *port, struct sockaddr_in *sin, struct create_addr_info *cai);
int find_callno_locked(int callno, int force, struct sockaddr_in *sin, int new_force, int sockfd, ...);
int make_trunk(int callno, int force);
int ast_test_flag(const void *flags, int flag);
void ast_string_field_set(struct iax2_channel *obj, const char *field, const char *value);
struct ast_channel *ast_iax2_new(int callno, int state, int capability);
void ast_mutex_unlock(pthread_mutex_t *mutex);
int ast_translator_best_choice(int *fmt, int *native);
const char *ast_getformatname(int format);
void ast_hangup(struct ast_channel *chan);
int ast_best_codec(int formats);
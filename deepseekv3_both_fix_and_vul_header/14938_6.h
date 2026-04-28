#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <syslog.h>

#define LOG_WARNING 4
#define NEW_FORCE 1
#define HOST_FIELD "host"

struct ast_channel {
    int nativeformats;
    int readformat;
    int writeformat;
    char *name;
    char *host;
    int maxtime;
    unsigned int flags;
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
    IAX_NOTRANSFER = 1 << 0,
    IAX_TRANSFERMEDIA = 1 << 1,
    IAX_USEJITTERBUF = 1 << 2,
    IAX_FORCEJITTERBUF = 1 << 3,
    IAX_TRUNK = 1 << 4,
    IAX_SENDANI = 1 << 5
};

enum {
    AST_CAUSE_UNREGISTERED = 1,
    AST_CAUSE_CONGESTION = 2
};

enum {
    AST_STATE_DOWN = 0
};

int ast_test_flag(struct create_addr_info *cai, int flag);
void ast_copy_flags(struct ast_channel *dst, struct create_addr_info *src, int flags);
void ast_copy_flags_cai(struct create_addr_info *dst, struct create_addr_info *src, int flags);
int ast_strlen_zero(const char *str);
char *ast_strdupa(const char *s);
void ast_log(int level, const char *fmt, ...);
void ast_string_field_set(struct ast_channel *chan, const char *field, const char *value);
struct ast_channel *ast_iax2_new(int callno, int state, int capability);
int ast_translator_best_choice(int *fmt, int *native);
const char *ast_getformatname(int format);
void ast_hangup(struct ast_channel *chan);
int ast_best_codec(int formats);
int parse_dial_string(char *str, struct parsed_dial_string *pds);
int create_addr(const char *peer, const char *port, struct sockaddr_in *sin, struct create_addr_info *cai);
int find_callno_locked(int callno, int force, struct sockaddr_in *sin, int new_force, int sockfd, ...);
int make_trunk(int callno, int force);
void ast_mutex_unlock(pthread_mutex_t *mutex);

#define host HOST_FIELD
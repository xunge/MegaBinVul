#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <stdarg.h>

struct ast_channel {
    int nativeformats;
    int readformat;
    int writeformat;
    char *name;
    int maxtime;
    char host[256];
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
extern struct ast_channel **iaxs;
extern pthread_mutex_t *iaxsl;

#define AST_STATE_DOWN 0
#define AST_CAUSE_UNREGISTERED 0
#define AST_CAUSE_CONGESTION 0
#define LOG_WARNING 0
#define NEW_FORCE 0

#define IAX_NOTRANSFER 0x01
#define IAX_TRANSFERMEDIA 0x02
#define IAX_USEJITTERBUF 0x04
#define IAX_FORCEJITTERBUF 0x08
#define IAX_TRUNK 0x10
#define IAX_SENDANI 0x20

static inline void ast_copy_flags(void *dest, void *src, int flags) {}
static inline int ast_test_flag(void *flags, int flag) { return 0; }
static inline void ast_string_field_set(struct ast_channel *ptr, const char *field, const char *value) {
    if (!strcmp(field, "host")) {
        strncpy(ptr->host, value, sizeof(ptr->host)-1);
    }
}
static inline int ast_strlen_zero(const char *s) { return !s || !*s; }
static inline char *ast_strdupa(const char *s) { return strdup(s); }
static inline void parse_dial_string(char *str, struct parsed_dial_string *pds) {}
static inline int create_addr(const char *peer, void *null, struct sockaddr_in *sin, struct create_addr_info *cai) { return 0; }
static inline int find_callno_locked(int a, int b, struct sockaddr_in *sin, int flag, int sockfd, ...) { 
    va_list args;
    va_start(args, sockfd);
    if (va_arg(args, int)) {}  // consume optional argument
    va_end(args);
    return 0;
}
static inline int make_trunk(int callno, int flag) { return 0; }
static inline struct ast_channel *ast_iax2_new(int callno, int state, int capability) { return NULL; }
static inline void ast_mutex_unlock(pthread_mutex_t *mutex) {}
static inline int ast_translator_best_choice(int *fmt, int *native) { return 0; }
static inline const char *ast_getformatname(int format) { return ""; }
static inline void ast_hangup(struct ast_channel *c) {}
static inline int ast_best_codec(int formats) { return 0; }
static inline void ast_log(int level, const char *fmt, ...) {}

#define host "host"
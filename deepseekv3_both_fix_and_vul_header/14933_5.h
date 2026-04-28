#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define IAX_MAX_CALLS 100
#define IAX_PROTO_VERSION 2
#define IAX_CAPABILITY_FULLBANDWIDTH 1
#define NEW_FORCE 1
#define AST_FRAME_IAX 1
#define IAX_COMMAND_NEW 1
#define LOG_WARNING 1

struct iax_ie_data {
    char *buf;
    int pos;
};

struct create_addr_info {
    int sockfd;
};

struct parsed_dial_string {
    char *peer;
    char *username;
    char *password;
    char *context;
    char *exten;
    char *key;
};

struct iax_session {
    char *dproot;
    char *secret;
    char *outkey;
    int capability;
};

extern struct iax_session *iaxs[IAX_MAX_CALLS];
extern pthread_mutex_t iaxsl[IAX_MAX_CALLS];

#define ast_mutex_trylock(x) (0)
#define ast_mutex_unlock(x)
#define ast_strdupa(x) strdup(x)
#define ast_strlen_zero(x) (!(x) || !*(x))
#define ast_log(level, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define ast_debug(level, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define ast_string_field_set(obj, field, value) (obj->field = strdup(value))

enum IAX_IE {
    IAX_IE_VERSION,
    IAX_IE_CALLED_NUMBER,
    IAX_IE_CALLED_CONTEXT,
    IAX_IE_USERNAME,
    IAX_IE_FORMAT,
    IAX_IE_CAPABILITY
};

static void parse_dial_string(char *str, struct parsed_dial_string *pds) {}
static int create_addr(const char *peer, const char *port, struct sockaddr_in *sin, struct create_addr_info *cai) { return 0; }
static int find_callno_locked(int callno, int force, struct sockaddr_in *sin, int new_force, int sockfd, ...) { return 0; }
static void iax_ie_append_short(struct iax_ie_data *ied, enum IAX_IE ie, short value) {}
static void iax_ie_append_str(struct iax_ie_data *ied, enum IAX_IE ie, const char *value) {}
static void iax_ie_append_int(struct iax_ie_data *ied, enum IAX_IE ie, int value) {}
static void send_command(struct iax_session *session, int frame_type, int command, int retry, char *buf, int len, int fd) {}
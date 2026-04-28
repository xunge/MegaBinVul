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
#define IAX_CAPABILITY_FULLBANDWIDTH 0x8000
#define NEW_FORCE 1
#define AST_FRAME_IAX 0
#define IAX_COMMAND_NEW 1
#define LOG_WARNING 4

#define IAX_IE_VERSION 0
#define IAX_IE_CALLED_NUMBER 1
#define IAX_IE_CALLED_CONTEXT 2
#define IAX_IE_USERNAME 3
#define IAX_IE_FORMAT 4
#define IAX_IE_CAPABILITY 5

struct iax_ie_data {
    char buf[1024];
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

struct iax_call {
    char *dproot;
    char *secret;
    char *outkey;
    int capability;
};

extern struct iax_call *iaxs[IAX_MAX_CALLS];
extern pthread_mutex_t iaxsl[IAX_MAX_CALLS];

#define ast_mutex_trylock(x) pthread_mutex_trylock(x)
#define ast_mutex_unlock(x) pthread_mutex_unlock(x)
#define ast_strdupa(x) strdup(x)
#define ast_strlen_zero(x) ((x) == NULL || (x)[0] == '\0')
#define ast_log(level, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define ast_debug(level, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define ast_string_field_set(obj, field, value) do { \
    free((obj)->field); \
    (obj)->field = strdup(value); \
} while(0)

static int parse_dial_string(const char *str, struct parsed_dial_string *pds);
static int create_addr(const char *peer, const char *port, struct sockaddr_in *sin, struct create_addr_info *cai);
static int find_callno_locked(int callno, int force, struct sockaddr_in *sin, int new_force, int sockfd, ...);
static void iax_ie_append_short(struct iax_ie_data *ied, int type, short value);
static void iax_ie_append_str(struct iax_ie_data *ied, int type, const char *value);
static void iax_ie_append_int(struct iax_ie_data *ied, int type, int value);
static void send_command(struct iax_call *call, int frame_type, int command, int retry, const char *data, int len, int fd);
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

#define IAX_MAX_CALLS 100
#define IAX_PROTO_VERSION 2
#define IAX_CAPABILITY_FULLBANDWIDTH 0
#define NEW_FORCE 0
#define LOG_WARNING 0
#define LOG_DEBUG 0
#define AST_FRAME_IAX 0
#define IAX_COMMAND_NEW 0

#define IAX_IE_VERSION 1
#define IAX_IE_CALLED_NUMBER 2
#define IAX_IE_CALLED_CONTEXT 3
#define IAX_IE_USERNAME 4
#define IAX_IE_FORMAT 5
#define IAX_IE_CAPABILITY 6

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
    int capability;
    char *secret;
    char *outkey;
};

static struct iax_session *iaxs[IAX_MAX_CALLS];
static pthread_mutex_t iaxsl[IAX_MAX_CALLS];

#define ast_mutex_trylock pthread_mutex_trylock
#define ast_mutex_unlock pthread_mutex_unlock
#define ast_strdupa strdup
#define ast_strlen_zero(s) (!(s) || !*(s))
#define ast_log(level, ...) printf(__VA_ARGS__)
#define ast_debug(level, ...) printf(__VA_ARGS__)
#define ast_string_field_set(session, field, value) (session)->field = strdup(value)
#define parse_dial_string(str, pds) memset(pds, 0, sizeof(*pds))
#define create_addr(peer, port, sin, cai) (0)
#define find_callno_locked(...) (1)
#define iax_ie_append_short(ied, type, value) (0)
#define iax_ie_append_str(ied, type, value) (0)
#define iax_ie_append_int(ied, type, value) (0)
#define send_command(session, frame_type, command, subclass, buf, len, retry) (0)
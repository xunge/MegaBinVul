#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <syslog.h>
#include <pthread.h>

#define IAX_MAX_CALLS 1024
#define IAX_PROTO_VERSION 2
#define IAX_CAPABILITY_FULLBANDWIDTH 0x8000
#define NEW_FORCE 1
#define AST_FRAME_IAX 1
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

struct iax_session {
    char *dproot;
    char *secret;
    char *outkey;
    int capability;
};

extern struct iax_session *iaxs[IAX_MAX_CALLS];
extern pthread_mutex_t iaxsl[IAX_MAX_CALLS];

enum {
    dproot,
    secret,
    outkey
};

int ast_mutex_trylock(pthread_mutex_t *mutex);
void ast_mutex_unlock(pthread_mutex_t *mutex);
int ast_strlen_zero(const char *s);
char *ast_strdupa(const char *s);
void ast_string_field_set(struct iax_session *session, int field, const char *value);
void ast_log(int level, const char *format, ...);
void ast_debug(int level, const char *format, ...);
int parse_dial_string(const char *str, struct parsed_dial_string *pds);
int create_addr(const char *peer, const char *port, struct sockaddr_in *sin, struct create_addr_info *cai);
int find_callno_locked(int callno, int subno, struct sockaddr_in *sin, int force, int sockfd, ...);
void iax_ie_append_short(struct iax_ie_data *ied, int type, short value);
void iax_ie_append_str(struct iax_ie_data *ied, int type, const char *value);
void iax_ie_append_int(struct iax_ie_data *ied, int type, int value);
void send_command(struct iax_session *session, int type, int cmd, int retry, const char *data, int len, int timestamp);
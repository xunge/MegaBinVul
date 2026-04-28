#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define IAX_MAX_CALLS 100
#define IAX_PROTO_VERSION 2
#define IAX_CAPABILITY_FULLBANDWIDTH 1
#define NEW_FORCE 1
#define LOG_WARNING 1
#define LOG_DEBUG 2

#define IAX_IE_VERSION 1
#define IAX_IE_CALLED_NUMBER 2
#define IAX_IE_CALLED_CONTEXT 3
#define IAX_IE_USERNAME 4
#define IAX_IE_FORMAT 5
#define IAX_IE_CAPABILITY 6
#define AST_FRAME_IAX 7
#define IAX_COMMAND_NEW 8

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

static struct iax_session *iaxs[IAX_MAX_CALLS];
static pthread_mutex_t iaxsl[IAX_MAX_CALLS];
extern int option_debug;

enum {
    dproot,
    secret,
    outkey
};
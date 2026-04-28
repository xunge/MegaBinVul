#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define HOSTNAME_MAX 1024
#define FIRSTSOCKET 0
#define RESP_TIMEOUT 0
#define SMTP_SERVERGREET 0
#define CURLE_OK 0
#define CURLE_OUT_OF_MEMORY 1
#define CURLPROTO_SMTPS (1 << 0)
#define TRUE 1
#define FALSE 0

typedef int CURLcode;

struct connectdata;
struct SessionHandle;

struct pingpong {
    long response_time;
    int (*statemach_act)(struct connectdata *conn);
    int (*endofresp)(struct connectdata *conn, int *resp);
    struct connectdata *conn;
};

struct smtp_conn {
    struct pingpong pp;
    char *domain;
};

struct HTTP {
    int dummy;
};

struct FTP {
    int dummy;
};

struct SessionHandle {
    struct {
        struct {
            struct FTP *smtp;
            struct HTTP *http;
        } proto;
        int used_interface;
        char *path;
    } state;
};

struct connectdata {
    struct {
        struct smtp_conn smtpc;
    } proto;
    struct SessionHandle *data;
    struct {
        char *name;
    } host;
    int remote_port;
    struct {
        char *path;
    } state;
    struct {
        int protocol;
    } *handler;
    struct {
        unsigned int close:1;
        unsigned int tunnel_proxy:1;
        unsigned int httpproxy:1;
    } bits;
};

enum Curl_if {
    Curl_if_multi
};

int smtp_statemach_act(struct connectdata *conn) { return 0; }
int smtp_endofresp(struct connectdata *conn, int *resp) { return 0; }
int smtp_init(struct connectdata *conn) { return 0; }
void Curl_reset_reqproto(struct connectdata *conn) {}
int Curl_proxyCONNECT(struct connectdata *conn, int socket, char *hostname, int port) { return 0; }
int Curl_ssl_connect(struct connectdata *conn, int socket) { return 0; }
void Curl_pp_init(struct pingpong *pp) {}
char *curl_easy_unescape(struct SessionHandle *data, const char *string, int length, int *outlength) { return NULL; }
int Curl_gethostname(char *name, size_t len) { return 0; }
void state(struct connectdata *conn, int state) {}
int smtp_multi_statemach(struct connectdata *conn, bool *done) { return 0; }
int smtp_easy_statemach(struct connectdata *conn) { return 0; }
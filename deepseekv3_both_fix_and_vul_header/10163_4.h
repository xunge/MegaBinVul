#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define TRUE 1
#define INET_ADDRSTRLEN 16
#define INET6_ADDRSTRLEN 46
#define LRMD_REMOTE_AUTH_TIMEOUT 30000
#define GNUTLS_SERVER 1
#define G_PRIORITY_DEFAULT 0
#define CRM_CLIENT_TLS 1

typedef void* gpointer;
typedef unsigned int guint;
typedef int gint;
typedef int (*GSourceFunc)(gpointer);

typedef struct {
    void *data;
} gnutls_session_t;

typedef struct {
    void *data;
} GHashTable;

struct mainloop_fd_callbacks {
    int (*dispatch)(gpointer data);
    void (*destroy)(gpointer data);
};

struct crm_remote {
    gnutls_session_t *tls_session;
    guint auth_timeout;
    gpointer source;
};

struct crm_client {
    int kind;
    char *id;
    struct crm_remote *remote;
};

typedef struct crm_client crm_client_t;
typedef struct crm_remote crm_remote_t;

extern int ssock;
extern GHashTable *client_connections;
extern void *psk_cred_s;
extern int lrmd_auth_timeout_cb(gpointer data);

int lrmd_remote_client_msg(gpointer data);
void lrmd_remote_client_destroy(gpointer data);
void get_ip_str(const struct sockaddr *sa, char *s, size_t maxlen);
gnutls_session_t *create_psk_tls_session(int fd, int priority, void *cred);
char *crm_generate_uuid(void);
guint g_timeout_add(guint interval, GSourceFunc function, gpointer data);
gpointer mainloop_add_fd(const char *name, gint priority, gint fd, gpointer user_data, struct mainloop_fd_callbacks *callbacks);
void crm_info(const char *format, ...);
void crm_err(const char *format, ...);
void crm_notice(const char *format, ...);
void notify_of_new_client(crm_client_t *client);
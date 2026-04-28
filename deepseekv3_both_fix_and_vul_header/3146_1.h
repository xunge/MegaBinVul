#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>
#include <strings.h>

#define BUFFER_SIZE 1024

struct server {
    struct service *svr_sp;
    void *svr_conn;
};

struct service {
    struct service_config *sv_conf;
    unsigned flags;
    unsigned waits;
};

struct service_config {
    char *sc_name;
    unsigned sc_flags;
};

struct debug {
    int on;
} debug;

struct pset {
    void *data;
};

struct pset *ps;

#define SERVER_FD(serp) (0)
#define SERVER_SERVICE(serp) (NULL)
#define SERVER_CONNECTION(serp) (NULL)
#define SERVICES(ps) (NULL)
#define SP(ptr) ((struct service *)(ptr))
#define SVC_CONF(sp) ((sp)->sv_conf)
#define SC_NAME(scp) ((scp)->sc_name)
#define SVC_IS_MUXCLIENT(sp) (((sp)->flags & 0x1) != 0)
#define SVC_IS_MUXPLUSCLIENT(sp) (((sp)->flags & 0x2) != 0)
#define SVC_WAITS(svc) ((svc)->waits)
#define SC_IS_INTERNAL(scp) (((scp)->sc_flags & 0x1) != 0)
#define SC_INTERNAL(scp, nserp) 
#define TCPMUX_ACK ""
#define TCPMUX_NOT_FOUND ""

void close_all_svc_descriptors(void);
void msg(int priority, const char *tag, const char *fmt, ...);
int pset_count(struct pset *ps);
void *pset_pointer(struct pset *ps, unsigned index);
int Swrite(int fd, const void *buf, size_t count);
void Sflush(int fd);
void Sclose(int fd);
struct server *server_alloc(struct server *s);
void exec_server(struct server *s);
#include <sys/types.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t tcp_seq;

struct tcpcb {
    int sack_enable;
    tcp_seq snd_una;
    tcp_seq snd_max;
    int snd_numholes;
    struct sackhole *snd_holes;
    tcp_seq rcv_lastsack;
    uint32_t t_maxseg;
};

struct sackhole {
    tcp_seq start;
    tcp_seq end;
    tcp_seq rxmit;
    int dups;
    struct sackhole *next;
};

struct sackblk {
    tcp_seq start;
    tcp_seq end;
};

struct pool;
struct tcpstat {
    int tcps_sack_rcv_opts;
};

extern struct pool sackhl_pool;
extern int tcprexmtthresh;
extern struct tcpstat tcpstat;
#define TCP_SACKHOLE_LIMIT 100

#define PR_NOWAIT 0
#define TCPOLEN_SACK (2 * sizeof(tcp_seq))
#define SEQ_LT(a,b) ((int32_t)((a)-(b)) < 0)
#define SEQ_LEQ(a,b) ((int32_t)((a)-(b)) <= 0)
#define SEQ_GT(a,b) ((int32_t)((a)-(b)) > 0)
#define SEQ_GEQ(a,b) ((int32_t)((a)-(b)) >= 0)
#define SEQ_MAX(a,b) ((a) > (b) ? (a) : (b))
#define SEQ_MIN(a,b) ((a) < (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

void panic(const char *);
void *pool_get(struct pool *, int);
void pool_put(struct pool *, void *);
#define tcpstat_inc(x) (tcpstat.x++)
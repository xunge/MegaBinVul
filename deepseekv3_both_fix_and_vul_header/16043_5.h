#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

#define PICO_ZALLOC(size) malloc(size)
#define PICO_FREE(ptr) free(ptr)

struct pico_tree_node {
    void *key;
    struct pico_tree_node *left;
    struct pico_tree_node *right;
};

static struct pico_tree_node LEAF_NODE = {NULL, NULL, NULL};
static struct pico_tree_node *LEAF = &LEAF_NODE;

#define PICO_SIZE_TCPHDR 0
#define PICO_TCP_MIN_MSS 0
#define PICO_DEFAULT_SOCKETQ 0
#define PICO_TCP_RTO_MIN 0
#define PICO_SOCKET_OPT_TCPNODELAY 0
#define PICO_SOCKET_LINGER_TIMEOUT 0
#define TCP_TIME 0

struct pico_stack;
struct pico_socket {
    struct pico_stack *stack;
    uint32_t timestamp;
    uint16_t opt_flags;
};

struct pico_tree {
    struct pico_tree_node *root;
    int (*compare)(void *a, void *b);
};

struct pico_socket_queue {
    struct pico_tree pool;
    uint32_t max_size;
};

struct pico_socket_tcp {
    struct pico_socket sock;
    uint16_t mss;
    struct pico_socket_queue tcpq_in;
    struct pico_socket_queue tcpq_out;
    struct pico_socket_queue tcpq_hold;
    void *keepalive_tmr;
    uint32_t linger_timeout;
};

int segment_compare(void *a, void *b);
int input_segment_compare(void *a, void *b);
void rto_set(struct pico_socket_tcp *t, uint32_t rto);
void tcp_set_space(struct pico_socket_tcp *t);
void pico_socket_set_family(struct pico_socket *s, uint16_t family);
uint32_t pico_socket_get_mss(struct pico_socket *s);
void *pico_timer_add(struct pico_stack *S, uint32_t timeout, void (*callback)(void *), void *arg);
void pico_tcp_keepalive(void *arg);
void sock_stats(void *arg);
void tcp_dbg(const char *fmt, ...);
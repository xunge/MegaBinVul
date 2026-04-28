#include <sys/socket.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>

#define TIPC_MAX_USER_MSG_SIZE 66000
#define TIPC_LISTEN 1
#define TIPC_OPEN 2
#define TIPC_CONNECTING 3
#define NAMED_H_SIZE 32
#define BASIC_H_SIZE 24
#define TIPC_NAMED_MSG 1
#define TIPC_DIRECT_MSG 2
#define TIPC_SERVICE_ADDR 1
#define TIPC_SOCKET_ADDR 2
#define TIPC_SERVICE_RANGE 3
#define ELINKCONG 105

struct list_head {
    struct list_head *next, *prev;
};

struct tipc_msg {
    int type;
    int hdr_sz;
    int nametype;
    int nameinst;
    int lookup_scope;
    unsigned int destnode;
    unsigned int destport;
};

struct tipc_socket_addr {
    unsigned int node;
    unsigned int ref;
};

struct tipc_uaddr {
    int addrtype;
    int family;
    int scope;
    struct {
        int type;
        int instance;
    } sa;
    unsigned int lookup_node;
    struct tipc_socket_addr sk;
    int msg_namelen;
};

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
    unsigned long sk_write_queue;
};

struct net;

struct tipc_sock {
    struct list_head cong_links;
    struct tipc_group *group;
    struct tipc_msg phdr;
    struct tipc_uaddr peer;
    unsigned int portid;
    bool published;
    int conn_addrtype;
    int cong_link_cnt;
};

struct tipc_group;

struct sk_buff {
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
};

#define unlikely(x) (x)
#define __skb_queue_head_init(x) do { (x)->next = (x); (x)->prev = (x); } while (0)
#define __skb_queue_purge(x) do { (x)->next = (x); (x)->prev = (x); } while (0)
#define skb_peek(x) ((x)->next)
#define trace_tipc_sk_sendmsg(a,b,c,d)
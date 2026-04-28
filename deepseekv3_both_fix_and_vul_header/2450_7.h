#include <sys/socket.h>
#include <sys/poll.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

typedef int bool_t;
typedef unsigned long u_long;
typedef char* caddr_t;
typedef bool_t (*xdrproc_t)(void*, void*);

struct XDR {
    int x_op;
    /* Add other XDR fields as needed */
};
typedef struct XDR XDR;

typedef struct CLIENT {
    void* cl_private;
    void* cl_auth;
} CLIENT;

struct opaque_auth {
    uint32_t oa_length;
    uint32_t oa_flavor;
    caddr_t oa_base;
};

struct rpc_msg {
    struct {
        struct opaque_auth ar_verf;
        struct {
            xdrproc_t proc;
            caddr_t where;
        } ar_results;
    } acpted_rply;
};

struct rpc_err {
    int re_status;
    int re_errno;
    int re_why;
};

struct sock_extended_err {
    uint32_t ee_errno;
    /* Add other fields as needed */
};

struct cu_data {
    XDR cu_outxdrs;
    int cu_xdrpos;
    char* cu_outbuf;
    int cu_sock;
    struct sockaddr_in cu_raddr;
    socklen_t cu_rlen;
    struct timeval cu_wait;
    struct timeval cu_total;
    struct rpc_err cu_error;
    char* cu_inbuf;
    size_t cu_recvsz;
};

enum clnt_stat {
    RPC_SUCCESS,
    RPC_CANTENCODEARGS,
    RPC_CANTSEND,
    RPC_TIMEDOUT,
    RPC_CANTRECV,
    RPC_AUTHERROR,
    RPC_CANTDECODERES
};

#define XDR_ENCODE 0
#define XDR_DECODE 1
#define XDR_FREE 2
static const struct opaque_auth _null_auth = {0, 0, NULL};
#define AUTH_INVALIDRESP 0
#define POLLIN 0x001

extern int __sendto(int, const void*, size_t, int, const struct sockaddr*, socklen_t);
extern int __poll(struct pollfd*, nfds_t, int);
extern int __recvfrom(int, void*, size_t, int, struct sockaddr*, socklen_t*);
extern int __recvmsg(int, struct msghdr*, int);
extern bool_t xdr_replymsg(XDR*, struct rpc_msg*);
extern bool_t xdr_opaque_auth(XDR*, struct opaque_auth*);
extern int is_network_up(int);
extern void XDR_SETPOS(XDR*, int);
extern int XDR_GETPOS(XDR*);
extern bool_t XDR_PUTLONG(XDR*, long*);
extern bool_t AUTH_MARSHALL(void*, XDR*);
extern bool_t AUTH_VALIDATE(void*, struct opaque_auth*);
extern bool_t AUTH_REFRESH(void*);
extern void _seterr_reply(struct rpc_msg*, struct rpc_err*);
extern void xdrmem_create(XDR*, char*, unsigned int, int);
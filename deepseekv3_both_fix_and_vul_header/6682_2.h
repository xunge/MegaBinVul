#include <stddef.h>
#include <errno.h>

struct hidp_connadd_req;
struct socket {
    struct sock *sk;
};
struct sock;

struct hidp_session {
    struct {
        int user;
    } user;
};

struct l2cap_conn;
struct l2cap_chan {
    struct l2cap_conn *conn;
    struct {
        int dst;
    } dst;
};

struct l2cap_pinfo {
    struct l2cap_chan *chan;
};

static inline struct l2cap_pinfo *l2cap_pi(const struct sock *sk)
{
    return (struct l2cap_pinfo *)sk;
}

#define EBADFD 77

int hidp_verify_sockets(struct socket *ctrl_sock, struct socket *intr_sock);
void l2cap_chan_lock(struct l2cap_chan *chan);
void l2cap_chan_unlock(struct l2cap_chan *chan);
struct l2cap_conn *l2cap_conn_get(struct l2cap_conn *conn);
int hidp_session_new(struct hidp_session **session, void *dst, struct socket *ctrl_sock, 
                    struct socket *intr_sock, struct hidp_connadd_req *req, struct l2cap_conn *conn);
int l2cap_register_user(struct l2cap_conn *conn, void *user);
void hidp_session_put(struct hidp_session *session);
void l2cap_conn_put(struct l2cap_conn *conn);
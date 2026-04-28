#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#define __user
#define READ_ONCE(x) (x)
#define USER_SOCKPTR(x) (x)

struct sock;
struct inet_connection_sock {
    struct {
        int (*getsockopt)(struct sock *sk, int level, int optname, char *optval, int *optlen);
    } *icsk_af_ops;
};
struct inet_connection_sock *inet_csk(struct sock *sk);
int do_tcp_getsockopt(struct sock *sk, int level, int optname, char *optval, int *optlen);
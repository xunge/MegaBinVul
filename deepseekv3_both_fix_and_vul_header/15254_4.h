#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>
#include <errno.h>

struct socket {
    struct sock *sk;
    int flags;
    int state;
};

struct sock {
    struct sock *sk;
    int sk_state;
    int sk_type;
    int sk_shutdown;
    struct {
        pid_t pid;
        uid_t uid;
        gid_t gid;
    } sk_peercred;
    struct {
        struct sock *peer;
        pthread_mutex_t lock;
    } sk_receive_queue;
    void (*sk_data_ready)(struct sock *, int);
    void *sk_sleep;
};

struct net;

struct unix_addr {
    int refcnt;
};

struct unix_sock {
    struct sock sk;
    struct unix_addr *addr;
    void *dentry;
    void *mnt;
    struct {
        int refcnt;
    } *peer_wait;
};

struct sk_buff;

#define SOCK_PASSCRED 1
#define SOCK_DEAD 1
#define TCP_LISTEN 1
#define TCP_ESTABLISHED 2
#define TCP_CLOSE 3
#define RCV_SHUTDOWN 1
#define SS_CONNECTED 1

#define sock_sndtimeo(sk, flags) 0
#define sock_net(sk) NULL
#define unix_sk(sk) ((struct unix_sock *)(sk))
#define unix_mkname(addr, len, hash) 0
#define test_bit(bit, addr) (*(addr) & (1 << (bit)))
#define unix_autobind(sock) 0
#define unix_create1(net, sock) NULL
#define sock_wmalloc(sk, size, priority, flags) NULL
#define unix_find_other(net, addr, len, type, hash, err) NULL
#define unix_state_lock(sk)
#define unix_state_unlock(sk)
#define sock_flag(sk, flag) 0
#define sock_put(sk)
#define unix_wait_for_peer(sk, timeo) 0
#define sock_intr_errno(timeo) 0
#define signal_pending(current) 0
#define unix_state_lock_nested(sk)
#define security_unix_stream_connect(sock, other, newsk) 0
#define sock_hold(sk)
#define unix_peer(sk) (sk)->sk_receive_queue.peer
#define task_tgid_vnr(current) 0
#define current_euid_egid(uid, gid) do { *(uid) = 0; *(gid) = 0; } while (0)
#define dget(dentry) NULL
#define mntget(mnt) NULL
#define atomic_inc(addr) (*(addr))++
#define smp_mb__after_atomic_inc()
#define spin_lock(lock) pthread_mutex_lock(lock)
#define spin_unlock(lock) pthread_mutex_unlock(lock)
#define __skb_queue_tail(queue, skb)
#define kfree_skb(skb) free(skb)
#define unix_release_sock(sk, flags)
#define unix_recvq_full(sk) 0
#include <sys/socket.h>
#include <sys/time.h>
#include <limits.h>
#include <stdint.h>
#include <stddef.h>

typedef uint64_t u64;

struct socket {
    struct sock *sk;
};

struct sock {
    // minimal definition
};

struct vsock_sock {
    const struct vsock_transport *transport;
    u64 buffer_max_size;
    u64 buffer_min_size;
    u64 buffer_size;
    unsigned long connect_timeout;
};

struct vsock_transport {
    // minimal definition
};

typedef struct {
    int dummy;
} sockptr_t;

#define ENOPROTOOPT 92
#define EINVAL 22
#define EFAULT 14
#define ERANGE 34
#define USEC_PER_SEC 1000000
#define HZ 100
#define MAX_SCHEDULE_TIMEOUT LONG_MAX
#define VSOCK_DEFAULT_CONNECT_TIMEOUT (2 * HZ)
#define SO_VM_SOCKETS_BUFFER_SIZE 0
#define SO_VM_SOCKETS_BUFFER_MAX_SIZE 1
#define SO_VM_SOCKETS_BUFFER_MIN_SIZE 2
#define SO_VM_SOCKETS_CONNECT_TIMEOUT 3

struct __kernel_old_timeval {
    long tv_sec;
    long tv_usec;
};

static inline int copy_from_sockptr(void *dst, sockptr_t src, size_t size) {
    return -1;
}

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline struct vsock_sock *vsock_sk(struct sock *sk) { return NULL; }
static inline void vsock_update_buffer_size(struct vsock_sock *vsk, const struct vsock_transport *transport, u64 val) {}

#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
#include <unistd.h>
#include <errno.h>

#define TLS_1_3_VERSION 0x0304
#define TLS_SW 1
#define TLS_HW 2
#define EINVAL 22
#define EFAULT 14

struct sock;
struct tls_context {
    struct {
        int version;
    } prot_info;
    int rx_conf;
    int rx_no_pad;
};

#define __user

static inline int tls_get_ctx(struct sock *sk) { return 0; }
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline int get_user(int len, int *optlen) { return 0; }
static inline int put_user(int size, int *optlen) { return 0; }
static inline int copy_to_user(char *optval, int *value, int size) { return 0; }
#include <errno.h>
#include <sys/socket.h>

#define __user
#define __SO_LEVEL_MATCH(optname, level) (0)
#define __SO_SIZE(optname) (0)
#define ATM_SD(sock) ((struct atm_vcc *)(sock)->sk)
#define ATM_VF_HASQOS 1
#define ATM_VF_ADDR 2
#define ATM_ATMOPT_CLP 1
#define SOL_SOCKET 1
#define SO_ATMQOS 100
#define SO_SETCLP 101
#define SO_ATMPVC 102

struct socket {
    void *sk;
};

struct atm_vcc {
    unsigned long flags;
    void *qos;
    unsigned long atm_options;
    struct {
        int number;
        struct {
            int (*getsockopt)(struct atm_vcc *, int, int, char *, int);
        } *ops;
    } *dev;
    int vpi;
    int vci;
};

struct sockaddr_atmpvc {
    int sap_family;
    struct {
        int itf;
        int vpi;
        int vci;
    } sap_addr;
};

static inline int get_user(int val, int __user *ptr) { return 0; }
static inline int copy_to_user(void __user *to, const void *from, unsigned long n) { return 0; }
static inline int put_user(int val, void __user *ptr) { return 0; }
static inline int test_bit(int nr, const volatile unsigned long *addr) { return *addr & (1UL << nr); }
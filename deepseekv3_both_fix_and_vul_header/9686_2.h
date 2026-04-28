#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

struct socket {
    struct sock *sk;
    int state;
};

struct sock {
    int sk_type;
    int sk_protocol;
    int sk_state;
};

struct sockaddr_irda {
    char sir_name[32];
    int sir_lsap_sel;
};

struct irda_sock {
    int pid;
    struct irias_object *ias_obj;
    int stsap_sel;
};

struct irias_object {
    char *name;
};

#define IRDA_DEBUG(level, fmt, ...)
#define CONFIG_IRDA_ULTRA
#define IRDAPROTO_ULTRA 1
#define EINVAL 22
#define EOPNOTSUPP 95
#define ENOMEM 12
#define SS_CONNECTED 1
#define TCP_ESTABLISHED 1
#define IAS_KERNEL_ATTR 1

static unsigned long jiffies = 0;

static inline struct irda_sock *irda_sk(struct sock *sk) { return (struct irda_sock *)sk; }
static inline void lock_kernel() {}
static inline void unlock_kernel() {}
static inline int irda_open_lsap(struct irda_sock *self, int pid) { return 0; }
static inline struct irias_object *irias_new_object(char *name, unsigned long jiffies) { 
    struct irias_object *obj = malloc(sizeof(struct irias_object));
    if (obj) obj->name = strdup(name);
    return obj;
}
static inline int irda_open_tsap(struct irda_sock *self, int sel, char *name) { return 0; }
static inline void irias_add_integer_attrib(struct irias_object *obj, char *name, int value, int type) {}
static inline void irias_insert_object(struct irias_object *obj) {}
static inline void kfree(void *p) { free(p); }
#include <stdbool.h>

#define MAX_RECURSION_LEVEL 4
#define ETOOMANYREFS (-23)
#define ENOMEM (-12)

#define unlikely(x) (x)
#define max(a, b) ((a) > (b) ? (a) : (b))

struct task_struct {
    // dummy definition
};

struct sock {
    // dummy definition  
};

struct file {
    // dummy definition
};

struct scm_cookie {
    struct scm_fp_list *fp;
};

struct sk_buff {
    char cb[32]; // control buffer
};

struct unix_sk {
    unsigned char recursion_level;
};

struct scm_fp_list {
    int count;
    struct file *fp[];
};

struct UNIXCB {
    struct scm_fp_list *fp;
};

#define UNIXCB(skb) (*((struct UNIXCB *)((skb)->cb)))

static struct task_struct *current = 0;

static inline struct unix_sk *unix_sk(const struct sock *sk)
{
    return (struct unix_sk *)sk;
}

static inline struct sock *unix_get_socket(struct file *filp)
{
    return 0;
}

static inline bool too_many_unix_fds(struct task_struct *task)
{
    return false;
}

static inline struct scm_fp_list *scm_fp_dup(struct scm_fp_list *fp)
{
    return 0;
}

static inline void unix_inflight(struct file *fp)
{
}
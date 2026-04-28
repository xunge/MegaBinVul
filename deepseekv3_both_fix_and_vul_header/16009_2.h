#include <stdbool.h>
#include <stddef.h>

struct sock {
    int sk_shutdown;
    void *sk_timer;
};

struct mptcp_subflow_context {
    int node;
};

struct mptcp_sock {
    struct mptcp_subflow_context *conn_list;
    void *last_snd;
    unsigned int flags;
    unsigned int cb_flags;
    unsigned int push_pending;
    bool recovery;
    bool can_ack;
    bool fully_established;
    bool rcv_data_fin;
    bool snd_data_fin_enable;
    bool rcv_fastclose;
    bool use_64bit_ack;
    bool csum_enabled;
    int token;
};

struct net;

#define MPTCP_CF_FASTCLOSE 0
#define MPTCP_EVENT_CLOSED 0
#define TCP_CLOSE 0
#define GFP_KERNEL 0

#define WRITE_ONCE(var, val) (var = val)

static inline void inet_sk_state_store(struct sock *sk, int state) {}
static inline struct mptcp_sock *mptcp_sk(const struct sock *sk) { return NULL; }
static inline struct sock *mptcp_subflow_tcp_sock(struct mptcp_subflow_context *subflow) { return NULL; }
static inline void __mptcp_close_ssk(struct sock *sk, struct sock *ssk, struct mptcp_subflow_context *subflow, int flags) {}
static inline void mptcp_stop_timer(struct sock *sk) {}
static inline void sk_stop_timer(struct sock *sk, void *timer) {}
static inline void mptcp_event(int event, struct mptcp_sock *msk, void *arg, int gfp) {}
static inline void mptcp_destroy_common(struct mptcp_sock *msk) {}
static inline bool mptcp_is_checksum_enabled(struct net *net) { return false; }
static inline void mptcp_pm_data_reset(struct mptcp_sock *msk) {}
static inline void mptcp_ca_reset(struct sock *sk) {}
static inline void sk_error_report(struct sock *sk) {}
static inline struct net *sock_net(struct sock *sk) { return NULL; }

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; false; )

#define mptcp_for_each_subflow(msk, subflow) \
    for (subflow = NULL; false; )
#include <stddef.h>
#include <sys/types.h>

typedef int pj_status_t;
typedef ssize_t pj_ssize_t;
typedef struct pjsip_endpoint pjsip_endpoint;
typedef struct pjsip_response_addr pjsip_response_addr;
typedef struct pjsip_tx_data pjsip_tx_data;
typedef struct pjsip_send_state pjsip_send_state;
typedef void (*pjsip_send_callback)(pjsip_send_state*, pjsip_tx_data*, pj_ssize_t);

struct pjsip_send_state {
    pjsip_endpoint *endpt;
    pjsip_tx_data *tdata;
    void *token;
    pjsip_send_callback app_cb;
    struct pjsip_transport *cur_transport;
};

struct pjsip_response_addr {
    struct pjsip_transport *transport;
    void *addr;
    int addr_len;
    struct {
        struct {
            struct {
                char *host;
            } addr;
        } dst_host;
    };
};

struct pjsip_tx_data {
    struct {
        char *start;
        char *cur;
    } buf;
    struct {
        struct {
            int slen;
        } name;
    } dest_info;
    void *pool;
};

struct pjsip_transport;

struct pj_str {
    int slen;
};

void pjsip_transport_add_ref(struct pjsip_transport *t);
void pjsip_transport_dec_ref(struct pjsip_transport *t);
pj_status_t pjsip_transport_send(struct pjsip_transport *t, pjsip_tx_data *tdata, 
                                void *addr, int addr_len, pjsip_send_state *state,
                                pjsip_send_callback cb);
void pj_strdup(void *pool, struct pj_str *dst, char **src);
void pjsip_endpt_resolve(pjsip_endpoint *endpt, void *pool, void *dst_host, 
                        pjsip_send_state *state, pjsip_send_callback cb);
void send_response_transport_cb(pjsip_send_state *state, pjsip_tx_data *tdata, pj_ssize_t sent);
void send_response_resolver_cb(pjsip_send_state *state, pjsip_tx_data *tdata, pj_ssize_t sent);

#define PJ_POOL_ZALLOC_T(pool, type) ((type*)0)
#define PJ_SUCCESS 0
#define PJ_EPENDING (-1)
#define PJ_DEF(ret) ret
#include <stddef.h>

typedef int pj_status_t;
#define PJ_SUCCESS 0

#define PJSIP_ACK_METHOD 1
#define PJSIP_CANCEL_METHOD 2

typedef struct pjsip_method {
    int id;
} pjsip_method;

typedef struct pjsip_hdr {
    struct pjsip_hdr *next;
    struct pjsip_hdr *prev;
} pjsip_hdr;

typedef struct pjsip_contact_hdr pjsip_contact_hdr;
typedef struct pjsip_fromto_hdr pjsip_fromto_hdr;
typedef struct pjsip_call_id_hdr pjsip_call_id_hdr;

typedef struct pjsip_route_hdr {
    pjsip_hdr hdr;
    struct pjsip_route_hdr *next;
} pjsip_route_hdr;

typedef struct pjsip_auth_clt_sess {
    int dummy;
} pjsip_auth_clt_sess;

typedef struct pjsip_endpoint pjsip_endpoint;
typedef struct pjsip_uri pjsip_uri;
typedef struct pjsip_msg pjsip_msg;

typedef struct pjsip_tx_data {
    void *pool;
    pjsip_msg *msg;
    void **mod_data;
    struct {
        char *name;
    } dest_info;
} pjsip_tx_data;

typedef struct pjsip_route_set {
    pjsip_route_hdr *next;
} pjsip_route_set;

typedef struct pjsip_dialog {
    struct {
        pjsip_contact_hdr *contact;
        pjsip_fromto_hdr *info;
    } local;
    struct {
        pjsip_fromto_hdr *info;
    } remote;
    pjsip_endpoint *endpt;
    pjsip_uri *target;
    pjsip_call_id_hdr *call_id;
    pjsip_route_set route_set;
    struct {
        int id;
    } *ua;
    pjsip_auth_clt_sess auth_sess;
    struct {
        size_t slen;
    } initial_dest;
} pjsip_dialog;

int pjsip_method_creates_dialog(const pjsip_method *method);
pj_status_t pjsip_endpt_create_request_from_hdr(pjsip_endpoint *endpt,
                                              const pjsip_method *method,
                                              pjsip_uri *target,
                                              pjsip_fromto_hdr *local,
                                              pjsip_fromto_hdr *remote,
                                              pjsip_contact_hdr *contact,
                                              pjsip_call_id_hdr *call_id,
                                              int cseq,
                                              void *param,
                                              pjsip_tx_data **p_tdata);
pjsip_hdr *pjsip_hdr_shallow_clone(void *pool, pjsip_hdr *hdr);
void pjsip_routing_hdr_set_route(pjsip_route_hdr *r);
void pjsip_msg_add_hdr(pjsip_msg *msg, pjsip_hdr *hdr);
pj_status_t pjsip_auth_clt_init_req(pjsip_auth_clt_sess *sess, pjsip_tx_data *tdata);
void pj_strdup(void *pool, char **dst, const char *src);
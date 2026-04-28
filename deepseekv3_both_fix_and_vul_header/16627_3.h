#include <stddef.h>

typedef struct pjsip_method pjsip_method;
typedef struct pjsip_hdr pjsip_hdr;
typedef struct pjsip_route_hdr pjsip_route_hdr;
typedef struct pjsip_msg pjsip_msg;

struct pjsip_method {
    int type;
    struct {
        const char *ptr;
        int slen;
    } name;
};

struct pjsip_hdr {
    int type;
    struct pjsip_hdr *prev;
};

struct pjsip_route_hdr {
    struct pjsip_hdr hdr;
};

struct pjsip_msg {
    int type;
    struct {
        struct {
            int code;
        } status;
    } line;
    struct pjsip_hdr hdr;
};

typedef struct {
    struct pjsip_method method;
} pjsip_cseq;

typedef struct {
    pjsip_cseq *cseq;
    pjsip_msg *msg;
} pjsip_msg_info;

typedef struct {
    const char *host;
} pjsip_hostname;

typedef struct {
    pjsip_hostname remote_name;
} pjsip_transport;

typedef struct {
    pjsip_transport *transport;
} pjsip_tp_info;

typedef struct pjsip_rx_data {
    pjsip_msg_info msg_info;
    pjsip_tp_info tp_info;
} pjsip_rx_data;

typedef struct pjsip_dialog {
    int route_set_frozen;
    int role;
    struct {
        int slen;
    } initial_dest;
    void *pool;
    struct pjsip_hdr *route_set;
    const char *obj_name;
} pjsip_dialog;

#define PJSIP_OTHER_METHOD 0
#define PJSIP_ROLE_UAC 0
#define PJSIP_RESPONSE_MSG 0
#define PJSIP_H_RECORD_ROUTE 0
#define PJ_TRUE 1

void pj_strdup(void *pool, void *dst, const char *src);
int pjsip_method_cmp(const struct pjsip_method *m1, const struct pjsip_method *m2);
void pj_list_init(struct pjsip_hdr *list);
void *pjsip_hdr_clone(void *pool, const struct pjsip_hdr *hdr);
void pjsip_routing_hdr_set_route(struct pjsip_route_hdr *r);
void pj_list_push_back(struct pjsip_hdr *list, struct pjsip_hdr *item);
int pjsip_method_creates_dialog(const struct pjsip_method *method);
#define PJSIP_IS_STATUS_IN_CLASS(code, class) ((code)/100 == (class)/100)
#define PJ_LOG(level, args)
void pj_assert(const char *msg);
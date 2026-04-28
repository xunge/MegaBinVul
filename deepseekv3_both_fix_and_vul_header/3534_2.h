#include <stdint.h>
#include <string.h>

#define ETH_ALEN 6
#define EINVAL 22
#define ECONNABORTED 103
#define ENOMEM 12
#define SINGLE_DEPTH_NESTING 1
#define IB_CM_SIDR_REQ_RECEIVED 1
#define IB_CM_SIDR_REQ_PRIVATE_DATA_SIZE 72
#define CMA_CM_MRA_SETTING 0

typedef uint8_t u8;

enum RDMA_TRANSPORT {
    RDMA_TRANSPORT_IB
};

enum IB_LINK_LAYER {
    IB_LINK_LAYER_ETHERNET
};

enum RDMA_CM_EVENT_TYPE {
    RDMA_CM_EVENT_CONNECT_REQUEST
};

enum RDMA_CM_STATE {
    RDMA_CM_LISTEN,
    RDMA_CM_CONNECT,
    RDMA_CM_DESTROYING
};

enum IB_QP_TYPE {
    IB_QPT_UD
};

struct ib_device {
    int node_type;
};

struct ib_cm_id {
    struct ib_device *device;
    void *context;
    void (*cm_handler)(struct ib_cm_id *, void *);
};

struct ib_cm_event {
    int event;
    struct {
        struct {
            int port;
            struct {
                void *sgid;
            } *primary_path;
            struct {
                void *sgid;
            } *alternate_path;
        } req_rcvd;
    } param;
    void *private_data;
};

struct rdma_cm_id {
    int (*event_handler)(struct rdma_cm_id *, void *);
    int qp_type;
};

struct rdma_cm_event {
    int event;
    union {
        struct {
            void *private_data;
            int private_data_len;
        } ud;
    } param;
};

struct rdma_id_private {
    struct rdma_cm_id id;
    struct {
        struct ib_cm_id *ib;
    } cm_id;
    int refcount;
    struct {
        int dummy;
    } handler_mutex;
};

static struct {
    int dummy;
} lock;

static int rdma_node_get_transport(int node_type) { return RDMA_TRANSPORT_IB; }
static int rdma_port_get_link_layer(struct ib_device *device, int port) { return IB_LINK_LAYER_ETHERNET; }
static int cma_check_req_qp_type(struct rdma_cm_id *id, struct ib_cm_event *event) { return 1; }
static int cma_disable_callback(struct rdma_id_private *id, int state) { return 0; }
static int cma_user_data_offset(struct rdma_id_private *id) { return 0; }
static struct rdma_id_private *cma_new_udp_id(struct rdma_cm_id *id, struct ib_cm_event *event) { return (void *)1; }
static struct rdma_id_private *cma_new_conn_id(struct rdma_cm_id *id, struct ib_cm_event *event) { return (void *)1; }
static void cma_set_req_event_data(struct rdma_cm_event *event, void *req_rcvd, void *private_data, int offset) {}
static int cma_acquire_dev(struct rdma_id_private *conn_id, struct rdma_id_private *listen_id) { return 0; }
static void cma_ib_handler(struct ib_cm_id *cm_id, void *event) {}
static void cma_deref_id(struct rdma_id_private *id) {}
static void cma_exch(struct rdma_id_private *id, int state) {}
static void rdma_destroy_id(struct rdma_cm_id *id) {}
static void rdma_addr_find_smac_by_sgid(void *sgid, u8 *smac, void *null) {}
static void ib_update_cm_av(struct ib_cm_id *cm_id, u8 *psmac, u8 *palt_smac) {}
static int cma_comp(struct rdma_id_private *id, int state) { return 1; }
static void ib_send_cm_mra(struct ib_cm_id *cm_id, int setting, void *null, int zero) {}

#define mutex_lock_nested(lock, subclass) (void)0
#define mutex_lock(lock) (void)0
#define mutex_unlock(lock) (void)0
#define atomic_inc(v) (*(v))++
#include <stdint.h>
#include <stddef.h>

struct srpt_rdma_ch {
    struct se_session *sess;
    void *cm_id;
};

struct srpt_recv_ioctx {
    struct {
        struct srp_tsk_mgmt *buf;
    } ioctx;
};

struct srpt_send_ioctx {
    struct {
        uint32_t tag;
        struct se_tmr_req *se_tmr_req;
    } cmd;
};

struct se_session;

struct se_tmr_req {
    int response;
};

struct srp_tsk_mgmt {
    int tsk_mgmt_func;
    uint64_t task_tag;
    uint32_t tag;
    uint8_t lun[8];
};

#define BUG_ON(condition)
#define pr_debug(fmt, ...)

#define SRPT_STATE_MGMT 0
#define TMR_TASK_MGMT_FUNCTION_NOT_SUPPORTED 0
#define TMR_TASK_DOES_NOT_EXIST 0
#define TMR_FUNCTION_REJECTED 0
#define SRP_TSK_ABORT_TASK 0
#define GFP_KERNEL 0
#define TARGET_SCF_ACK_KREF 0

static int srpt_unpack_lun(uint8_t *lun, size_t len) { return 0; }
static int srp_tmr_to_tcm(int func) { return 0; }
static int srpt_rx_mgmt_fn_tag(struct srpt_send_ioctx *ioctx, uint64_t tag) { return 0; }
static void srpt_set_cmd_state(struct srpt_send_ioctx *ioctx, int state) {}
static int target_submit_tmr(struct srpt_send_ioctx *cmd, struct se_session *sess, void *priv, uint64_t lun, void *tmr, int tcm_tmr, int gfp, uint32_t tag, int flags) { return 0; }
static void transport_send_check_condition_and_sense(struct srpt_send_ioctx *cmd, int a, int b) {}
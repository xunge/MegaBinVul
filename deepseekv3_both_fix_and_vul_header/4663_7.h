#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>
#include <errno.h>

typedef long ssize_t;
typedef unsigned long size_t;
typedef unsigned long __u64;

#define __user
#define WARN_ON_ONCE(x) (x)
#define ACCESS_ONCE(x) (x)

struct file {
    void *private_data;
};

struct hfi1_filedata {
    struct hfi1_ctxtdata *uctxt;
    int subctxt;
};

struct hfi1_ctxtdata {
    struct send_context *sc;
    struct hfi1_devdata *dd;
    int ctxt;
    int poll_type;
};

struct hfi1_cmd {
    int type;
    unsigned long addr;
    size_t len;
};

struct hfi1_user_info {
    // Add required fields
};

struct hfi1_tid_info {
    unsigned int tidcnt;
    unsigned int length;
    // Add other required fields
};

struct send_context {
    unsigned int flags;
    int halt_wait;
    // Add other required fields
};

struct hfi1_devdata {
    unsigned int flags;
    int event_queue;
    // Add other required fields
};

#define HFI1_CMD_ASSIGN_CTXT 0
#define HFI1_CMD_SDMA_STATUS_UPD 1
#define HFI1_CMD_CREDIT_UPD 2
#define HFI1_CMD_TID_UPDATE 3
#define HFI1_CMD_TID_FREE 4
#define HFI1_CMD_TID_INVAL_READ 5
#define HFI1_CMD_USER_INFO 6
#define HFI1_CMD_RECV_CTRL 7
#define HFI1_CMD_POLL_TYPE 8
#define HFI1_CMD_ACK_EVENT 9
#define HFI1_CMD_CTXT_INFO 10
#define HFI1_CMD_SET_PKEY 11
#define HFI1_CMD_CTXT_RESET 12
#define HFI1_CMD_EP_INFO 13
#define HFI1_CMD_EP_ERASE_CHIP 14
#define HFI1_CMD_EP_ERASE_RANGE 15
#define HFI1_CMD_EP_READ_RANGE 16
#define HFI1_CMD_EP_WRITE_RANGE 17

#define SCF_HALTED (1 << 0)
#define SCF_FROZEN (1 << 1)
#define HFI1_FROZEN (1 << 0)
#define HFI1_FORCED_FREEZE (1 << 1)
#define SEND_CTXT_HALT_TIMEOUT 1000
#define HFI1_RCVCTRL_CTXT_ENB 0
#define HFI1_CAP_IS_USET(x) 0
#define PKEY_CHECK 0
#define CAP_SYS_ADMIN 0

static inline int ib_safe_file_access(struct file *fp) { return 1; }
static int assign_ctxt(struct file *fp, struct hfi1_user_info *uinfo) { return 0; }
static int setup_ctxt(struct file *fp) { return 0; }
static int user_init(struct file *fp) { return 0; }
static int get_ctxt_info(struct file *fp, void *addr, size_t len) { return 0; }
static int get_base_info(struct file *fp, void *addr, size_t len) { return 0; }
static void sc_return_credits(struct send_context *sc) {}
static int hfi1_user_exp_rcv_setup(struct file *fp, struct hfi1_tid_info *tinfo) { return 0; }
static int hfi1_user_exp_rcv_invalid(struct file *fp, struct hfi1_tid_info *tinfo) { return 0; }
static int hfi1_user_exp_rcv_clear(struct file *fp, struct hfi1_tid_info *tinfo) { return 0; }
static int manage_rcvq(struct hfi1_ctxtdata *uctxt, int subctxt, int val) { return 0; }
static int user_event_ack(struct hfi1_ctxtdata *uctxt, int subctxt, __u64 val) { return 0; }
static int set_ctxt_pkey(struct hfi1_ctxtdata *uctxt, int subctxt, __u64 val) { return 0; }
static void sc_disable(struct send_context *sc) {}
static int sc_enable(struct send_context *sc) { return 0; }
static void hfi1_rcvctrl(struct hfi1_devdata *dd, int ctrl, int ctxt) {}
static int sc_restart(struct send_context *sc) { return 0; }
static int handle_eprom_command(struct file *fp, struct hfi1_cmd *cmd) { return 0; }
static int copy_from_user(void *to, const void *from, size_t n) { return 0; }
static int copy_to_user(void *to, const void *from, size_t n) { return 0; }
static int capable(int cap) { return 1; }
static void wait_event_interruptible_timeout(int wait, int condition, unsigned long timeout) {}
static unsigned long msecs_to_jiffies(unsigned int msecs) { return 0; }
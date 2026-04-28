#include <stdint.h>
#include <stddef.h>

struct kern_ipc_perm {
    int key;
};

struct msg_msg {
};

struct task_struct {
};

struct ipc_security_struct {
    uint32_t sid;
};

struct msg_security_struct {
    uint32_t sid;
};

struct common_audit_data {
    int type;
    union {
        int ipc_id;
    } u;
};

struct selinux_state {
};

extern struct selinux_state selinux_state;

#define LSM_AUDIT_DATA_IPC 0
#define SECCLASS_MSGQ 0
#define MSGQ__READ 0
#define SECCLASS_MSG 0
#define MSG__RECEIVE 0

typedef uint32_t u32;
typedef uint16_t u16;

static inline struct ipc_security_struct *selinux_ipc(struct kern_ipc_perm *ipc) { return NULL; }
static inline struct msg_security_struct *selinux_msg_msg(struct msg_msg *msg) { return NULL; }
static inline u32 task_sid_subj(struct task_struct *task) { return 0; }
static inline int avc_has_perm(struct selinux_state *state, u32 ssid, u32 tsid, u16 tclass, u32 perms, struct common_audit_data *ad) { return 0; }
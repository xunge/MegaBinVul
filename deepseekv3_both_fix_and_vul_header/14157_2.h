#include <stddef.h>
#include <stdint.h>

struct task_struct;
struct selinux_state;
extern struct selinux_state selinux_state;
extern struct task_struct *current;

#define SECCLASS_PROCESS 0
#define PROCESS__PTRACE 0

typedef uint32_t u32;
typedef uint16_t u16;

static inline u32 task_sid_subj(struct task_struct *p) { return 0; }
static inline u32 task_sid_obj(struct task_struct *p) { return 0; }
static int avc_has_perm(struct selinux_state *state, u32 ssid, u32 tsid, u16 tclass, u32 requested, void *auditdata) { return 0; }
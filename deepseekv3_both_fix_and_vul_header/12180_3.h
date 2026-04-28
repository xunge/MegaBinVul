#include <stdatomic.h>
#include <stdint.h>
#include <stddef.h>
#include <time.h>

typedef uint16_t __le16;
typedef uint16_t __u16;

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

struct kref {
    _Atomic int refcount;
};

struct task_struct;

struct TCP_Server_Info_vals {
    __le16 lock_cmd;
};

struct TCP_Server_Info_ops {
    void (*handle_cancelled_mid)(void *, void *);
};

struct TCP_Server_Info {
    struct TCP_Server_Info_ops *ops;
    struct TCP_Server_Info_vals *vals;
    _Atomic int num_cmds[1];
    unsigned long slowest_cmd[1];
    unsigned long fastest_cmd[1];
    unsigned long time_per_cmd[1];
    _Atomic int smb2slowcmd[1];
};

struct mid_q_entry {
    struct kref refcount;
    struct TCP_Server_Info *server;
    void *resp_buf;
    unsigned int mid_flags;
    int mid_state;
    int large_buf;
    uint16_t command;
    unsigned long when_alloc;
    unsigned long when_sent;
    unsigned long when_received;
    unsigned long long mid;
    int pid;
    struct task_struct *creator;
};

#define CONFIG_CIFS_STATS2 1
#define MID_WAIT_CANCELLED 0
#define MID_RESPONSE_RECEIVED 0
#define MID_RESPONSE_READY 0
#define MID_FREE 0
#define NUMBER_OF_SMB2_COMMANDS 1
#define slow_rsp_threshold 0
#define HZ 100
#define CIFS_TIMER 0
#define VFS 0
#define cifsFYI 0

extern _Atomic int mid_count;
extern void *cifs_mid_poolp;
extern unsigned long jiffies;

static inline __le16 le16_to_cpu(__le16 val) { return val; }
static inline int time_after(unsigned long a, unsigned long b) { return a > b; }
static inline void atomic_dec(_Atomic int *v) { (*v)--; }
static inline int atomic_read(_Atomic int *v) { return *v; }

void cifs_buf_release(void *);
void cifs_small_buf_release(void *);
void cifs_stats_inc(_Atomic int *);
void cifs_server_dbg(int, const char *);
void cifs_info(const char *, ...);
void trace_smb3_slow_rsp(int, unsigned long long, int, unsigned long, unsigned long);
void pr_debug(const char *, ...);
void put_task_struct(struct task_struct *);
void mempool_free(void *, void *);
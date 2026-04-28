#include <stdint.h>
#include <stddef.h>

struct vcpu {
    struct domain *domain;
    int vcpu_id;
};

struct domain {
    struct xenoprof *xenoprof;
};

struct xenoprof {
    struct xenoprof_vcpu *vcpu;
};

struct xenoprof_vcpu {
    struct xenoprof_buf *buffer;
    int event_size;
};

struct cpu_user_regs;

struct xenoprof_buf {
    unsigned long lost_samples;
    unsigned long user_samples;
    unsigned long kernel_samples;
    unsigned long xen_samples;
    unsigned int event_head;
    unsigned int event_tail;
};

#define XENOPROF_ESCAPE_CODE 0
#define XENOPROF_TRACE_BEGIN 1

extern unsigned long total_samples;
extern unsigned long others_samples;
extern unsigned long invalid_buffer_samples;
extern unsigned long lost_samples;
extern unsigned long active_samples;
extern unsigned long passive_samples;
extern int backtrace_depth;

int is_profiled(struct domain *d);
int is_active(struct domain *d);
int xenoprof_buf_space(struct domain *d, struct xenoprof_buf *buf, int size);
int xenoprof_add_sample(struct domain *d, struct xenoprof_buf *buf, uint64_t pc, int mode, int event);
void xenoprof_backtrace(struct vcpu *vcpu, const struct cpu_user_regs *regs, int depth, int mode);

typedef struct xenoprof_buf xenoprof_buf_t;

#define xenoprof_buf(d, buf, field) ((buf)->field)
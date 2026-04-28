#include <stdint.h>

struct xenoprof_buf;

struct vcpu {
    struct domain *domain;
    int vcpu_id;
};

struct domain {
    struct {
        struct {
            struct xenoprof_buf *buffer;
        } *vcpu;
    } *xenoprof;
};

typedef struct xenoprof_buf xenoprof_buf_t;

#define XENOPROF_ESCAPE_CODE 0

extern int invalid_buffer_samples;
extern int xenoprof_add_sample(struct domain *d, xenoprof_buf_t *buf, uint64_t pc, int mode, int flags);
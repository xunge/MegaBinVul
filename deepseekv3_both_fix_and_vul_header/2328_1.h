#include <stdint.h>

#define X86EMUL_OKAY 0
#define X86EMUL_UNHANDLEABLE 1

#define IOREQ_READ 0
#define IOREQ_WRITE 1

#define IOREQ_TYPE_COPY 0

#define HVMTRANS_okay 0
#define HVMTRANS_bad_gfn_to_mfn 1
#define HVMTRANS_bad_linear_to_gfn 2
#define HVMTRANS_gfn_paged_out 3
#define HVMTRANS_gfn_shared 4

struct hvm_io_ops {
    int (*read)(const struct hvm_io_handler *, uint64_t, int, uint64_t *);
    int (*write)(const struct hvm_io_handler *, uint64_t, int, uint64_t);
};

struct hvm_io_handler {
    const struct hvm_io_ops *ops;
};

typedef struct {
    int df;
    int size;
    int dir;
    int count;
    int type;
    int data_is_ptr;
    uint64_t addr;
    uint64_t data;
} ioreq_t;

struct domain;

struct task_struct {
    struct domain *domain;
};

extern struct task_struct *current;

void ASSERT_UNREACHABLE(void);
void domain_crash(struct domain *);
int hvm_copy_to_guest_phys(uint64_t, const void *, int, struct task_struct *);
int hvm_copy_from_guest_phys(void *, uint64_t, int);
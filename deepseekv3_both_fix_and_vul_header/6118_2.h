#include <stdint.h>
#include <stddef.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define KVM_PAM 0x0fffffffffffffffUL
#define EINVAL 22
#define ENOENT 2

typedef uint32_t rtas_arg_t;
typedef uint64_t gpa_t;

struct kvm_vcpu;
struct kvm;

struct rtas_args {
    uint32_t token;
    uint32_t nargs;
    uint32_t nret;
    rtas_arg_t args[16];
    rtas_arg_t *rets;
};

struct rtas_handler {
    void (*handler)(struct kvm_vcpu *, struct rtas_args *);
};

struct rtas_token_definition {
    uint32_t token;
    struct rtas_handler *handler;
    struct rtas_token_definition *next;
    struct rtas_token_definition *prev;
};

struct kvm_arch {
    struct rtas_token_definition *rtas_tokens;
    struct {
        int dummy;
    } rtas_token_lock;
};

struct kvm {
    struct kvm_arch arch;
    struct {
        int dummy;
    } srcu;
};

struct kvm_vcpu {
    struct kvm* kvm;
    int srcu_idx;
};

static inline uint32_t be32_to_cpu(uint32_t x) {
    return __builtin_bswap32(x);
}

static inline gpa_t kvmppc_get_gpr(struct kvm_vcpu *vcpu, int r) {
    return 0;
}

static inline int kvm_read_guest(struct kvm *kvm, gpa_t gpa, void *data, unsigned long len) {
    return 0;
}

static inline int kvm_write_guest(struct kvm *kvm, gpa_t gpa, void *data, unsigned long len) {
    return 0;
}

static inline int srcu_read_lock(struct kvm *kvm) {
    return 0;
}

static inline void srcu_read_unlock(struct kvm *kvm, int idx) {
}

static inline void mutex_lock(struct kvm_arch *arch) {
}

static inline void mutex_unlock(struct kvm_arch *arch) {
}

#define list_for_each_entry(pos, head, member) \
    for (pos = (head); pos != NULL; pos = pos->next)
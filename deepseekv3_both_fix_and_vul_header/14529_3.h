#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

#define BPF_REG_1 1
#define BPF_MAX_VAR_SIZ (1 << 29)
#define EACCES 13
#define EINVAL 22
#define EFAULT 14
#define BPF_READ 0
#define SRC_OP 1
#define BPF_FUNC_spin_lock 1
#define BPF_FUNC_spin_unlock 2

typedef uint32_t u32;
typedef uint64_t u64;
typedef int64_t s64;

struct bpf_verifier_env;
struct btf;

enum bpf_arg_type {
    ARG_DONTCARE,
    ARG_ANYTHING,
    ARG_PTR_TO_MAP_VALUE,
    ARG_PTR_TO_UNINIT_MAP_VALUE,
    ARG_CONST_MAP_PTR,
    ARG_PTR_TO_MAP_KEY,
    ARG_PTR_TO_PERCPU_BTF_ID,
    ARG_PTR_TO_SPIN_LOCK,
    ARG_PTR_TO_TIMER,
    ARG_PTR_TO_FUNC,
    ARG_PTR_TO_MEM,
    ARG_PTR_TO_UNINIT_MEM,
    ARG_PTR_TO_ALLOC_MEM,
    ARG_PTR_TO_BUF,
    ARG_CONST_SIZE,
    ARG_CONST_SIZE_OR_ZERO,
    ARG_PTR_TO_CONST_STR
};

enum bpf_reg_type {
    NOT_INIT,
    SCALAR_VALUE,
    PTR_TO_CTX,
    PTR_TO_PACKET,
    PTR_TO_PACKET_META,
    PTR_TO_MAP_KEY,
    PTR_TO_MAP_VALUE,
    PTR_TO_MEM,
    PTR_TO_BUF,
    PTR_TO_STACK,
    PTR_TO_BTF_ID,
    MEM_RDONLY = 0x10,
};

struct tnum {
    u64 value;
    u64 mask;
};

struct bpf_map {
    u32 key_size;
    u32 value_size;
    bool (*map_direct_value_addr)(struct bpf_map *map, u64 *addr, int off);
    bool is_rdonly;
    struct bpf_map_ops *ops;
};

struct bpf_map_ops {
    bool (*map_direct_value_addr)(struct bpf_map *map, u64 *addr, int off);
};

struct bpf_func_proto {
    enum bpf_arg_type arg_type[5];
    u32 arg_btf_id[5];
};

struct bpf_call_arg_meta {
    struct bpf_map *map_ptr;
    u32 map_uid;
    u32 subprogno;
    u64 msize_max_value;
    u64 mem_size;
    bool raw_mode;
    const struct btf *ret_btf;
    u32 ret_btf_id;
    u32 ref_obj_id;
    int func_id;
};

struct bpf_reg_state {
    enum bpf_reg_type type;
    u32 off;
    u32 id;
    u32 ref_obj_id;
    u32 map_uid;
    struct bpf_map *map_ptr;
    const struct btf *btf;
    u32 btf_id;
    u32 subprogno;
    struct tnum var_off;
    s64 smin_value;
    u64 umin_value;
    u64 umax_value;
};

static inline bool arg_type_is_mem_ptr(enum bpf_arg_type type) {
    return type == ARG_PTR_TO_MEM || type == ARG_PTR_TO_UNINIT_MEM;
}

static inline bool arg_type_is_mem_size(enum bpf_arg_type type) {
    return type == ARG_CONST_SIZE || type == ARG_CONST_SIZE_OR_ZERO;
}

static inline bool arg_type_is_alloc_size(enum bpf_arg_type type) {
    return type == ARG_PTR_TO_ALLOC_MEM;
}

static inline bool arg_type_is_int_ptr(enum bpf_arg_type type) {
    return false;
}

static inline char *strnchr(const char *s, size_t count, int c) {
    return NULL;
}

static inline struct bpf_reg_state *cur_regs(struct bpf_verifier_env *env) { return NULL; }
static inline int check_reg_arg(struct bpf_verifier_env *env, u32 regno, int op) { return 0; }
static inline bool is_pointer_value(struct bpf_verifier_env *env, u32 regno) { return false; }
static inline void verbose(struct bpf_verifier_env *env, const char *fmt, ...) {}
static inline bool type_is_pkt_pointer(enum bpf_reg_type type) { return false; }
static inline bool may_access_direct_pkt_data(struct bpf_verifier_env *env, 
                                            struct bpf_call_arg_meta *meta,
                                            int op) { return false; }
static inline enum bpf_arg_type base_type(enum bpf_arg_type type) { return type; }
static inline int resolve_map_arg_type(struct bpf_verifier_env *env,
                                     struct bpf_call_arg_meta *meta,
                                     enum bpf_arg_type *arg_type) { return 0; }
static inline bool register_is_null(struct bpf_reg_state *reg) { return false; }
static inline bool type_may_be_null(enum bpf_arg_type type) { return false; }
static inline int check_reg_type(struct bpf_verifier_env *env, u32 regno,
                               enum bpf_arg_type arg_type, u32 btf_id) { return 0; }
static inline int __check_ptr_off_reg(struct bpf_verifier_env *env,
                                    struct bpf_reg_state *reg, u32 regno,
                                    bool is_btf_id) { return 0; }
static inline int check_helper_mem_access(struct bpf_verifier_env *env, u32 regno,
                                        u32 size, bool zero_size_allowed,
                                        struct bpf_call_arg_meta *meta) { return 0; }
static inline int mark_chain_precision(struct bpf_verifier_env *env, u32 regno) { return 0; }
static inline int process_spin_lock(struct bpf_verifier_env *env, u32 regno, bool lock) { return 0; }
static inline int process_timer_func(struct bpf_verifier_env *env, u32 regno,
                                   struct bpf_call_arg_meta *meta) { return 0; }
static inline int check_ptr_alignment(struct bpf_verifier_env *env,
                                    struct bpf_reg_state *reg, u32 off,
                                    int size, bool strict) { return 0; }
static inline int check_map_access(struct bpf_verifier_env *env, u32 regno,
                                 u32 off, u32 size, bool zero_size_allowed) { return 0; }
static inline bool bpf_map_is_rdonly(struct bpf_map *map) { return false; }
static inline bool tnum_is_const(struct tnum t) { return true; }
static inline int int_ptr_type_to_size(enum bpf_arg_type type) { return 0; }
#include <stddef.h>
#include <errno.h>

#define __user
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define EINVAL 22

struct btf;
struct bpf_prog_aux {
    struct btf *btf;
};

struct bpf_prog {
    struct bpf_prog_aux *aux;
};

struct bpf_verifier_env {
    struct bpf_prog *prog;
};

union bpf_attr {
    unsigned int func_info_cnt;
    unsigned int line_info_cnt;
    int prog_btf_fd;
};

static int check_abnormal_return(struct bpf_verifier_env *env);
static int check_btf_func(struct bpf_verifier_env *env, const union bpf_attr *attr, union bpf_attr *uattr);
static int check_btf_line(struct bpf_verifier_env *env, const union bpf_attr *attr, union bpf_attr *uattr);
struct btf *btf_get_by_fd(int fd);
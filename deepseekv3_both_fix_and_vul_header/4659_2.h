#include <stdatomic.h>
#include <errno.h>
#include <stdint.h>

typedef uint32_t u32;

struct fd {
    int dummy;
};

struct bpf_prog_aux {
    _Atomic int refcnt;
};

struct bpf_prog {
    struct bpf_prog_aux *aux;
};

#define IS_ERR(x) ((unsigned long)(x) >= (unsigned long)-4095)
#define PTR_ERR(x) ((long)(x))
#define ERR_PTR(x) ((void *)(long)(x))

struct bpf_prog *__bpf_prog_get(struct fd f);
struct fd fdget(u32 fd);
void fdput(struct fd f);
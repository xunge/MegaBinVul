#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <stdio.h>

typedef void *scmp_filter_ctx;

#define SCMP_ARCH_NATIVE 0
#define SCMP_FLTATR_ACT_BADARCH 1
#define SCMP_ACT_ALLOW 0
#define SCMP_ACT_ERRNO(x) (0x00050000 | ((x) & 0x0000ffff))
#define __NR_SCMP_ERROR -1
#define SCMP_CMP_MASKED_EQ 1

struct scmp_arg_cmp {
    unsigned int arg;
    int op;
    uint32_t datum_a;
    uint32_t datum_b;
};

static inline void showerr(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

static inline uint32_t seccomp_arch_native(void) { return 0; }
static inline int seccomp_arch_remove(scmp_filter_ctx ctx, uint32_t arch) { return 0; }
static inline int seccomp_arch_add(scmp_filter_ctx ctx, uint32_t arch) { return 0; }
static inline int seccomp_attr_set(scmp_filter_ctx ctx, int attr, uint32_t value) { return 0; }
static inline int seccomp_syscall_resolve_name(const char *name) { return 0; }
static inline int seccomp_rule_add(scmp_filter_ctx ctx, uint32_t action, int syscall, unsigned int arg_cnt, ...) { return 0; }
#include <stdint.h>

typedef struct pgd_t {
    void *pgd;
} pgd_t;

struct mm_struct {
    pgd_t *pgd;
    struct {
        unsigned long asce_bits;
        int noexec;
    } context;
};

struct task_struct {
    struct {
        unsigned long mm_segment;
    } thread;
};

struct lowcore {
    unsigned long user_asce;
    unsigned long user_exec_asce;
};

extern struct lowcore S390_lowcore;
extern int switch_amode;
extern struct task_struct *current;

pgd_t *get_shadow_table(pgd_t *pgd);
void set_fs(unsigned long seg);

#define __pa(x) ((uintptr_t)(x))
#define LCTL_OPCODE "lctl"
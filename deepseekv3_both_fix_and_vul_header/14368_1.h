#include <stdint.h>
#include <stddef.h>

typedef uint64_t target_ulong;
typedef target_ulong tb_page_addr_t;

struct CPUState {
    void *env_ptr;
};

struct uc_struct {
    struct CPUState *cpu;
};

extern tb_page_addr_t get_page_addr_code(void *env_ptr, uint64_t addr);
extern void tb_invalidate_phys_range(struct uc_struct *uc, tb_page_addr_t start, tb_page_addr_t end);
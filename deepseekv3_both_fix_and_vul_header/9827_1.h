#include <stddef.h>
#include <string.h>
#include <stdint.h>

struct bfa_iocfc_cfg_s;
struct bfa_meminfo_s;
struct bfa_mem_part_s {
    int mem_type;
    uint32_t mem_len;
};

struct bfa_meminfo_s {
    struct bfa_mem_part_s meminfo[2];
};

enum {
    BFA_MEM_TYPE_KVA = 1,
    BFA_MEM_TYPE_DMA = 2
};

typedef uint32_t u32;

extern void bfa_assert(int);
extern void bfa_os_memset(void *, int, size_t);
extern void bfa_iocfc_meminfo(struct bfa_iocfc_cfg_s *, u32 *, u32 *);

struct hal_mod_s {
    void (*meminfo)(struct bfa_iocfc_cfg_s *, u32 *, u32 *);
};
extern struct hal_mod_s *hal_mods[];
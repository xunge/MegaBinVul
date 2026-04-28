#include <stdbool.h>

#define BFA_FALSE false
#define BFA_MEM_TYPE_MAX 32

struct bfa_s {
    bool fcs;
};

struct bfa_iocfc_cfg_s;
struct bfa_meminfo_s;
struct bfa_pcidev_s;

struct bfa_mem_elem_s {
    void *kva_curp;
    void *kva;
    void *dma_curp;
    void *dma;
};

struct bfa_meminfo_s {
    struct bfa_mem_elem_s meminfo[BFA_MEM_TYPE_MAX];
};

struct bfa_hal_mod_s {
    void (*attach)(struct bfa_s *, void *, struct bfa_iocfc_cfg_s *,
                  struct bfa_meminfo_s *, struct bfa_pcidev_s *);
};

extern struct bfa_hal_mod_s *hal_mods[];

#define bfa_assert(cond) ((void)0)

void bfa_iocfc_attach(struct bfa_s *bfa, void *bfad, struct bfa_iocfc_cfg_s *cfg,
                     struct bfa_meminfo_s *meminfo, struct bfa_pcidev_s *pcidev);
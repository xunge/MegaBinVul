#include <stdint.h>

typedef uint64_t kvm_pte_t;
typedef uint64_t u64;

enum pkvm_page_state {
    PKVM_NOPAGE
};

static int kvm_pte_valid(kvm_pte_t pte);
static enum pkvm_page_state pkvm_getstate(int prot);
static int kvm_pgtable_stage2_pte_prot(kvm_pte_t pte);
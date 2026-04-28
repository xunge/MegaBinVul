#include <stdint.h>

enum pkvm_page_state {
    PKVM_NOPAGE,
};

typedef uint64_t kvm_pte_t;
typedef uint64_t u64;

int kvm_pte_valid(kvm_pte_t pte);
enum pkvm_page_state pkvm_getstate(int prot);
int kvm_pgtable_stage2_pte_prot(kvm_pte_t pte);
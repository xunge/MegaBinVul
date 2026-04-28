#include <stddef.h>
#include <stdint.h>
#include <errno.h>

typedef unsigned long paddr_t;
typedef unsigned int nodeid_t;

#define NUMA_NO_NODE (-1)
#define MEMF_node(node) (0)
#define CONFIG_PV 1

struct page_info;
typedef unsigned long mfn_t;

#define per_cpu(var, cpu) (var)
#define cpu_to_node(cpu) (0)
#define cpu_has_fsgsbase (0)
#define page_to_mfn(pg) ((mfn_t)0)
#define page_to_maddr(pg) ((paddr_t)0)
#define clear_domain_page(mfn) 
#define __map_domain_page_global(pg) (NULL)

static struct page_info *alloc_domheap_page(void *dom, unsigned int flags) { return NULL; }
static void svm_cpu_dead(unsigned int cpu) {}

paddr_t hsa;
paddr_t host_vmcb;
void *host_vmcb_va;
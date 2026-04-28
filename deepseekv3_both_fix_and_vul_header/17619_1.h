#include <stdlib.h>
#include <stdbool.h>

struct svm_cpu_data {
    int cpu;
    void *save_area;
    void **sev_vmcbs;
};

extern bool svm_sev_enabled(void);
extern unsigned int max_sev_asid;
extern struct svm_cpu_data **svm_data;

#define GFP_KERNEL 0
#define ENOMEM 12
#define per_cpu(var, cpu) (var[cpu])

void *kzalloc(size_t size, int flags);
void *kmalloc_array(size_t n, size_t size, int flags);
void kfree(void *ptr);
void *alloc_page(int flags);
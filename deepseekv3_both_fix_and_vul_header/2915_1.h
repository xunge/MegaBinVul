#include <stdbool.h>
#include <stddef.h>

struct kvm_vcpu {
    struct {
        bool pv_time_enabled;
        void *time_page;
    } arch;
};

void kvm_release_page_dirty(void *page);
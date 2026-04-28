#include <pthread.h>

struct vm_area_struct;
struct kvm {
    struct {
        pthread_mutex_t uvmem_lock;
    } arch;
};
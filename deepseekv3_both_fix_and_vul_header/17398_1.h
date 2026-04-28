#include <stddef.h>
#include <stdbool.h>
#include <errno.h>

#define FOLL_WRITE    0x01
#define FOLL_REMOTE   0x02
#define FOLL_ANON     0x04
#define FOLL_FORCE    0x08

#define VM_IO         0x00000001
#define VM_PFNMAP     0x00000002
#define VM_WRITE      0x00000004
#define VM_READ       0x00000008
#define VM_MAYREAD    0x00000010
#define VM_MAYWRITE   0x00000020

typedef unsigned long vm_flags_t;

struct vm_area_struct {
    vm_flags_t vm_flags;
};

static inline int vma_is_anonymous(struct vm_area_struct *vma) {
    return 0;
}

static inline int is_cow_mapping(vm_flags_t flags) {
    return 0;
}

static inline int arch_vma_access_permitted(struct vm_area_struct *vma, 
                                          int write, bool execute, int foreign) {
    return 0;
}
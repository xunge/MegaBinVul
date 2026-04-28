#include <sys/mman.h>
#include <errno.h>

#define VM_HUGEPAGE     0x00020000
#define VM_NOHUGEPAGE   0x00040000
#define VM_NO_THP       0x00080000
#define VM_SHARED       0x00000001
#define VM_MAYSHARE     0x00000002
#define VM_PFNMAP       0x00000004
#define VM_IO           0x00000008
#define VM_DONTEXPAND   0x00000010
#define VM_RESERVED     0x00000020
#define VM_HUGETLB      0x00000040
#define VM_INSERTPAGE   0x00000080
#define VM_MIXEDMAP     0x00000100
#define VM_SAO          0x00000200

#define MADV_HUGEPAGE   14
#define MADV_NOHUGEPAGE 15

struct vm_area_struct;
int khugepaged_enter_vma_merge(struct vm_area_struct *vma);
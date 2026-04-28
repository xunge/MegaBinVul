#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define ACRN_INVALID_VMID 0
#define EINVAL 22
#define EFAULT 14
#define ENODEV 19
#define ENOTTY 25
#define EEXIST 17

typedef uint64_t u64;

#define __user
#define FOLL_WRITE 0x01
#define FOLL_LONGTERM 0x02

struct file {
    void *private_data;
};

struct device;
struct page;

struct acrn_vm {
    unsigned int vmid;
    struct page *monitor_page;
    void *default_client;
    struct device *this_device;
};

struct acrn_vm_creation {
    unsigned long reserved0;
    unsigned long reserved1;
};

struct acrn_vcpu_regs {
    struct {
        unsigned long reserved_32[16];
        unsigned long reserved_64[16];
        struct {
            unsigned long reserved[16];
        } gdt;
        struct {
            unsigned long reserved[16];
        } idt;
    } vcpu_regs;
    unsigned long reserved[16];
};

struct acrn_ioreq_notify {
    unsigned int vcpu;
    unsigned int reserved;
};

struct acrn_ptdev_irq {};
struct acrn_ioeventfd {
    unsigned int reserved;
};
struct acrn_vm_memmap {};
struct acrn_mmiodev {};
struct acrn_msi_entry {};
struct acrn_pcidev {};
struct acrn_irqfd {};
struct acrn_vdev {};

enum {
    ACRN_IOCTL_CREATE_VM,
    ACRN_IOCTL_START_VM,
    ACRN_IOCTL_PAUSE_VM,
    ACRN_IOCTL_RESET_VM,
    ACRN_IOCTL_DESTROY_VM,
    ACRN_IOCTL_SET_VCPU_REGS,
    ACRN_IOCTL_SET_MEMSEG,
    ACRN_IOCTL_UNSET_MEMSEG,
    ACRN_IOCTL_ASSIGN_MMIODEV,
    ACRN_IOCTL_DEASSIGN_MMIODEV,
    ACRN_IOCTL_ASSIGN_PCIDEV,
    ACRN_IOCTL_DEASSIGN_PCIDEV,
    ACRN_IOCTL_CREATE_VDEV,
    ACRN_IOCTL_DESTROY_VDEV,
    ACRN_IOCTL_SET_PTDEV_INTR,
    ACRN_IOCTL_RESET_PTDEV_INTR,
    ACRN_IOCTL_SET_IRQLINE,
    ACRN_IOCTL_INJECT_MSI,
    ACRN_IOCTL_VM_INTR_MONITOR,
    ACRN_IOCTL_CREATE_IOREQ_CLIENT,
    ACRN_IOCTL_DESTROY_IOREQ_CLIENT,
    ACRN_IOCTL_ATTACH_IOREQ_CLIENT,
    ACRN_IOCTL_NOTIFY_REQUEST_FINISH,
    ACRN_IOCTL_CLEAR_VM_IOREQ,
    ACRN_IOCTL_PM_GET_CPU_STATE,
    ACRN_IOCTL_IOEVENTFD,
    ACRN_IOCTL_IRQFD
};

struct acrn_dev {
    struct device *this_device;
} acrn_dev;

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-1000))
#define PTR_ERR(x) ((long)(x))
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))
#define unlikely(x) (x)

static inline void *memdup_user(const void *src, size_t len) { return NULL; }
static inline int hcall_start_vm(unsigned int vmid) { return 0; }
static inline int hcall_pause_vm(unsigned int vmid) { return 0; }
static inline int hcall_reset_vm(unsigned int vmid) { return 0; }
static inline int acrn_vm_destroy(struct acrn_vm *vm) { return 0; }
static inline int hcall_set_vcpu_regs(unsigned int vmid, uintptr_t phys_regs) { return 0; }
static inline int acrn_vm_memseg_map(struct acrn_vm *vm, struct acrn_vm_memmap *memmap) { return 0; }
static inline int acrn_vm_memseg_unmap(struct acrn_vm *vm, struct acrn_vm_memmap *memmap) { return 0; }
static inline int hcall_assign_mmiodev(unsigned int vmid, uintptr_t phys_mmiodev) { return 0; }
static inline int hcall_deassign_mmiodev(unsigned int vmid, uintptr_t phys_mmiodev) { return 0; }
static inline int hcall_assign_pcidev(unsigned int vmid, uintptr_t phys_pcidev) { return 0; }
static inline int hcall_deassign_pcidev(unsigned int vmid, uintptr_t phys_pcidev) { return 0; }
static inline int hcall_create_vdev(unsigned int vmid, uintptr_t phys_vdev) { return 0; }
static inline int hcall_destroy_vdev(unsigned int vmid, uintptr_t phys_vdev) { return 0; }
static inline int hcall_set_ptdev_intr(unsigned int vmid, uintptr_t phys_irq_info) { return 0; }
static inline int hcall_reset_ptdev_intr(unsigned int vmid, uintptr_t phys_irq_info) { return 0; }
static inline int hcall_set_irqline(unsigned int vmid, unsigned long ioctl_param) { return 0; }
static inline int hcall_inject_msi(unsigned int vmid, uintptr_t phys_msi) { return 0; }
static inline int hcall_vm_intr_monitor(unsigned int vmid, uintptr_t phys_page) { return 0; }
static inline bool acrn_ioreq_client_create(struct acrn_vm *vm, void *arg1, void *arg2, bool arg3, const char *arg4) { return false; }
static inline void acrn_ioreq_client_destroy(void *client) {}
static inline int acrn_ioreq_client_wait(void *client) { return 0; }
static inline int acrn_ioreq_request_default_complete(struct acrn_vm *vm, unsigned int vcpu) { return 0; }
static inline void acrn_ioreq_request_clear(struct acrn_vm *vm) {}
static inline int pmcmd_ioctl(uint64_t cmd, void *param) { return 0; }
static inline int acrn_ioeventfd_config(struct acrn_vm *vm, struct acrn_ioeventfd *ioeventfd) { return 0; }
static inline int acrn_irqfd_config(struct acrn_vm *vm, struct acrn_irqfd *irqfd) { return 0; }
static inline struct acrn_vm *acrn_vm_create(struct acrn_vm *vm, struct acrn_vm_creation *vm_param) { return NULL; }
static inline void kfree(void *p) {}
static inline int copy_to_user(void *dst, const void *src, size_t size) { return 0; }
static inline int copy_from_user(void *dst, const void *src, size_t size) { return 0; }
static inline int pin_user_pages_fast(unsigned long addr, int nr_pages, unsigned int gup_flags, struct page **pages) { return 0; }
static inline void unpin_user_page(struct page *page) {}
static inline uintptr_t virt_to_phys(void *x) { return (uintptr_t)x; }
static inline uintptr_t page_to_phys(struct page *page) { return 0; }
static inline void dev_dbg(struct device *dev, const char *fmt, ...) {}
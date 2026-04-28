#include <stdint.h>
#include <string.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;
typedef uintptr_t dma_addr_t;

#define __user
#define KERN_DEBUG
#define dprintk(x)
#define CAP_SYS_ADMIN 1
#define GFP_KERNEL 0
#define __GFP_DMA 0
#define GFP_DMA 0
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
#define cpu_to_le32(x) (x)
#define le32_to_cpu(x) (x)

#define SRBF_ExecuteScsi 0
#define SRB_DataIn 1
#define SRB_DataOut 2
#define DMA_TO_DEVICE 1
#define DMA_BIDIRECTIONAL 2
#define DMA_FROM_DEVICE 3
#define DMA_NONE 0
#define AAC_OPT_SGMAP_HOST64 1
#define AAC_OPT_NEW_COMM 2
#define FsaNormal 0
#define ScsiPortCommand 0
#define ScsiPortCommand64 0
#define FastResponseCapable 0
#define EBUSY 1
#define EPERM 1
#define ENOMEM 1
#define EFAULT 1
#define EINVAL 1
#define ENXIO 1
#define ERESTARTSYS 1

struct aac_dev {
    int in_reset;
    u32 max_fib_size;
    struct {
        u32 options;
    } adapter_info;
    struct {
        unsigned long max_sectors;
    } *scsi_host_ptr;
    struct {
    } *pdev;
};

struct fib {
    struct {
        struct aac_fibhdr *hw_fib_va;
    };
};

struct aac_fibhdr {
    struct {
        u32 XferState;
    } header;
};

struct user_sgentry {
    u32 count;
    u32 addr;
};

struct sgentry {
    u32 count;
    u32 addr;
};

struct user_sgmap {
    u32 count;
    struct user_sgentry sg[0];
};

struct sgmap {
    u32 count;
    struct sgentry sg[0];
};

struct user_sgentry64 {
    u32 count;
    u32 addr[2];
};

struct sgentry64 {
    u32 count;
    u32 addr[2];
};

struct user_sgmap64 {
    u32 count;
    struct user_sgentry64 sg[0];
};

struct sgmap64 {
    u32 count;
    struct sgentry64 sg[0];
};

struct aac_srb {
    u32 function;
    u32 channel;
    u32 id;
    u32 lun;
    u32 timeout;
    u32 flags;
    u32 retry_limit;
    u32 cdb_size;
    u8 cdb[16];
    u32 count;
    union {
        struct sgmap sg;
        struct sgmap64 sg64;
    };
};

struct user_aac_srb {
    u32 function;
    u32 channel;
    u32 id;
    u32 lun;
    u32 timeout;
    u32 flags;
    u32 retry_limit;
    u32 cdb_size;
    u8 cdb[16];
    u32 count;
    union {
        struct user_sgmap sg;
        struct user_sgmap64 sg64;
    };
};

struct aac_srb_reply {
    u32 status;
};

static int copy_from_user(void *to, const void __user *from, unsigned long n) { return 0; }
static int copy_to_user(void __user *to, const void *from, unsigned long n) { return 0; }
static void *kmalloc(size_t size, int flags) { return NULL; }
static void kfree(const void *objp) {}
static dma_addr_t pci_map_single(void *pdev, void *ptr, size_t size, int dir) { return 0; }
static int capable(int cap) { return 1; }

static void *aac_fib_alloc(struct aac_dev *dev) { return NULL; }
static void aac_fib_init(struct fib *fib) {}
static void *fib_data(struct fib *fib) { return NULL; }
static int aac_fib_send(int cmd, struct fib *fib, u32 size, int type, int priority, int wait, void *callback, void *callback_data) { return 0; }
static void aac_fib_complete(struct fib *fib) {}
static void aac_fib_free(struct fib *fib) {}
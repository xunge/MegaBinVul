#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define VIDEO_MAX_FRAME 32
#define PAGE_SHIFT 12
#define VM_WRITE 0x2
#define VM_SHARED 0x8
#define VM_DONTEXPAND 0x4000
#define VM_RESERVED 0x8000
#define EINVAL 22
#define ENOMEM 12
#define GFP_KERNEL 0
#define V4L2_MEMORY_MMAP 1
#define MAGIC_VMAL_MEM 0

struct vm_area_struct;

struct vm_operations_struct {
    void (*open)(struct vm_area_struct *vma);
};

struct videbuf_vmalloc_memory {
    unsigned int magic;
    void *vmalloc;
    struct vm_area_struct *vma;
};

struct videobuf_mapping {
    unsigned long start;
    unsigned long end;
    struct videobuf_queue *q;
};

struct videobuf_buffer {
    unsigned int memory;
    unsigned long boff;
    struct videobuf_mapping *map;
    unsigned long baddr;
    unsigned long bsize;
    struct videbuf_vmalloc_memory *priv;
};

struct videobuf_queue {
    struct videobuf_buffer *bufs[VIDEO_MAX_FRAME];
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_pgoff;
    unsigned long vm_flags;
    const struct vm_operations_struct *vm_ops;
    void *vm_private_data;
};

static const struct vm_operations_struct videobuf_vm_ops = {0};
static void videobuf_vm_open(struct vm_area_struct *vma) {}

#define MAGIC_CHECK(x,y) 
#define BUG_ON(x) 
#define dprintk(level, fmt, ...) 

static void *kmalloc(size_t size, int flags) { return malloc(size); }
static void kfree(void *ptr) { free(ptr); }
static int remap_vmalloc_range(struct vm_area_struct *vma, void *addr, unsigned long pgoff) { return 0; }

typedef struct videbuf_vmalloc_memory videobuf_vmalloc_memory;
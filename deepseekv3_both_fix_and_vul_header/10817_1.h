#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define PAGE_SHIFT 12
#define CONFIG_SWAP 1
#define EBADF 9

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_pgoff;
    struct file *vm_file;
};

struct file {
    struct inode *f_inode;
    void *f_mapping;
};

struct inode;

int force_swapin_readahead(struct vm_area_struct *vma, unsigned long start, unsigned long end);
int force_shm_swapin_readahead(struct vm_area_struct *vma, unsigned long start, unsigned long end, void *mapping);
int force_page_cache_readahead(void *mapping, struct file *file, unsigned long start, unsigned long count);
int shmem_mapping(void *mapping);
struct inode *file_inode(struct file *file);
#define IS_DAX(inode) 0
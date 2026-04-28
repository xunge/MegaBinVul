#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>

#define MAP_ANONYMOUS 0x20
#define MAP_HUGETLB 0x40000
#define MAP_EXECUTABLE 0x1000
#define MAP_DENYWRITE 0x800
#define MAP_HUGE_SHIFT 26
#define MAP_HUGE_MASK 0x3f

#define HUGETLB_ANON_FILE 1
#define HUGETLB_ANONHUGE_INODE 2
#define VM_NORESERVE 0x40

#define EBADF 9
#define EINVAL 22

struct file;
struct user_struct;
struct hstate;

unsigned long untagged_addr(unsigned long addr);
struct file *fget(unsigned int fd);
int is_file_hugepages(struct file *file);
unsigned long huge_page_size(struct hstate *hs);
struct hstate *hstate_sizelog(int size);
struct file *hugetlb_file_setup(int type, unsigned long len, int flags, struct user_struct **user, int inode, int mask);
int IS_ERR(const void *ptr);
long PTR_ERR(const void *ptr);
void fput(struct file *file);
void audit_mmap_fd(unsigned long fd, unsigned long flags);
unsigned long vm_mmap_pgoff(struct file *file, unsigned long addr, unsigned long len, unsigned long prot, unsigned long flags, unsigned long pgoff);
unsigned long ALIGN(unsigned long x, unsigned long align);
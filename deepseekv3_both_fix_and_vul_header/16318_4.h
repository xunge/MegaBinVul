#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
#define __user

#define PAGE_SIZE 4096
#define EINVAL 22
#define EFAULT 14
#define FOLL_WRITE 0x01
#define FUT_OFF_MMSHARED (1UL << 30)
#define FUT_OFF_INODE (1UL << 31)

enum futex_access {
    FUTEX_READ,
    FUTEX_WRITE
};

struct mm_struct {
    void *mm;
};

struct page {
    void *mapping;
};

struct address_space {
    void *host;
};

struct inode {
    int i_count;
    void *i_mapping;
    unsigned long i_seq;
};

union futex_key {
    struct {
        unsigned long pgoff;
        struct inode *inode;
        unsigned long i_seq;
        int offset;
    } shared;
    struct {
        unsigned long address;
        struct mm_struct *mm;
        int offset;
    } private;
    struct {
        unsigned long word;
        void *ptr;
        int offset;
    } both;
};

struct mm_struct *current;

#define READ_ONCE(x) (x)
#define unlikely(x) (x)
#define WARN_ON_ONCE(x) (0)
#define PageSwapCache(x) (0)
#define PageAnon(x) (0)

void rcu_read_lock() {}
void rcu_read_unlock() {}

extern int get_user_pages_fast(unsigned long start, int nr_pages, int write, struct page **pages);
extern void put_page(struct page *page);
extern void lock_page(struct page *page);
extern void unlock_page(struct page *page);
extern struct page *compound_head(struct page *page);
extern int should_fail_futex(int fshared);
extern void get_futex_key_refs(union futex_key *key);
extern unsigned long basepage_index(struct page *page);
extern int access_ok(const void *addr, unsigned long size);
extern int atomic_inc_not_zero(int *v);
extern void iput(struct inode *inode);
extern unsigned long get_inode_sequence_number(struct inode *inode);
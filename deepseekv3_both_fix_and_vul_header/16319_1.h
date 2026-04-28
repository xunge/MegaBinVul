#include <stddef.h>

#define CONFIG_MMU 1
#define FUT_OFF_INODE 1
#define FUT_OFF_MMSHARED 2

struct inode;
struct mm_struct;

union futex_key {
    struct {
        unsigned long offset;
        void *ptr;
    } both;
    struct {
        struct inode *inode;
    } shared;
    struct {
        struct mm_struct *mm;
    } private;
};

#define WARN_ON_ONCE(cond) ((void)0)
#define IS_ENABLED(option) (1)

void iput(struct inode *inode);
void mmdrop(struct mm_struct *mm);
#include <stdint.h>

#define CONFIG_MMU 1
#define FUT_OFF_INODE 1
#define FUT_OFF_MMSHARED 2

typedef struct inode inode;
typedef struct mm_struct mm_struct;

union futex_key {
    struct {
        unsigned long pgoff;
        struct inode *inode;
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

void smp_mb(void);
void ihold(struct inode *inode);
void futex_get_mm(union futex_key *key);
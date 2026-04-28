#include <stdint.h>
#include <stddef.h>

struct svm_range {
    uint32_t actual_loc;
};

struct mm_struct;

#define pr_debug(fmt, ...)
#define EDEADLK 11

// 提供两个版本的函数声明
extern int svm_migrate_vram_to_ram_3args(struct svm_range *prange, struct mm_struct *mm, uint32_t trigger);
extern int svm_migrate_vram_to_ram_4args(struct svm_range *prange, struct mm_struct *mm, uint32_t trigger, void *arg);
extern int svm_migrate_ram_to_vram(struct svm_range *prange, uint32_t best_loc, struct mm_struct *mm, uint32_t trigger);
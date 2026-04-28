#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define SEC_FTR_FLUSH_COUNT_CACHE 0
#define SEC_FTR_FLUSH_LINK_STACK 0
#define SEC_FTR_BCCTR_FLUSH_ASSIST 0

#define PPC_INST_NOP 0
#define PPC_INST_BLR 0
#define BRANCH_SET_LINK 0

typedef uint64_t u64;

enum {
    COUNT_CACHE_FLUSH_NONE,
    COUNT_CACHE_FLUSH_SW,
    COUNT_CACHE_FLUSH_HW
};

extern bool security_ftr_enabled(unsigned long feature);
extern void patch_instruction_site(void *site, unsigned int instr);
extern void patch_branch_site(void *site, u64 target, unsigned int flags);
extern void no_count_cache_flush(void);
extern void flush_count_cache(void);

extern bool link_stack_flush_enabled;
extern int count_cache_flush_type;
extern void *patch__call_flush_count_cache;
extern void *patch__flush_link_stack_return;
extern void *patch__flush_count_cache_return;

#define pr_info(fmt, ...) printf(fmt, ##__VA_ARGS__)
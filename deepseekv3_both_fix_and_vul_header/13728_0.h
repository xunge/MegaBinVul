#include <stdbool.h>

extern bool no_spectrev2;
extern int security_ftr_enabled(unsigned long);
extern void security_ftr_set(unsigned long);
extern void pr_warn(const char *);
extern bool cpu_mitigations_off(void);
extern void toggle_count_cache_flush(bool);

#define SEC_FTR_BCCTRL_SERIALISED 0
#define SEC_FTR_COUNT_CACHE_DISABLED 0
#define SEC_FTR_FLUSH_COUNT_CACHE 0
#define SEC_FTR_FLUSH_LINK_STACK 0
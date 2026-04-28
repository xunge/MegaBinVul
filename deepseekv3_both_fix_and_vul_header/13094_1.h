#include <stdbool.h>
#include <stddef.h>

struct domain {
    bool is_dying;
    bool is_shutting_down;
    unsigned int shutdown_code;
};

#define unlikely(x) (x)
#define SHF_L1_ANY 0
#define SHF_FL1_ANY 0
#define SHUTDOWN_crash 0

unsigned int shadow_size(unsigned int type);
bool paging_mode_log_dirty(struct domain *d);
unsigned int paging_logdirty_levels();
bool _shadow_prealloc(struct domain *d, unsigned int count);
void domain_crash(struct domain *d);
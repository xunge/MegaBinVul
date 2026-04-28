#include <stdbool.h>

struct domain {
    struct {
        struct {
            struct {
                struct {
                    int (*enable)(struct domain *, bool);
                } *ops;
            } log_dirty;
        } paging;
    } arch;
};

int has_arch_pdevs(struct domain *d);
bool paging_mode_log_dirty(struct domain *d);
void domain_pause(struct domain *d);
void domain_unpause(struct domain *d);

#define EINVAL 22
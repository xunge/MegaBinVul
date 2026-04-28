#include <stdint.h>

#define GNTPIN_hstw_mask (1U << 0)
#define GNTPIN_devw_mask (1U << 1)
#define GNTPIN_hstr_mask (1U << 2)

#define _GTF_writing (1U << 0)
#define _GTF_reading (1U << 1)

struct active_grant_entry {
    uint32_t pin;
};

static inline void gnttab_clear_flag(uint16_t flag, uint16_t *status) {
    *status &= ~flag;
}
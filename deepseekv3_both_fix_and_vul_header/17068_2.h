#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#define NFPROTO_BRIDGE 7
#define pr_debug(fmt, ...) 

struct ebt_entry {
    unsigned int bitmask;
    unsigned int watchers_offset;
    unsigned int target_offset;
    unsigned int next_offset;
};

struct ebt_entries {
    unsigned int policy;
};

struct ebt_entries_buf_state {
    unsigned int buf_user_offset;
    char *buf_kern_start;
    unsigned int buf_kern_offset;
};

struct compat_ebt_entry_mwt {
    // placeholder structure
};

static int ebt_buf_add(struct ebt_entries_buf_state *state, const void *data, unsigned int len) { return 0; }
static int ebt_size_mwt(struct compat_ebt_entry_mwt *match32, unsigned int size, int i, struct ebt_entries_buf_state *state, const unsigned char *base) { return 0; }
static int xt_compat_add_offset(uint8_t pf, unsigned int offset, unsigned int delta) { return 0; }

#define WARN_ON(condition) ((condition) ? 1 : 0)
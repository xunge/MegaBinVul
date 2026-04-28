#include <stddef.h>

#define EINVAL 22
#define WARN_ON(condition) (condition)

struct compat_ebt_entry_mwt {
    unsigned int match_size;
};

struct ebt_entries_buf_state {
    char *buf_kern_start;
    unsigned int buf_kern_offset;
};

struct ebt_entry_match {
    unsigned int match_size;
};

enum compat_mwt {
    EBT_COMPAT_TARGET
};

extern int ebt_buf_add(struct ebt_entries_buf_state *state, const void *data, unsigned int len);
extern int ebt_buf_add_pad(struct ebt_entries_buf_state *state, unsigned int len);
extern unsigned int ebt_compat_entry_padsize(void);
extern int compat_mtw_from_user(struct compat_ebt_entry_mwt *match32, enum compat_mwt type, struct ebt_entries_buf_state *state, const void *base);
#include <stdbool.h>

enum {
    SPECTRE_V2_IBRS_ENHANCED,
    SPECTRE_V2_USER_NONE,
    SPECTRE_V2_USER_STRICT,
    SPECTRE_V2_USER_STRICT_PREFERRED,
    SPECTRE_V2_USER_PRCTL,
    SPECTRE_V2_USER_SECCOMP
};

extern int spectre_v2_enabled;
extern int spectre_v2_user;
extern int spectre_v2_user_stibp;

struct static_key {
    bool enabled;
};

extern struct static_key switch_to_cond_stibp;

static inline bool static_key_enabled(struct static_key *key)
{
    return key->enabled;
}
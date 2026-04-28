#include <stdbool.h>

enum spectre_v2_user_mitigation {
    SPECTRE_V2_USER_NONE,
    SPECTRE_V2_USER_STRICT,
    SPECTRE_V2_USER_STRICT_PREFERRED,
    SPECTRE_V2_USER_PRCTL,
    SPECTRE_V2_USER_SECCOMP
};

extern bool spectre_v2_in_ibrs_mode(bool);
extern bool spectre_v2_enabled;
extern enum spectre_v2_user_mitigation spectre_v2_user_stibp;
extern struct static_key_false switch_to_cond_stibp;

struct static_key_false {
    bool enabled;
};

static inline bool static_key_enabled(const struct static_key_false *key)
{
    return key->enabled;
}
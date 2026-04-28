#include <stddef.h>

#define R_API

typedef struct ht_pp_t HTpp;
typedef struct r_cmd_alias_val_t RCmdAliasVal;

typedef struct r_cmd_t {
    HTpp *aliases;
} RCmd;

#define r_return_val_if_fail(cond, val) if (!(cond)) return (val)

RCmdAliasVal *ht_pp_find(HTpp *ht, const char *k, void *user);
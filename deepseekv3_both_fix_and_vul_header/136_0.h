#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct conn conn;
typedef struct token_t {
    char *value;
} token_t;

typedef struct settings_t {
    uint32_t hot_lru_pct;
    uint32_t warm_lru_pct;
    double hot_max_factor;
    double warm_max_factor;
    bool lru_maintainer_thread;
    bool lru_segmented;
    bool temp_lru;
    int32_t temporary_ttl;
} settings_t;

extern settings_t settings;

int safe_strtoul(const char *str, uint32_t *out);
int safe_strtod(const char *str, double *out);
int safe_strtol(const char *str, int32_t *out);
void out_string(conn *c, const char *str);
void set_noreply_maybe(conn *c, token_t *tokens, const size_t ntokens);
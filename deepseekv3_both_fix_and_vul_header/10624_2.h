#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define R_API
typedef unsigned long long ut64;

typedef struct RConfigNode {
    char *name;
    char *value;
    ut64 i_value;
    int flags;
    bool (*setter)(void *user, struct RConfigNode *node);
} RConfigNode;

typedef struct RConfig {
    void *user;
    void *num;
    void *ht;
    void *nodes;
    int n_nodes;
    bool lock;
} RConfig;

#define STRNULL(x) (!(x) || !*(x))
#define CN_RO 1
#define CN_BOOL 2
#define CN_INT 4
#define UT64_MAX ULLONG_MAX
#define IS_DIGIT(x) ((x) >= '0' && (x) <= '9')

bool is_true(const char *value);
bool is_bool(const char *value);
const char *r_str_bool(bool b);
ut64 r_num_get(void *num, const char *value);
ut64 r_num_math(void *num, const char *value);
RConfigNode *r_config_node_get(RConfig *cfg, const char *name);
RConfigNode *r_config_node_new(const char *name, const char *value);
int ht_insert(void *ht, const char *key, void *value);
void r_list_append(void *list, void *item);
void eprintf(const char *format, ...);
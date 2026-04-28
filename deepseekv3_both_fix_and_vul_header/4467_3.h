#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_OPT_ARGS 1
#define ENOMEM 12
#define EINVAL 22

enum {
    OPT_UPPERDIR,
    OPT_LOWERDIR,
    OPT_WORKDIR,
    OPT_DEFAULT_PERMISSIONS,
};

struct ovl_config {
    char *upperdir;
    char *lowerdir;
    char *workdir;
    bool default_permissions;
};

typedef struct {
    char *start;
    char *end;
} substring_t;

typedef struct {
    int token;
    const char *pattern;
} match_entry_t;

match_entry_t ovl_tokens[] = {
    {OPT_UPPERDIR, "upperdir=%s"},
    {OPT_LOWERDIR, "lowerdir=%s"},
    {OPT_WORKDIR, "workdir=%s"},
    {OPT_DEFAULT_PERMISSIONS, "default_permissions"},
    {0, NULL},
};

extern char *ovl_next_opt(char **s);
extern int match_token(char *p, match_entry_t *table, substring_t *args);
extern char *match_strdup(substring_t *arg);
extern void kfree(void *ptr);
extern void pr_err(const char *fmt, ...);
extern void pr_info(const char *fmt, ...);
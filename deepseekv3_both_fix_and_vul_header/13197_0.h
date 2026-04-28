#include <assert.h>
#include <string.h>

typedef int LY_ERR;
#define LY_SUCCESS 0
#define LY_EEXIST 1
#define LY_EDENIED 2
#define LY_ERECOMPILE 3

struct lys_module {
    int implemented;
    void *ctx;
    const char *name;
    const char *revision;
    void *parsed;
    int to_compile;
};

struct lys_glob_unres {
    struct {
        int (*add)(void *, void *, int, void *);
    } implementing;
};

#define LOGVRB(...)
#define LOGERR(...)
#define LY_CHECK_RET(x) do { if (x) return x; } while (0)

int ly_ctx_get_module_implemented(void *ctx, const char *name);
int lys_set_features(void *parsed, const char **features);
int lys_precompile_augments_deviations(struct lys_module *mod, struct lys_glob_unres *unres);
int lys_has_compiled_import_r(struct lys_module *mod);
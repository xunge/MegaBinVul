#include <stdlib.h>

struct lys_restr {
    void *ext;
    unsigned int ext_size;
    char *expr;
    char *dsc;
    char *ref;
    char *eapptag;
    char *emsg;
};

struct lys_module {
    void *ctx;
};

struct unres_schema;

#define UNRES_EXT 0
#define LYEXT_PAR_RESTR 0

#define LY_CHECK_ERR_RETURN(cond, action, retval) \
    do { \
        if (cond) { \
            action; \
            return retval; \
        } \
    } while(0)

#define LOGMEM(ctx)

int unres_schema_find(struct unres_schema *unres, int index, void *item, int type);
void lys_ext_dup(void *ctx, struct lys_module *mod, void *ext, int ext_size, void *parent, int type, void **new_ext, int shallow, struct unres_schema *unres);
char *lydict_insert(void *ctx, const char *value, int len);
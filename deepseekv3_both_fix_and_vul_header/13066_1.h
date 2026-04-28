#include <assert.h>
#include <stdlib.h>

typedef struct tcpeditdlt_s {
    void *tcpedit;
    struct {
        void *config;
    } *encoder;
} tcpeditdlt_t;

typedef struct tcpeditdlt_plugin_s {
    char *name;
    void *config;
    size_t config_size;
} tcpeditdlt_plugin_t;

typedef struct jnpr_ether_config_s {
    tcpeditdlt_t *subctx;
} jnpr_ether_config_t;

#define TCPEDIT_OK 0
#define TCPEDIT_ERROR -1

extern tcpeditdlt_plugin_t *tcpedit_dlt_getplugin(tcpeditdlt_t *ctx, int dlt_value);
extern void tcpedit_seterr(void *tcpedit, const char *format, ...);
extern void safe_free(void *ptr);
extern void tcpedit_dlt_cleanup(tcpeditdlt_t *subctx);

extern int dlt_value;
extern const char *dlt_name;
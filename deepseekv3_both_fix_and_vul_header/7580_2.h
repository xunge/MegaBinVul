#include <assert.h>
#include <stdlib.h>

typedef struct tcpeditdlt {
    void *tcpedit;
    struct encoder *encoder;
} tcpeditdlt_t;

typedef struct tcpeditdlt_plugin {
    char *name;
    void *config;
    size_t config_size;
} tcpeditdlt_plugin_t;

typedef struct jnpr_ether_config {
    void *subctx;
} jnpr_ether_config_t;

typedef struct encoder {
    void *config;
} encoder_t;

#define TCPEDIT_OK 0
#define TCPEDIT_ERROR -1

extern int dlt_value;
extern char *dlt_name;
extern void *safe_free(void *ptr);
extern tcpeditdlt_plugin_t *tcpedit_dlt_getplugin(tcpeditdlt_t *ctx, int dlt_value);
extern void tcpedit_seterr(void *tcpedit, const char *msg, ...);
extern void tcpedit_dlt_cleanup(void *subctx);
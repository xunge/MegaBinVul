#include <stdint.h>
#include <stddef.h>

struct tcpeditdlt_s {
    struct {
        int dlt;
    } *decoder;
    struct {
        void *config;
    } *encoder;
    void *tcpedit;
};

typedef struct tcpeditdlt_s tcpeditdlt_t;
typedef struct jnpr_ether_config_s {
    void *subctx;
} jnpr_ether_config_t;

extern int dlt_value;
extern void *tcpedit_dlt_init(void *tcpedit, int dlt_type);
#define TCPEDIT_OK 0
#define DLT_EN10MB 1
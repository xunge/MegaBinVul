#include <string.h>

#define OIDC_DEFAULT_HEADER_PREFIX "OIDC_"

typedef struct server_rec {
    void *module_config;
} server_rec;

typedef struct request_rec {
    struct server_rec *server;
} request_rec;

typedef struct oidc_cfg {
    int scrub_request_headers;
    char *claim_prefix;
} oidc_cfg;

typedef struct module_struct module;
extern module auth_openidc_module;

void oidc_scrub_request_headers(request_rec *r, const char *prefix, const char *except);
const char *oidc_cfg_dir_authn_header(request_rec *r);
oidc_cfg* ap_get_module_config(void*, module*);
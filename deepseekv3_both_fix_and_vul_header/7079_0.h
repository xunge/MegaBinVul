#include <stdbool.h>
#include <string.h>
#include <errno.h>

struct sss_certmap_ctx;
struct parsed_template {
    char *name;
    char *conversion;
};
struct sss_cert_content {
    void *issuer_rdn_list;
    void *subject_rdn_list;
    void *san_list;
};

#define CM_DEBUG(ctx, fmt, ...) 
#define EINVAL 22
#define ENOMEM 12
#define EOK 0

void *talloc_free(void *ptr);

int rdn_list_2_dn_str(struct sss_certmap_ctx *ctx, char *conversion, void *rdn_list, char **out);
int expand_san(struct sss_certmap_ctx *ctx, struct parsed_template *parsed_template, void *san_list, char **out);
int expand_cert(struct sss_certmap_ctx *ctx, struct parsed_template *parsed_template, struct sss_cert_content *cert_content, char **out);
int sss_filter_sanitize(struct sss_certmap_ctx *ctx, char *input, char **output);
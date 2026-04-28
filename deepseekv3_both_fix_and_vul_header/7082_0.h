#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef void TALLOC_CTX;

struct cert_auth_info;
struct sss_certmap_ctx;

#define SSSDBG_OP_FAILURE 0
#define DEBUG(level, message)

int sss_certmap_init(TALLOC_CTX *mem_ctx, void *arg1, void *arg2, struct sss_certmap_ctx **ctx);
int sss_certmap_add_rule(struct sss_certmap_ctx *ctx, int priority, const char *match_rule, const char *map_rule, void *arg);
unsigned char *sss_base64_decode(TALLOC_CTX *mem_ctx, const char *input, size_t *output_size);
const char *sss_cai_get_cert(struct cert_auth_info *cert_info);
int sss_certmap_get_search_filter(struct sss_certmap_ctx *ctx, unsigned char *der, size_t der_size, char **filter, char ***domains);
const char *sss_cai_get_label(struct cert_auth_info *cert_info);
void sss_certmap_free_filter_and_domains(char *filter, char **domains);
void sss_certmap_free_ctx(struct sss_certmap_ctx *ctx);
void talloc_free(void *ptr);
char *talloc_asprintf(TALLOC_CTX *mem_ctx, const char *fmt, ...);
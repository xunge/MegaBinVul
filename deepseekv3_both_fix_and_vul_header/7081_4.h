#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <stddef.h>

struct sss_certmap_ctx {
    struct priority_list *prio_list;
    void *default_mapping_rule;
};

struct priority_list {
    struct priority_list *next;
    struct match_map_rule *rule_list;
};

struct match_map_rule {
    struct match_map_rule *next;
    void *parsed_match_rule;
    void *parsed_mapping_rule;
    char **domains;
};

struct sss_cert_content;

extern int expand_mapping_rule_ex(struct sss_certmap_ctx *ctx,
                                const uint8_t *der_cert, size_t der_size,
                                bool flag, char **_filter, char ***_domains);
extern int sss_cert_get_content(struct sss_certmap_ctx *ctx,
                               const uint8_t *der_cert, size_t der_size,
                               struct sss_cert_content **cert_content);
extern int do_match(struct sss_certmap_ctx *ctx, void *parsed_match_rule,
                   struct sss_cert_content *cert_content);
extern int get_filter(struct sss_certmap_ctx *ctx, void *parsed_mapping_rule,
                     struct sss_cert_content *cert_content, char **filter);
extern void *talloc_zero_array(void *ctx, const char *type, size_t count);
extern char *talloc_strdup(void *ctx, const char *str);
extern void talloc_free(void *ptr);

#define CM_DEBUG(ctx, fmt, ...)

#define talloc_zero_array(ctx, type, count) talloc_zero_array(ctx, #type, count)
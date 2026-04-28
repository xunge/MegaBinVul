#include <stdbool.h>
#include <errno.h>
#include <stddef.h>

struct sss_certmap_ctx;
struct ldap_mapping_rule;
struct sss_cert_content;
struct ldap_mapping_rule_comp;

enum component_type {
    comp_string,
    comp_template
};

struct ldap_mapping_rule_comp {
    enum component_type type;
    char *val;
    void *parsed_template;
    struct ldap_mapping_rule_comp *next;
};

struct ldap_mapping_rule {
    struct ldap_mapping_rule_comp *list;
};

extern void *talloc_strdup(void *ctx, const char *str);
extern void *talloc_strdup_append(void *ctx, const char *str);
extern void talloc_free(void *ptr);
extern int expand_template(struct sss_certmap_ctx *ctx, void *parsed_template,
                          struct sss_cert_content *cert_content, ...);
extern void CM_DEBUG(struct sss_certmap_ctx *ctx, const char *msg);
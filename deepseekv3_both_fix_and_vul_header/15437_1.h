#include <stdlib.h>
#include <string.h>

struct mansession;
struct message;

struct ast_config;
struct ast_category;
struct ast_variable {
    char *name;
    char *value;
    struct ast_variable *next;
};
struct ast_str;
struct ast_flags {
    unsigned int flags;
};

#define CONFIG_FLAG_WITHCOMMENTS (1 << 0)
#define CONFIG_FLAG_NOCACHE (1 << 1)

#define CONFIG_STATUS_FILEMISSING ((struct ast_config *)0x1)
#define CONFIG_STATUS_FILEINVALID ((struct ast_config *)0x2)

extern int ast_strlen_zero(const char *s);
extern int restrictedFile(const char *fn);
extern struct ast_config *ast_config_load2(const char *fn, const char *name, struct ast_flags flags);
extern void ast_config_destroy(struct ast_config *cfg);
extern const char *astman_get_header(const struct message *m, const char *header);
extern void astman_send_error(struct mansession *s, const struct message *m, const char *error);
extern void astman_start_ack(struct mansession *s, const struct message *m);
extern void astman_append(struct mansession *s, const char *fmt, ...);
extern struct ast_category *ast_category_browse_filtered(struct ast_config *cfg, const char *category, struct ast_category *cur_category, const char *filter);
extern const char *ast_category_get_name(struct ast_category *cat);
extern int ast_category_is_template(struct ast_category *cat);
extern struct ast_str *ast_category_get_templates(struct ast_category *cat);
extern size_t ast_str_strlen(const struct ast_str *s);
extern char *ast_str_buffer(const struct ast_str *s);
extern void ast_free(void *ptr);
extern struct ast_variable *ast_category_first(struct ast_category *cat);
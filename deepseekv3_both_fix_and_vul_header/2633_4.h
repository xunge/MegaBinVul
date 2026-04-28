#include <stdint.h>
#include <string.h>

typedef struct cmd_parms {
    struct {
        struct {
            void *cmd_data;
            const char *name;
        } *cmd;
        int64_t limited;
        void *temp_pool;
        void *pool;
        struct {
            void *first_child;
        } *directive;
        void *context;
    };
} cmd_parms;

#define AP_CORE_DECLARE_NONSTD(ret) ret
#define AP_METHOD_BIT (1)
#define M_TRACE 0
#define M_INVALID -1

typedef int64_t apr_int64_t;

const char *unclosed_directive(cmd_parms *cmd);
const char *missing_container_arg(cmd_parms *cmd);
const char *ap_strrchr_c(const char *s, char c);
char *apr_pstrmemdup(void *pool, const char *s, size_t n);
char *ap_getword_conf(void *pool, const char **line);
int ap_method_number_of(const char *method);
int ap_method_register(void *pool, const char *method);
char *apr_pstrdup(void *pool, const char *s);
char *apr_pstrcat(void *pool, ...);
const char *ap_walk_config(void *node, cmd_parms *parms, void *context);
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RAII_VAR(type, name, init, destroy) \
    __attribute__((cleanup(destroy))) type name = (init)

extern int live_dangerously;
extern const char *ast_config_AST_CONFIG_DIR;

void ast_free(void *ptr);
char *ast_strip(char *str);
char *ast_strdupa(const char *s);
int ast_asprintf(char **strp, const char *fmt, ...);
int ast_begins_with(const char *str, const char *prefix);
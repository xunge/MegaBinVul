#include <string.h>
#include <strings.h>

#define HASH_ENABLED 1
#define HASH_DISABLED 0

typedef struct directory_config directory_config;
typedef struct cmd_parms cmd_parms;

struct directory_config {
    int hash_is_enabled;
    int hash_enforcement;
};

struct cmd_parms {
    void *pool;
};

char *apr_psprintf(void *pool, const char *fmt, ...);
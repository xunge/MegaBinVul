#include <stdlib.h>
#include <string.h>

#define R_API

typedef struct RCore RCore;
typedef struct RConfig RConfig;

struct RCore {
    RConfig *config;
};

#define R_ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

static const char *fortunes[] = {NULL};  // 初始化为空数组

extern RConfig *r_config_get(RConfig *config, const char *key);
extern char *getFortuneFile(RCore *core, const char *fortune);
extern char *r_file_slurp(const char *file, int *sz);
extern void r_cons_printf(const char *fmt, ...);
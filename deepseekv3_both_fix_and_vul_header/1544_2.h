#include <string.h>
#include <strings.h>

#define WEBOBJECTS "webobjects"
#define WO_DBG 0
#define WO_ERR 1
#define WOURLOK 0
#define WOURLInvalidApplicationName 1
#define DECLINED -1
#define OK 0

typedef struct request_rec {
    char *uri;
    char *handler;
    char *filename;
    struct {
        void *module_config;
    } *server;
    void *pool;
} request_rec;

typedef struct {
    const char *WebObjects_alias;
} WebObjects_config;

typedef struct {
    int dummy;  // placeholder for WOURLComponents members
} WOURLComponents;

typedef int WOURLError;

struct module {
    int dummy;  // placeholder for module members
};
extern struct module WebObjects_module;
extern int adaptorEnabled;

int WOLog(int level, const char *format, ...);
int WOParseApplicationName(WOURLComponents *url, const char *uri);
int ac_authorizeAppListing(WOURLComponents *url);
void *ap_get_module_config(void *conf, struct module *mod);
char *apr_pstrdup(void *pool, const char *str);

static const WOURLComponents WOURLComponents_Initializer = {0};
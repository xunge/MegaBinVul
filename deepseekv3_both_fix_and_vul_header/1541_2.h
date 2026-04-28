#include <string.h>
#include <strings.h>

#define WEBOBJECTS "webobjects"
#define WO_DBG 0
#define WO_ERR 0
#define WOURLOK 0
#define WOURLInvalidApplicationName 0
#define DECLINED -1
#define OK 0

typedef struct request_rec {
    char *uri;
    char *handler;
    void *pool;
    char *filename;
    struct {
        void *module_config;
    } *server;
} request_rec;

typedef struct WebObjects_config {
    char *WebObjects_alias;
} WebObjects_config;

typedef struct WOURLComponents {
    int dummy;
} WOURLComponents;

typedef int WOURLError;
typedef int module;

extern module WebObjects_module;
extern int adaptorEnabled;
extern WOURLComponents WOURLComponents_Initializer;

void WOLog(int level, const char *format, ...);
int ac_authorizeAppListing(WOURLComponents *url);
WOURLError WOParseApplicationName(WOURLComponents *url, const char *uri);
WebObjects_config *ap_get_module_config(void *module_config, module *mod);
char *apr_pstrdup(void *pool, const char *str);
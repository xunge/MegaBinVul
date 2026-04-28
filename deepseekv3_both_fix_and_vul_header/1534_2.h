#include <string.h>

typedef struct request_rec {
    struct server_rec *server;
    char *uri;
    void *pool;
    char *handler;
} request_rec;

typedef struct server_rec {
    void *module_config;
} server_rec;

typedef struct module {
    int dummy;
} module;

typedef struct WebObjects_config {
    char *WebObjects_alias;
} WebObjects_config;

typedef struct WOURLComponents {
    int dummy;
} WOURLComponents;

typedef enum WOURLError {
    WOURLOK,
    WOURLInvalidApplicationName
} WOURLError;

#define DECLINED -1
#define OK 0
#define WEBOBJECTS "WebObjects"
#define WO_DBG 0
#define WO_ERR 1

extern module WebObjects_module;
extern int adaptorEnabled;
extern void *ap_get_module_config(void *module_config, module *mod);
extern char *ap_pstrdup(void *pool, const char *str);

extern WOURLComponents WOURLComponents_Initializer;
extern WOURLError WOParseApplicationName(WOURLComponents *url, const char *uri);
extern int ac_authorizeAppListing(WOURLComponents *url);
extern void WOLog(int level, const char *format, ...);
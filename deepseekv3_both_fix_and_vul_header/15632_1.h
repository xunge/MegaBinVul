#include <stdbool.h>
#include <stdlib.h>

#define AGERR 1

typedef struct GVC_s GVC_t;
typedef struct gvplugin_package_s gvplugin_package_t;

typedef struct {
    const char *name;
} api_t;

extern gvplugin_package_t *gvplugin_package_record(GVC_t *gvc, char *package_path, char *name);
extern api_t gvplugin_api(char *api);
extern bool gvplugin_install(GVC_t *gvc, api_t api, const char *type, int quality, gvplugin_package_t *package, void *ptr);
extern void agerr(int level, const char *fmt, ...);
extern char *token(int *nest, char **s);
extern void separator(int *nest, char **s);
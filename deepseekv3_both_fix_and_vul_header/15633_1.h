#include <stdbool.h>
#include <stdlib.h>

typedef struct GVC_s GVC_t;
typedef struct gvplugin_package_s gvplugin_package_t;

typedef int api_t;
#define AGERR 0

extern char* token(int* nest, char** s);
extern void separator(int* nest, char** s);
extern gvplugin_package_t* gvplugin_package_record(GVC_t* gvc, char* package_path, char* name);
extern api_t gvplugin_api(const char* api);
extern bool gvplugin_install(GVC_t* gvc, api_t api, const char* type, int quality, gvplugin_package_t* package, void* ptr);
extern void agerr(int level, const char* fmt, ...);
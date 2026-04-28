#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>

typedef void* gpointer;
typedef int gboolean;
#define TRUE 1
#define FALSE 0

typedef enum {
    NM_VPN_PLUGIN_ERROR_BAD_ARGUMENTS
} NMVpnPluginError;

typedef enum {
    ITEM_TYPE_IGNORED,
    ITEM_TYPE_STRING,
    ITEM_TYPE_SECRET,
    ITEM_TYPE_PATH,
    ITEM_TYPE_INT,
    ITEM_TYPE_BOOLEAN
} ItemType;

typedef struct {
    const char *name;
    ItemType type;
    int int_min;
    int int_max;
} ValidProperty;

typedef struct {
    int domain;
    int code;
    char *message;
} GError;

typedef struct {
    ValidProperty *table;
    gboolean have_items;
    GError **error;
} ValidateInfo;

#define NM_SETTING_NAME "name"
#define NM_VPN_PLUGIN_ERROR 0
#define G_FILE_TEST_EXISTS 1

char* _(const char *str);
int g_strcmp0(const char *str1, const char *str2);
gboolean g_path_is_absolute(const char *file_name);
gboolean g_file_test(const char *filename, int test);

static void g_set_error(GError **err, int domain, int code, const char *format, ...) {
    va_list args;
    va_start(args, format);
    if (err) {
        *err = malloc(sizeof(GError));
        (*err)->domain = domain;
        (*err)->code = code;
        vasprintf(&(*err)->message, format, args);
    }
    va_end(args);
}
#include <stdlib.h>
#include <string.h>

typedef struct _EphyHistoryService EphyHistoryService;
typedef struct _EphySnapshotService EphySnapshotService;
typedef struct _EphyEmbedShell EphyEmbedShell;
typedef struct _GList {
    void *data;
    struct _GList *next;
    struct _GList *prev;
} GList;
typedef struct _GString {
    char *str;
    size_t len;
    size_t allocated_len;
} GString;
typedef struct _GtkIconInfo GtkIconInfo;
typedef struct _WebKitURISchemeRequest WebKitURISchemeRequest;

typedef int gboolean;
#define FALSE 0
#define TRUE 1
typedef unsigned int guint;
typedef size_t gsize;
typedef char gchar;

typedef enum {
    GTK_TEXT_DIR_NONE,
    GTK_TEXT_DIR_LTR,
    GTK_TEXT_DIR_RTL
} GtkTextDirection;

typedef struct _EphyHistoryURL {
    char *url;
    char *title;
} EphyHistoryURL;

#define EPHY_PAGE_TEMPLATE_ABOUT_CSS ""
#define NEW_TAB_PAGE_TITLE ""
#define APPLICATION_ID ""
#define _(x) x
#define g_autofree
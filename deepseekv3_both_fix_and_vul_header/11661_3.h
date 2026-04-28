#include <stdlib.h>
#include <string.h>

typedef struct _DialogData DialogData;
typedef struct _GthContactSheetTheme {
    void* file;
    int editable;
    char* display_name;
} GthContactSheetTheme;
typedef struct _GFile GFile;
typedef struct _GFileEnumerator GFileEnumerator;
typedef struct _GFileInfo GFileInfo;
typedef struct _GKeyFile GKeyFile;
typedef struct _GtkTreeIter {
    int dummy;
} GtkTreeIter;
typedef struct _GdkPixbuf GdkPixbuf;

#define PREVIEW_SIZE 128
#define THEME_COLUMN_THEME 0
#define THEME_COLUMN_DISPLAY_NAME 1
#define THEME_COLUMN_PREVIEW 2

#define G_FILE_ATTRIBUTE_STANDARD_NAME "standard::name"
#define G_FILE_ATTRIBUTE_STANDARD_TYPE "standard::type"
#define G_FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME "standard::display-name"
#define G_FILE_QUERY_INFO_NONE 0
#define G_FILE_TYPE_REGULAR 1
#define G_KEY_FILE_NONE 0

#define GET_WIDGET(x) ((void*)0)
#define GTK_LIST_STORE(x) ((void*)x)

typedef int gboolean;
typedef size_t gsize;

static void* g_object_ref(void* obj) { return obj; }
static void g_object_unref(void* obj) {}
static void _g_object_unref(void* obj) {}
static void g_free(void* ptr) {}
static int g_strcmp0(const char* s1, const char* s2) { return 0; }
static char* _g_uri_get_file_extension(const char* filename) { return NULL; }
static char* g_file_info_get_name(GFileInfo* info) { return NULL; }
static int g_file_info_get_file_type(GFileInfo* info) { return 0; }
static GFile* g_file_get_child(GFile* dir, const char* name) { return NULL; }
static int _g_file_load_in_buffer(GFile* file, void** buffer, gsize* size, void* a, void* b) { return 0; }
static GKeyFile* g_key_file_new(void) { return NULL; }
static int g_key_file_load_from_data(GKeyFile* key_file, char* buffer, gsize size, int flags, void* error) { return 0; }
static void g_key_file_free(GKeyFile* key_file) {}
static GthContactSheetTheme* gth_contact_sheet_theme_new_from_key_file(GKeyFile* key_file) { return NULL; }
static GdkPixbuf* gth_contact_sheet_theme_create_preview(GthContactSheetTheme* theme, int size) { return NULL; }
static void gtk_list_store_append(void* store, GtkTreeIter* iter) {}
static void gtk_list_store_set(void* store, GtkTreeIter* iter, ...) {}
static GFileEnumerator* g_file_enumerate_children(GFile* dir, const char* attributes, int flags, void* cancellable, void* error) { return NULL; }
static GFileInfo* g_file_enumerator_next_file(GFileEnumerator* enumerator, void* cancellable, void* error) { return NULL; }
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef int gboolean;
typedef char gchar;
typedef unsigned int guint32;
typedef size_t gsize;
typedef long gssize;
typedef void* gpointer;
typedef int gint;

#define TRUE 1
#define FALSE 0
#define GETTEXT_PACKAGE ""
#define G_FILE_TEST_EXISTS 1
#define G_FILE_TEST_IS_DIR 2

typedef struct _GError GError;
typedef struct _EMsgComposer EMsgComposer;
typedef struct _EAttachmentView EAttachmentView;
typedef struct _EAttachmentStore EAttachmentStore;
typedef struct _EComposerHeaderTable EComposerHeaderTable;
typedef struct _EDestination EDestination;
typedef struct _EAttachment EAttachment;
typedef struct _GSettings GSettings;
typedef struct _GObject GObject;
typedef struct _GAsyncResult GAsyncResult;
typedef struct _GFile GFile;

typedef struct _GList {
    void *data;
    struct _GList *next;
    struct _GList *prev;
} GList;

enum {
    CAMEL_MIME_FILTER_TOHTML_CONVERT_URLS = 1 << 0,
    CAMEL_MIME_FILTER_TOHTML_CONVERT_ADDRESSES = 1 << 1,
    CAMEL_MIME_FILTER_TOHTML_PRE = 1 << 2,
    CAMEL_MIME_FILTER_TOHTML_CONVERT_NL = 1 << 3,
    CAMEL_MIME_FILTER_TOHTML_CONVERT_SPACES = 1 << 4
};

typedef void (*GAsyncReadyCallback)(GObject *source_object, GAsyncResult *res, gpointer user_data);

static void g_list_free(GList *list) {
    while (list) {
        GList *next = list->next;
        free(list);
        list = next;
    }
}

static void g_clear_object(gpointer *object_ptr) {
    if (object_ptr && *object_ptr) {
        free(*object_ptr);
        *object_ptr = NULL;
    }
}

static void g_object_unref(gpointer object) {
    free(object);
}

static gchar* g_strdup(const gchar *str) {
    if (!str) return NULL;
    size_t len = strlen(str) + 1;
    gchar *new_str = malloc(len);
    if (new_str) memcpy(new_str, str, len);
    return new_str;
}

static gchar* g_strndup(const gchar *str, gsize n) {
    if (!str) return NULL;
    gsize len = strnlen(str, n);
    gchar *new_str = malloc(len + 1);
    if (new_str) {
        memcpy(new_str, str, len);
        new_str[len] = '\0';
    }
    return new_str;
}

static void g_free(gpointer mem) {
    free(mem);
}

static int g_ascii_strcasecmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        int c1 = tolower(*s1++);
        int c2 = tolower(*s2++);
        if (c1 != c2) return c1 - c2;
    }
    return *s1 - *s2;
}

static int g_ascii_strncasecmp(const char *s1, const char *s2, gsize n) {
    for (gsize i = 0; i < n; i++) {
        int c1 = tolower(s1[i]);
        int c2 = tolower(s2[i]);
        if (c1 != c2) return c1 - c2;
        if (c1 == '\0') break;
    }
    return 0;
}

static const char* g_dngettext(const char *domain, const char *msgid, const char *msgid_plural, unsigned long int n) {
    return n == 1 ? msgid : msgid_plural;
}

static char* g_strdup_printf(const char *format, ...) {
    return NULL;
}

static gchar* g_locale_to_utf8(const gchar *opsysstring, gssize len, gsize *bytes_read, gsize *bytes_written, GError **error) {
    return NULL;
}

static void e_attachment_load_handle_error(GObject *source_object, GAsyncResult *res, gpointer user_data) {}

static GList* add_recipients(GList *list, const gchar *recipients) { return NULL; }
static void camel_url_decode(gchar *str) {}
static gboolean g_utf8_validate(const gchar *str, gssize max_len, const gchar **end) { return TRUE; }
static gpointer g_realloc(gpointer mem, gsize n_bytes) { return realloc(mem, n_bytes); }
static gboolean file_is_blacklisted(const gchar *filename) { return FALSE; }
static void merge_always_cc_and_bcc(EComposerHeaderTable *table, GList *to, GList **cc, GList **bcc) {}
static EDestination** destination_list_to_vector(GList *list) { return NULL; }
static void e_destination_freev(EDestination **vector) {}
static gchar* camel_text_to_html(const gchar *text, guint32 flags, guint32 colour) { return NULL; }
static void set_editor_text(EMsgComposer *composer, const gchar *text, gboolean is_html, gboolean set_signature) {}

EComposerHeaderTable* e_msg_composer_get_header_table(EMsgComposer *composer) { return NULL; }
EAttachmentView* e_msg_composer_get_attachment_view(EMsgComposer *composer) { return NULL; }
EAttachmentStore* e_attachment_view_get_store(EAttachmentView *view) { return NULL; }
void e_msg_composer_add_header(EMsgComposer *composer, const gchar *name, const gchar *value) {}
EAttachment* e_attachment_new_for_uri(const gchar *uri) { return NULL; }
EAttachment* e_attachment_new_for_path(const gchar *path) { return NULL; }
GFile* e_attachment_ref_file(EAttachment *attachment) { return NULL; }
const gchar* g_file_peek_path(GFile *file) { return NULL; }
gboolean g_file_test(const gchar *filename, int test) { return FALSE; }
void e_attachment_store_add_attachment(EAttachmentStore *store, EAttachment *attachment) {}
void e_attachment_load_async(EAttachment *attachment, GAsyncReadyCallback callback, gpointer user_data) {}
void e_alert_submit(gpointer sink, const gchar *type, const gchar *message, ...) {}
GSettings* e_util_ref_settings(const gchar *schema_id) { return NULL; }
gboolean g_settings_get_boolean(GSettings *settings, const gchar *key) { return FALSE; }
void e_composer_header_table_set_destinations_to(EComposerHeaderTable *table, EDestination **to) {}
void e_composer_header_table_set_destinations_cc(EComposerHeaderTable *table, EDestination **cc) {}
void e_composer_header_table_set_destinations_bcc(EComposerHeaderTable *table, EDestination **bcc) {}
void e_composer_header_table_set_subject(EComposerHeaderTable *table, const gchar *subject) {}
gpointer e_msg_composer_get_editor(EMsgComposer *composer) { return NULL; }
gpointer E_ALERT_SINK(gpointer editor) { return editor; }
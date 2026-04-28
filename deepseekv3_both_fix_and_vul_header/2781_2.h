#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _EMsgComposer EMsgComposer;
typedef struct _EAttachmentView EAttachmentView;
typedef struct _EAttachmentStore EAttachmentStore;
typedef struct _EComposerHeaderTable EComposerHeaderTable;
typedef struct _EDestination EDestination;
typedef struct _EAttachment EAttachment;
typedef struct _GList GList;
typedef long gssize;
typedef void* GError;

#define gchar char
#define gint int
#define gsize size_t
#define gboolean int
#define TRUE 1
#define FALSE 0
#define CAMEL_MIME_FILTER_TOHTML_PRE 0
typedef void (*GAsyncReadyCallback)(void*, void*, void*);

GList *g_list_append(GList *list, void *data);
void g_list_free(GList *list);
char *g_strdup(const char *str);
char *g_strndup(const char *str, size_t n);
void g_free(void *ptr);
int g_ascii_strcasecmp(const char *s1, const char *s2);
int g_ascii_strncasecmp(const char *s1, const char *s2, size_t n);
int g_utf8_validate(const char *str, long max_len, const char **end);
char *g_locale_to_utf8(const char *opsysstring, gssize len, gsize *bytes_read, gsize *bytes_written, GError **error);
void *g_realloc(void *mem, size_t n_bytes);

GList *add_recipients(GList *list, const gchar *content);
void merge_always_cc_and_bcc(EComposerHeaderTable *table, GList *to, GList **cc, GList **bcc);
EDestination **destination_list_to_vector(GList *list);
void e_destination_freev(EDestination **destinations);
void e_msg_composer_add_header(EMsgComposer *composer, const gchar *header, const gchar *content);
void set_editor_text(EMsgComposer *composer, gchar *text, gboolean is_html);
char *camel_text_to_html(const char *text, gint flags, gint length);
void camel_url_decode(char *str);
void e_attachment_load_handle_error(EAttachment *attachment, void *res, EMsgComposer *composer);
EAttachment *e_attachment_new_for_uri(const char *uri);
EAttachment *e_attachment_new_for_path(const char *path);
void e_attachment_store_add_attachment(EAttachmentStore *store, EAttachment *attachment);
void e_attachment_load_async(EAttachment *attachment, GAsyncReadyCallback callback, EMsgComposer *composer);
void g_object_unref(void *object);
EComposerHeaderTable *e_msg_composer_get_header_table(EMsgComposer *composer);
EAttachmentView *e_msg_composer_get_attachment_view(EMsgComposer *composer);
EAttachmentStore *e_attachment_view_get_store(EAttachmentView *view);
void e_composer_header_table_set_destinations_to(EComposerHeaderTable *table, EDestination **dest);
void e_composer_header_table_set_destinations_cc(EComposerHeaderTable *table, EDestination **dest);
void e_composer_header_table_set_destinations_bcc(EComposerHeaderTable *table, EDestination **dest);
void e_composer_header_table_set_subject(EComposerHeaderTable *table, const char *subject);
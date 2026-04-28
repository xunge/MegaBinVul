#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef int gboolean;
typedef char gchar;
typedef int gint;
typedef unsigned long gulong;
typedef void* GckSession;
typedef void* GSettings;
typedef void* GckAttributes;
typedef void* GcrPrompt;
typedef void* GError;

#define TRUE 1
#define FALSE 0
#define GCK_IS_SESSION(session) (1)
#define CKA_G_COLLECTION "CKA_G_COLLECTION"
#define CKA_GNOME_TRANSIENT "CKA_GNOME_TRANSIENT"
#define CKA_G_DESTRUCT_IDLE "CKA_G_DESTRUCT_IDLE"
#define CKA_G_DESTRUCT_AFTER "CKA_G_DESTRUCT_AFTER"

#define G_IO_ERROR 0
#define G_IO_ERROR_CANCELLED 1

#define GCR_UNLOCK_OPTION_ALWAYS "always"
#define GCR_UNLOCK_OPTION_IDLE "idle"
#define GCR_UNLOCK_OPTION_TIMEOUT "timeout"
#define GCR_UNLOCK_OPTION_SESSION "session"

typedef struct {
    // dummy structure
} GckBuilder;

#define GCK_BUILDER_INIT {}

static gchar* do_lookup_password(GckSession *session, const gchar *keyid);
static GcrPrompt* open_password_prompt(GckSession *session, const gchar *keyid, const gchar *errmsg, const gchar *prompt_text, const gchar *description, gboolean confirm);
static gchar* egg_secure_strdup(const gchar *str);
static gchar* egg_error_message(GError *error);
static GSettings* gkd_gpg_agent_settings(void);
static void do_save_password(GckSession *session, const gchar *keyid, const gchar *description, const gchar *password, GckAttributes *attrs);

void g_assert(int condition);
void g_warning(const char *format, ...);
void g_message(const char *format, ...);
void g_clear_error(GError **error);
void g_clear_object(GcrPrompt **prompt);
void g_free(void *ptr);
int g_strcmp0(const char *str1, const char *str2);
gboolean g_error_matches(GError *error, int domain, int code);
gchar* g_settings_get_string(GSettings *settings, const char *key);
gint g_settings_get_int(GSettings *settings, const char *key);
void g_settings_set_string(GSettings *settings, const char *key, const char *value);
gboolean gcr_prompt_get_choice_chosen(GcrPrompt *prompt);
gchar* gcr_prompt_password(GcrPrompt *prompt, void *unused, GError **error);
GckAttributes* gck_attributes_ref_sink(GckAttributes *attrs);
void gck_attributes_unref(GckAttributes *attrs);
void gck_builder_add_string(GckBuilder *builder, const char *type, const char *value);
void gck_builder_add_boolean(GckBuilder *builder, const char *type, gboolean value);
void gck_builder_add_ulong(GckBuilder *builder, const char *type, gulong value);
GckAttributes* gck_builder_end(GckBuilder *builder);
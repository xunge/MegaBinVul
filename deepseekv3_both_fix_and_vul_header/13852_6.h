#include <time.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _InfGtkCertificateManager InfGtkCertificateManager;
typedef struct _InfGtkCertificateManagerPrivate InfGtkCertificateManagerPrivate;
typedef struct _InfGtkCertificateManagerQuery InfGtkCertificateManagerQuery;
typedef struct _InfXmppConnection InfXmppConnection;
typedef struct _InfCertificateChain InfCertificateChain;
typedef struct _InfGtkCertificateDialog InfGtkCertificateDialog;
typedef struct _GtkWidget GtkWidget;
typedef struct _GtkLabel GtkLabel;
typedef struct _GtkMisc GtkMisc;
typedef struct _GtkBox GtkBox;
typedef struct _GtkWindow GtkWindow;
typedef struct _GtkDialog GtkDialog;
typedef struct _GObject GObject;
typedef struct _GParamSpec GParamSpec;
typedef struct _GError GError;
typedef struct _GHashTable GHashTable;
typedef struct _GSList GSList;

typedef enum {
    INF_GTK_CERTIFICATE_DIALOG_CERT_HOSTNAME_MISMATCH = 1 << 0,
    INF_GTK_CERTIFICATE_DIALOG_CERT_ISSUER_NOT_KNOWN = 1 << 1,
    INF_GTK_CERTIFICATE_DIALOG_CERT_UNEXPECTED = 1 << 2,
    INF_GTK_CERTIFICATE_DIALOG_CERT_OLD_EXPIRED = 1 << 3
} InfGtkCertificateDialogFlags;

typedef void* gnutls_session_t;
typedef void* gnutls_x509_crt_t;
typedef int gboolean;
typedef void* gpointer;
typedef char gchar;
typedef int32_t gint;

#define INF_GTK_CERTIFICATE_MANAGER(obj) ((InfGtkCertificateManager*)obj)
#define INF_GTK_CERTIFICATE_MANAGER_PRIVATE(obj) ((InfGtkCertificateManagerPrivate*)obj)
#define G_OBJECT(obj) ((GObject*)obj)
#define GTK_DIALOG(obj) ((GtkDialog*)obj)
#define GTK_LABEL(obj) ((GtkLabel*)obj)
#define GTK_WINDOW(obj) ((GtkWindow*)obj)
#define GTK_BOX(obj) ((GtkBox*)obj)
#define GTK_MISC(obj) ((GtkMisc*)obj)
#define G_CALLBACK(func) ((void(*)(void))func)

#define GNUTLS_E_SUCCESS 0
#define GNUTLS_CERT_SIGNER_NOT_FOUND 1
#define GNUTLS_CERT_INVALID 2
#define GNUTLS_VERIFY_ALLOW_X509_V1_CA_CRT 4
#define GTK_RESPONSE_REJECT 0
#define GTK_RESPONSE_ACCEPT 1
#define TRUE 1
#define FALSE 0
#define PANGO_WRAP_WORD_CHAR 0
#define INF_GTK_CERTIFICATE_MANAGER_EXPIRATION_TOLERANCE (86400 * 30)

struct _InfGtkCertificateManagerPrivate {
    GtkWindow* parent_window;
    GSList* queries;
};

struct _InfGtkCertificateManagerQuery {
    InfGtkCertificateManager* manager;
    GHashTable* known_hosts;
    InfXmppConnection* connection;
    InfGtkCertificateDialog* dialog;
    InfCertificateChain* certificate_chain;
};

static char* _(const char* str) { return (char*)str; }

/* Function declarations */
void* inf_certificate_chain_get_raw(InfCertificateChain* chain);
int inf_certificate_chain_get_n_certificates(InfCertificateChain* chain);
void* g_slice_new(size_t size);
void inf_gtk_certificate_manager_notify_status_cb(GObject* connection, GParamSpec* pspec, gpointer user_data);
void inf_gtk_certificate_manager_response_cb(GtkDialog* dialog, gint response_id, gpointer user_data);

/* Dummy function declarations */
void g_object_get(GObject* obj, const char* prop, void* val, ...);
void* inf_certificate_chain_get_own_certificate(InfCertificateChain* chain);
int gnutls_x509_crt_check_hostname(void* cert, const char* hostname);
int gnutls_certificate_verify_peers2(void* session, unsigned int* verify);
void inf_gnutls_set_error(GError** error, int ret);
void* inf_certificate_chain_get_root_certificate(InfCertificateChain* chain);
int gnutls_x509_crt_list_verify(void* chain, int n, void** root, int roots, 
                               void** trusted, int trusted_size, unsigned flags, 
                               unsigned* verify);
void inf_gnutls_certificate_verification_set_error(GError** error, unsigned verify);
GHashTable* inf_gtk_certificate_manager_ref_known_hosts(InfGtkCertificateManager* mgr, GError** err);
void* g_hash_table_lookup(GHashTable* table, const char* key);
gboolean inf_gtk_certificate_manager_compare_fingerprint(void* known, void* presented, GError** err);
time_t gnutls_x509_crt_get_expiration_time(void* cert);
gboolean g_hash_table_remove(GHashTable* table, const char* key);
void inf_gtk_certificate_manager_write_known_hosts_with_warning(InfGtkCertificateManager* mgr, GHashTable* table);
void inf_xmpp_connection_certificate_verify_continue(InfXmppConnection* conn);
void* inf_gtk_certificate_dialog_new(void* parent, int flags, int dialog_flags, const char* host, InfCertificateChain* chain);
void g_object_ref(void* obj);
void inf_certificate_chain_ref(InfCertificateChain* chain);
void g_signal_connect(GObject* obj, const char* signal, void* callback, void* data);
void gtk_dialog_add_button(GtkDialog* dialog, const char* text, int response);
char* g_strdup_printf(const char* fmt, ...);
void* gtk_label_new(const char* text);
void gtk_label_set_line_wrap(GtkLabel* label, gboolean wrap);
void gtk_label_set_line_wrap_mode(GtkLabel* label, int mode);
void gtk_label_set_max_width_chars(GtkLabel* label, int n_chars);
void gtk_misc_set_alignment(GtkMisc* misc, float xalign, float yalign);
void gtk_widget_show(void* widget);
void g_free(void* ptr);
void* gtk_dialog_get_content_area(GtkDialog* dialog);
void gtk_box_pack_start(GtkBox* box, void* child, gboolean expand, gboolean fill, int padding);
void* g_slist_prepend(void* list, void* data);
void gtk_window_present(GtkWindow* window);
void inf_xmpp_connection_certificate_verify_cancel(InfXmppConnection* conn, GError* err);
void g_error_free(GError* error);
void g_hash_table_unref(GHashTable* table);

/* Fix for g_slice_new usage */
#define g_slice_new(type) ((type*)malloc(sizeof(type)))
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define FALSE 0
#define TRUE 1
#define ESEXP_RES_STRING 1
#define ESEXP_RES_BOOL 2
#define PROP_TYPE_STRING 0x1
#define PROP_WRITE_ONLY 0x2
#define PROP_EVOLVE 0x4
#define PROP_CALENTRY 0x8

typedef int gint;
typedef void* gpointer;
typedef char gchar;
typedef int gboolean;

typedef struct {
    gchar* str;
    size_t len;
    size_t allocated_len;
} GString;

typedef struct _ESExp ESExp;
typedef struct _ESExpResult ESExpResult;
typedef struct _EBookBackendLDAPSExpData EBookBackendLDAPSExpData;

struct _ESExpResult {
    int type;
    union {
        gboolean boolean;
        gchar *string;
    } value;
};

struct BackendPrivate {
    gboolean evolutionPersonSupported;
    gboolean calEntrySupported;
};

struct Backend {
    struct BackendPrivate *priv;
};

struct _EBookBackendLDAPSExpData {
    void *list;
    struct Backend *bl;
};

typedef struct {
    const gchar *ldap_attr;
    int prop_type;
} PropInfo;

static PropInfo prop_info[] = {
    /* This should be filled with actual data */
    {NULL, 0}
};

#define G_N_ELEMENTS(arr) (sizeof(arr)/sizeof(arr[0]))

extern const gchar *query_prop_to_ldap(const gchar *propname, gboolean evolutionPersonSupported, gboolean calEntrySupported);
extern gchar *extend_query_value(gchar *str);
extern gchar *rfc2254_escape(gchar *str);
extern ESExpResult *e_sexp_result_new(ESExp *f, int type);
extern void g_free(void *ptr);
extern gchar *g_strdup_printf(const char *format, ...);
extern GString *g_string_sized_new(size_t dfl_size);
extern void g_string_append(GString *string, const gchar *val);
extern void *g_list_prepend(void *list, void *data);
extern gchar *g_string_free(GString *string, gboolean free_segment);
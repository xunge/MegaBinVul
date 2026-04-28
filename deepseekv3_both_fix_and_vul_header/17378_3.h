#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1

typedef int gint;
typedef void* gpointer;
typedef char gchar;

#define ESEXP_RES_STRING 1
#define ESEXP_RES_BOOL 2

typedef struct _ESExp ESExp;
typedef struct _ESExpResult ESExpResult;
typedef struct _EBookBackendLDAPSExpData EBookBackendLDAPSExpData;

struct _ESExpResult {
    int type;
    union {
        int boolean;
        char *string;
    } value;
};

struct _EBookBackendLDAPPrivate {
    int evolutionPersonSupported;
    int calEntrySupported;
};

struct _EBookBackendLDAP {
    struct _EBookBackendLDAPPrivate *priv;
};

struct _EBookBackendLDAPSExpData {
    struct _EBookBackendLDAP *bl;
    void *list;
};

typedef struct {
    const char *ldap_attr;
    int prop_type;
} PropInfo;

static const PropInfo prop_info[1] = {{NULL, 0}};

static const char *query_prop_to_ldap(const char *propname, int evolutionPersonSupported, int calEntrySupported) {
    return NULL;
}

#define PROP_WRITE_ONLY (1 << 0)
#define PROP_EVOLVE (1 << 1)
#define PROP_CALENTRY (1 << 2)

#define G_N_ELEMENTS(arr) (sizeof(arr)/sizeof((arr)[0]))

typedef struct {
    char *str;
    size_t len;
    size_t allocated_len;
} GString;

GString *g_string_sized_new(size_t size) {
    GString *s = malloc(sizeof(GString));
    s->str = malloc(size);
    s->len = 0;
    s->allocated_len = size;
    return s;
}

void g_string_append(GString *string, const char *val) {
    size_t len = strlen(val);
    if (string->len + len >= string->allocated_len) {
        string->allocated_len = string->len + len + 1;
        string->str = realloc(string->str, string->allocated_len);
    }
    strcpy(string->str + string->len, val);
    string->len += len;
}

char *g_string_free(GString *string, int free_segment) {
    char *result = NULL;
    if (free_segment) {
        free(string->str);
    } else {
        result = string->str;
    }
    free(string);
    return result;
}

void *g_list_prepend(void *list, void *data) {
    struct Node {
        void *data;
        struct Node *next;
    };
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = list;
    return node;
}

char *g_strdup(const char *str) {
    return str ? strdup(str) : NULL;
}

char *g_strdup_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int len = vsnprintf(NULL, 0, format, args);
    va_end(args);
    char *buf = malloc(len + 1);
    va_start(args, format);
    vsnprintf(buf, len + 1, format, args);
    va_end(args);
    return buf;
}

void g_free(void *ptr) {
    free(ptr);
}

ESExpResult *e_sexp_result_new(ESExp *f, int type) {
    ESExpResult *r = malloc(sizeof(ESExpResult));
    r->type = type;
    return r;
}
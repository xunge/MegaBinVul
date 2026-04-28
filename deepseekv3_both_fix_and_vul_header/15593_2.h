#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char gchar;
typedef bool gboolean;
typedef unsigned int guint;

#define FALSE false
#define TRUE true

#define EV_DOCUMENT_ERROR 1
enum {
    EV_DOCUMENT_ERROR_INVALID
};

typedef struct {
    int domain;
    int code;
    char *message;
} GError;

static inline int g_strv_length(const gchar **array) {
    int len = 0;
    while (array[len]) len++;
    return len;
}

static inline int g_strcmp0(const char *str1, const char *str2) {
    if (!str1 || !str2) return str1 ? 1 : (str2 ? -1 : 0);
    return strcmp(str1, str2);
}

static inline void g_set_error_literal(GError **err, int domain, int code, const char *message) {
    if (err) {
        *err = malloc(sizeof(GError));
        if (*err) {
            (*err)->domain = domain;
            (*err)->code = code;
            (*err)->message = strdup(message);
        }
    }
}

static inline void g_propagate_error(GError **dest, GError *src) {
    if (dest) *dest = src;
}

#define _(x) x

const gchar *ev_file_get_mime_type(const gchar *uri, gboolean sniff, GError **error);
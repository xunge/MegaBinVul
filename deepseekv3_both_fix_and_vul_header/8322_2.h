#include <stdlib.h>
#include <string.h>

typedef struct _GError {
    int domain;
    int code;
    char *message;
} GError;

typedef struct _GtkWidget GtkWidget;
typedef char gchar;

#define g_return_val_if_fail(expr, val) \
    do { if (!(expr)) return (val); } while (0)

#define _(str) (str)

char* g_markup_escape_text(const char *text, int length);
char* g_strdup(const char *str);
char* g_strdup_printf(const char *format, ...);
void g_free(void *ptr);

#define EOG_ERROR_MESSAGE_AREA_CANCEL_BUTTON (1 << 0)

GtkWidget* create_error_message_area(const gchar *error_message,
                                    const gchar *message_details,
                                    unsigned int flags);
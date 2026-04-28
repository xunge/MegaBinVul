#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

typedef bool gboolean;
typedef char gchar;
typedef int gint;

#define FALSE false
#define TRUE true

typedef struct {
    gchar *message;
} GError;

typedef enum {
    RARLABS,
    GNAUNRAR,
    UNZIP,
    P7ZIP,
    TAR
} CommandUsage;

typedef struct {
    gchar *selected_command;
    gchar *alternative_command;
    CommandUsage command_usage;
} ComicsDocument;

#define EV_DOCUMENT_ERROR 1
enum {
    EV_DOCUMENT_ERROR_INVALID
};

#define _(x) x

static gboolean g_content_type_is_a(gchar *type, const char *subtype) {
    return strcmp(type, subtype) == 0;
}

static gchar* g_find_program_in_path(const char *program) {
    return program[0] ? strdup(program) : NULL;
}

static gboolean g_spawn_command_line_sync(const gchar *command, gchar **std_out, 
                                        gchar **std_err, gint *exit_status, GError **error) {
    return TRUE;
}

static void g_propagate_error(GError **dest, GError *src) {
    *dest = src;
}

static void g_error_free(GError *error) {
    free(error);
}

static char* g_strrstr(const char *haystack, const char *needle) {
    return strstr(haystack, needle);
}

static void g_free(void *ptr) {
    free(ptr);
}

static void g_set_error(GError **err, int domain, int code, const char *format, ...) {}

static void g_set_error_literal(GError **err, int domain, int code, const char *message) {}
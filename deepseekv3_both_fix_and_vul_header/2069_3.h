#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

typedef struct _GDBusMethodInvocation GDBusMethodInvocation;
typedef int gint;
typedef char gchar;
typedef struct _PolkitSubject PolkitSubject;
typedef pid_t GPid;

int get_caller_uid(GDBusMethodInvocation *context, gint *uid);
int get_caller_pid(GDBusMethodInvocation *context, GPid *pid);
char* g_strdup_printf(const char *format, ...);
int g_file_get_contents(const char *filename, char **contents, size_t *length, void *error);
void g_free(void *ptr);
int g_snprintf(char *string, size_t n, const char *format, ...);
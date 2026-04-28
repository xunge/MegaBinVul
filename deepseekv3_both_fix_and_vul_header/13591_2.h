#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CPDB_BSIZE 256
#define CPDB_BACKEND_INFO_DIR "/usr/share/cpdb/backend-info"

typedef struct _PrintBackend PrintBackend;
typedef struct _GDBusConnection GDBusConnection;

struct _GError {
    int domain;
    int code;
    char *message;
};
typedef struct _GError GError;

extern char *cpdbGetStringCopy(const char *str);
extern char *cpdbConcatPath(const char *dir, const char *file);
extern void logerror(const char *format, ...);
extern PrintBackend *print_backend_proxy_new_sync(GDBusConnection *connection,
                                                int flags,
                                                const char *name,
                                                const char *object_path,
                                                void *unused,
                                                GError **error);
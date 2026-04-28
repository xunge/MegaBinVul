#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int numberOfArguments;
    char **mimeArguments;
} message;

extern void cli_dbgmsg(const char *format, ...);
extern int usefulArg(const char *arg);
extern char *rfc2231(const char *arg);
extern const char *messageGetMimeType(message *m);
extern void messageSetMimeType(message *m, const char *type);

#define NOMIME NULL
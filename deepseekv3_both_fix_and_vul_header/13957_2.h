#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

typedef struct message {
    int numberOfArguments;
} message;

char *cli_strdup(const char *s);
void cli_dbgmsg(const char *format, ...);
char *messageGetArgument(const message *m, int i);
#include <time.h>
#include <string.h>
#include <limits.h>

#define CRLF "\r\n"

typedef struct PFTPCONTEXT {
    unsigned long SessionID;
} *PFTPCONTEXT;

void ultostr(unsigned long num, char *str);
int writeconsolestr(const char *str);
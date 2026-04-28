#include <poll.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>

#define ISCTRLCODE(c) ((c) < 0x20 || (c) == 0x7F)
#define LOG_WARNING 4
#define MSG_LINE_TOO_LONG "Line too long"

extern size_t scanned;
extern size_t readnbd;
extern size_t cmdsize;
extern int clientfd;
extern unsigned int idletime;
extern char *cmd;

void die(int code, int priority, const char *message);
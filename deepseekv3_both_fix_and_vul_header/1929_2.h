#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

typedef int gboolean;
typedef void* gpointer;
typedef unsigned long gsize;
typedef int GIOStatus;
typedef char gchar;
typedef struct _GIOChannel GIOChannel;
typedef int GIOCondition;
typedef struct _GError GError;

struct sockaddr_nl {
    unsigned short nl_family;
    unsigned short nl_pad;
    unsigned int nl_pid;
    unsigned int nl_groups;
};

#define FALSE 0
#define TRUE 1
#define G_IO_NVAL (1 << 0)
#define G_IO_HUP (1 << 1)
#define G_IO_ERR (1 << 2)
#define G_IO_STATUS_NORMAL 0
#define G_IO_STATUS_AGAIN 1
#define DBG(fmt, ...)

int g_io_channel_unix_get_fd(GIOChannel *channel);
GIOStatus g_io_channel_read_chars(GIOChannel *channel, gchar *buf, gsize count, gsize *bytes_read, GError **error);
void rtnl_message(unsigned char *buf, int len);
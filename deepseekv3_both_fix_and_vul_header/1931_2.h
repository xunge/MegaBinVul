#include <sys/socket.h>
#include <netinet/in.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

typedef void* gpointer;
typedef unsigned long gsize;
typedef struct _GIOChannel GIOChannel;
typedef char gchar;

struct inet_rtnl_cb_data {
    struct __connman_inet_rtnl_handle *rtnl;
    void (*callback)(struct nlmsghdr *h, void *user_data);
    void *user_data;
    unsigned int rtnl_timeout;
};

struct __connman_inet_rtnl_handle {
    int fd;
    int seq;
};

enum {
    G_IO_STATUS_NORMAL,
    G_IO_STATUS_AGAIN
};

#define DBG(fmt, ...) 
#define connman_error(fmt, ...) 

static void __connman_inet_rtnl_close(struct __connman_inet_rtnl_handle *rth);
static void g_free(void *ptr);
static int g_io_channel_read_chars(GIOChannel *chan, gchar *buf, size_t count, gsize *bytes_read, void *null);
static int g_io_channel_unix_get_fd(GIOChannel *chan);
static void g_source_remove(unsigned int id);
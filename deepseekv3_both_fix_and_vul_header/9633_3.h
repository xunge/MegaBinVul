#include <stddef.h>

typedef struct _IPADDR IPADDR;
typedef struct _GIOChannel GIOChannel;
typedef int gboolean;

GIOChannel *net_connect_ip(IPADDR *ip, int port, IPADDR *my_ip);
GIOChannel *irssi_ssl_get_iochannel(GIOChannel *handle, ...);
void g_io_channel_unref(GIOChannel *channel);
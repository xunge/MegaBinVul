#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

typedef struct {
    int fd;
} GIOChannel;

typedef struct {
    void* ice_connection;
    int watch_id;
    unsigned int protocol_timeout;
    char* description;
} GsmXSMPClientPrivate;

typedef struct {
    GsmXSMPClientPrivate* priv;
} GsmXSMPClient;

#define G_IO_IN  1
#define G_IO_ERR 4

typedef int (*GIOFunc)(GIOChannel* source, int condition, void* data);
typedef int (*GSourceFunc)(void* data);

static int client_iochannel_watch(GIOChannel* source, int condition, void* data) { return 0; }
static int _client_protocol_timeout(void* data) { return 0; }
static void set_description(GsmXSMPClient* client) {}
static void g_debug(const char* format, ...) {}
static int IceConnectionNumber(void* ice_conn) { return 0; }
static GIOChannel* g_io_channel_unix_new(int fd) { static GIOChannel ch; ch.fd = fd; return &ch; }
static int g_io_add_watch(GIOChannel* channel, int condition, GIOFunc func, void* data) { return 0; }
static void g_io_channel_unref(GIOChannel* channel) {}
static unsigned int g_timeout_add_seconds(unsigned int interval, GSourceFunc function, void* data) { return 0; }
#include <stdint.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <time.h>
#include <stdio.h>

typedef bool gboolean;
typedef void* gpointer;

struct dhcp_packet {
    uint32_t ciaddr;
    uint8_t chaddr[16];
};

struct dhcp_lease {
    uint32_t lease_nip;
};

typedef struct {
    int listener_watch;
    int listener_sockfd;
    uint32_t server_nip;
} GDHCPServer;

typedef struct GIOChannel GIOChannel;
typedef int GIOCondition;

#define G_IO_NVAL (1 << 0)
#define G_IO_ERR (1 << 1)
#define G_IO_HUP (1 << 2)
#define FALSE false
#define TRUE true

#define DHCP_SERVER_ID 54
#define DHCP_REQUESTED_IP 50
#define DHCPDISCOVER 1
#define DHCPREQUEST 3
#define DHCPDECLINE 4
#define DHCPRELEASE 7
#define DHCPINFORM 8

static void debug(GDHCPServer *server, const char *message, ...) {
    va_list args;
    va_start(args, message);
    vprintf(message, args);
    va_end(args);
}
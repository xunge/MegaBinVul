#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>

#define ADDRESS_BUFFER_SIZE 256

enum AddressType {
    WILDCARD,
    HOSTNAME
};

struct Address {
    enum AddressType type;
    uint16_t port;
    size_t len;
    char data[];
};

extern struct Address *new_address_sa(const struct sockaddr *sa, socklen_t salen);
extern int is_numeric(const char *s);
extern int valid_hostname(const char *hostname);
extern void address_set_port(struct Address *addr, uint16_t port);
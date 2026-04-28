#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

extern struct cfg *cfg;

enum log_level {
  E_LOG,
  E_DBG
};

enum log_domain {
  L_MISC
};

#define DPRINTF(level, domain, fmt, ...) /* macro definition */

union net_sockaddr {
  struct sockaddr sa;
  struct sockaddr_in sin;
  struct sockaddr_in6 sin6;
};

int cfg_getbool(struct cfg_section *sec, const char *key);
const char *cfg_getstr(struct cfg_section *sec, const char *key);
struct cfg_section *cfg_getsec(struct cfg *cfg, const char *name);
void net_port_get(short unsigned *port, union net_sockaddr *sa);
void net_address_get(char *addr, size_t addrlen, union net_sockaddr *sa);
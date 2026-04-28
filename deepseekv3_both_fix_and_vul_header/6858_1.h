#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct {
    char *name;
    size_t namelen;
} cupsd_alias_t;

typedef struct {
    char *hostname;
    size_t hostlen;
} cupsd_netif_t;

typedef struct {
    char clientname[256];
    int clientport;
    int serverport;
    void *http;
} cupsd_client_t;

typedef struct http_addrlist_s http_addrlist_t;

#define HTTP_FIELD_HOST 0

extern cupsd_alias_t *ServerAlias;
extern cupsd_alias_t *DNSSDAlias;
extern cupsd_netif_t *NetIFList;

extern int _cups_strcasecmp(const char *, const char *);
extern int _cups_strncasecmp(const char *, const char *, size_t);
extern size_t strlcpy(char *, const char *, size_t);
extern char *httpGetField(void *, int);
extern int httpAddrLocalhost(void *);
extern void *httpGetAddress(void *);
extern http_addrlist_t *httpAddrGetList(const char *, int, void *);
extern void httpAddrFreeList(http_addrlist_t *);
extern void *cupsArrayFirst(void *);
extern void *cupsArrayNext(void *);
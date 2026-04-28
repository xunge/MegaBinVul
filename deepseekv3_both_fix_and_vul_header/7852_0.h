#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int SOCKET;
#define INVALID_SOCKET (-1)

#define XML_FROM_HTTP 0
#define XML_HTTP_URL_SYNTAX 0
#define XML_HTTP_UNKNOWN_HOST 0
#define XML_NANO_HTTP_WRITE 0
#define XML_NANO_HTTP_READ 0
#define XML_NANO_HTTP_MAX_REDIR 0
#define DEBUG_HTTP 0
#define HAVE_ZLIB_H 0

typedef struct _xmlNanoHTTPCtxt xmlNanoHTTPCtxt;
typedef xmlNanoHTTPCtxt *xmlNanoHTTPCtxtPtr;

struct _xmlNanoHTTPCtxt {
    char *protocol;
    char *hostname;
    int port;
    char *path;
    char *query;
    char *location;
    char *contentType;
    int returnValue;
    SOCKET fd;
    char *out;
    char *outptr;
    char *inrptr;
    char *content;
    int state;
};

extern char *proxy;
extern int proxyPort;

void xmlNanoHTTPInit(void);
xmlNanoHTTPCtxtPtr xmlNanoHTTPNewCtxt(const char *URL);
void xmlNanoHTTPFreeCtxt(xmlNanoHTTPCtxtPtr ctxt);
void __xmlIOErr(int domain, int code, const char *msg);
void xmlFree(void *ptr);
void *xmlMallocAtomic(size_t size);
char *xmlMemStrdup(const char *str);
void xmlHTTPErrMemory(const char *msg);
SOCKET xmlNanoHTTPConnectHost(const char *hostname, int port);
int xmlNanoHTTPSend(xmlNanoHTTPCtxtPtr ctxt, const char *ptr, int len);
char *xmlNanoHTTPReadLine(xmlNanoHTTPCtxtPtr ctxt);
void xmlNanoHTTPScanAnswer(xmlNanoHTTPCtxtPtr ctxt, char *line);
int xmlNanoHTTPRecv(xmlNanoHTTPCtxtPtr ctxt);
void xmlGenericError(void *ctx, const char *msg, ...);
extern void *xmlGenericErrorContext;
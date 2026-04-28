#include <string.h>
#include <errno.h>
#include <stdio.h>

typedef struct _GIOChannel GIOChannel;
typedef struct _GIOSSLChannel GIOSSLChannel;

struct _GIOSSLChannel {
    void *ssl;
    void *ctx;
    int verify;
    const char *hostname;
};

typedef void X509;

#define SSL_ERROR_WANT_READ 1
#define SSL_ERROR_WANT_WRITE 2
#define SSL_ERROR_ZERO_RETURN 3
#define SSL_ERROR_SYSCALL 4

#define g_warning printf
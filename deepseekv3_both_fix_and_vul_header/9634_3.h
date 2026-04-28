#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct SSL {
    int dummy;
} SSL;

typedef struct SSL_CTX {
    int dummy;
} SSL_CTX;

typedef struct GIOChannel {
    struct GIOFuncs* funcs;
    int is_readable;
    int is_writeable;
    int use_buffer;
} GIOChannel;

typedef struct GIOFuncs {
    int dummy;
} GIOFuncs;

typedef int gboolean;
#define TRUE 1
#define FALSE 0
#define SSL_FILETYPE_PEM 1
#define SSL_MODE_ENABLE_PARTIAL_WRITE 0x00000001
#define SSL_MODE_ACCEPT_MOVING_WRITE_BUFFER 0x00000002

#define g_return_val_if_fail(expr, val) do { if (!(expr)) return (val); } while (0)
#define g_error(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define g_warning(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define g_free(ptr) free(ptr)
#define g_new0(struct_type, n) calloc(n, sizeof(struct_type))

typedef struct {
    GIOChannel channel;
    int fd;
    GIOChannel *giochan;
    SSL *ssl;
    SSL_CTX *ctx;
    gboolean verify;
    const char *hostname;
} GIOSSLChannel;

static SSL_CTX* SSL_CTX_new(void* method) { return NULL; }
static void* SSLv23_client_method(void) { return NULL; }
static int SSL_CTX_use_certificate_file(SSL_CTX* ctx, const char* file, int type) { return 0; }
static int SSL_CTX_use_PrivateKey_file(SSL_CTX* ctx, const char* file, int type) { return 0; }
static int SSL_CTX_check_private_key(SSL_CTX* ctx) { return 0; }
static int SSL_CTX_load_verify_locations(SSL_CTX* ctx, const char* cafile, const char* capath) { return 0; }
static void SSL_CTX_free(SSL_CTX* ctx) {}
static SSL* SSL_new(SSL_CTX* ctx) { return NULL; }
static int SSL_set_fd(SSL* ssl, int fd) { return 0; }
static void SSL_free(SSL* ssl) {}
static void SSL_set_mode(SSL* ssl, int mode) {}

static SSL_CTX *ssl_ctx = NULL;
static GIOFuncs irssi_ssl_channel_funcs;

static int g_io_channel_unix_get_fd(GIOChannel *handle) { return 0; }
static void g_io_channel_init(GIOChannel *channel) {}
static gboolean irssi_ssl_init(void) { return FALSE; }
static char *convert_home(const char *path) { return NULL; }
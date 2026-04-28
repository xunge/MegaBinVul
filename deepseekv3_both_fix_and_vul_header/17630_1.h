#include <stdbool.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#define IS_ENABLED(x) 0
#define CONFIG_NET_IPV6 0
#define CONFIG_NET_IPV4 0
#define CONFIG_UPDATEHUB_DTLS 0
#define TLS_PEER_VERIFY_REQUIRED 1
#define TLS_PEER_VERIFY_NONE 0
#define CA_CERTIFICATE_TAG 0
#define UPDATEHUB_SERVER ""
#define LOG_ERR(x)
#define K_SECONDS(x) (x)
#define IPPROTO_DTLS_1_2 256
#define SOL_TLS 282
#define TLS_SEC_TAG_LIST 1
#define TLS_PEER_VERIFY 2

typedef int sec_tag_t;

struct {
    int sock;
} ctx;

static void prepare_fds(void);
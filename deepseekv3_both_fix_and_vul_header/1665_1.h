#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef int ogs_socket_t;
#define INVALID_SOCKET (-1)

struct ogs_sockaddr_s {
    sa_family_t sa_family;
    char sa_data[14];
};
typedef struct ogs_sockaddr_s ogs_sockaddr_t;

struct ogs_pkbuf_s {
    void *data;
    size_t len;
};
typedef struct ogs_pkbuf_s ogs_pkbuf_t;

struct ogs_pfcp_node_s {
    void *sock;
};
typedef struct ogs_pfcp_node_s ogs_pfcp_node_t;

struct ogs_pfcp_header_s {
    uint8_t version;
    uint8_t flags;
    uint8_t type;
    uint16_t length;
    uint32_t sqn_only;
};
typedef struct ogs_pfcp_header_s ogs_pfcp_header_t;

struct sgwc_event_s {
    ogs_pfcp_node_t *pfcp_node;
    ogs_pkbuf_t *pkbuf;
};
typedef struct sgwc_event_s sgwc_event_t;

#define OGS_MAX_SDU_LEN 8192
#define OGS_PFCP_VERSION 1
#define OGS_PFCP_VERSION_NOT_SUPPORTED_RESPONSE_TYPE 0
#define OGS_LOG_ERROR 1
#define OGS_OK 0
#define SGWC_EVT_SXA_MESSAGE 0

extern int ogs_socket_errno;

extern ogs_pkbuf_t *ogs_pkbuf_alloc(void *a, size_t size);
extern void ogs_pkbuf_put(ogs_pkbuf_t *pkbuf, size_t size);
extern void ogs_pkbuf_free(ogs_pkbuf_t *pkbuf);
extern void ogs_pkbuf_trim(ogs_pkbuf_t *pkbuf, size_t size);
extern ssize_t ogs_recvfrom(ogs_socket_t fd, void *buf, size_t len, int flags, ogs_sockaddr_t *from);
extern ssize_t ogs_sendto(ogs_socket_t fd, const void *buf, size_t len, int flags, const ogs_sockaddr_t *to);
extern void ogs_log_message(int level, int err, const char *format, ...);
extern void ogs_error(const char *format, ...);
extern void ogs_assert(int expr);
extern sgwc_event_t *sgwc_event_new(int type);
extern void sgwc_event_free(sgwc_event_t *e);
extern ogs_pfcp_node_t *ogs_pfcp_node_find(void *list, ogs_sockaddr_t *addr);
extern ogs_pfcp_node_t *ogs_pfcp_node_add(void *list, ogs_sockaddr_t *addr);
extern void pfcp_node_fsm_init(ogs_pfcp_node_t *node, bool init);
extern int ogs_queue_push(void *queue, void *item);
extern struct {
    void *queue;
} *ogs_app();
extern struct {
    void *pfcp_peer_list;
} *ogs_pfcp_self();
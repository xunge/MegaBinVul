#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <endian.h>

#define OGS_MAX_SDU_LEN 8192
#define OGS_PFCP_VERSION 1
#define OGS_PFCP_VERSION_NOT_SUPPORTED_RESPONSE_TYPE 0
#define OGS_OK 0
#define OGS_LOG_ERROR 1
#define SGWC_EVT_SXA_MESSAGE 1
#define INVALID_SOCKET (-1)

typedef int ogs_socket_t;
typedef uint16_t ogs_pfcp_type_t;

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
    void *pfcp_peer_list;
};
typedef struct ogs_pfcp_node_s ogs_pfcp_node_t;

struct ogs_pfcp_header_s {
    uint8_t flags;
    ogs_pfcp_type_t type;
    uint16_t length;
    uint32_t sqn_only;
    uint8_t version;
};
typedef struct ogs_pfcp_header_s ogs_pfcp_header_t;

struct sgwc_event_s {
    ogs_pfcp_node_t *pfcp_node;
    ogs_pkbuf_t *pkbuf;
};
typedef struct sgwc_event_s sgwc_event_t;

struct ogs_app_s {
    void *queue;
};
typedef struct ogs_app_s ogs_app_t;

struct ogs_pfcp_self_s {
    ogs_pfcp_node_t pfcp_peer_list;
};
typedef struct ogs_pfcp_self_s ogs_pfcp_self_t;

extern ogs_app_t *ogs_app(void);
extern ogs_pkbuf_t *ogs_pkbuf_alloc(void *, size_t);
extern void ogs_pkbuf_free(ogs_pkbuf_t *);
extern void ogs_pkbuf_put(ogs_pkbuf_t *, size_t);
extern void ogs_pkbuf_trim(ogs_pkbuf_t *, size_t);
extern ssize_t ogs_recvfrom(ogs_socket_t, void *, size_t, int, ogs_sockaddr_t *);
extern ssize_t ogs_sendto(ogs_socket_t, const void *, size_t, int, const ogs_sockaddr_t *);
extern void ogs_log_message(int, int, const char *);
extern void ogs_error(const char *, ...);
extern void ogs_assert(int expr);
extern ogs_pfcp_node_t *ogs_pfcp_node_find(void *, ogs_sockaddr_t *);
extern ogs_pfcp_node_t *ogs_pfcp_node_add(void *, ogs_sockaddr_t *);
extern void pfcp_node_fsm_init(ogs_pfcp_node_t *, bool);
extern sgwc_event_t *sgwc_event_new(int);
extern void sgwc_event_free(sgwc_event_t *);
extern int ogs_queue_push(void *, sgwc_event_t *);
extern ogs_pfcp_self_t *ogs_pfcp_self(void);

#define ogs_socket_errno errno
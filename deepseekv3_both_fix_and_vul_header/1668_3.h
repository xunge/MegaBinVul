#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <endian.h>

#define INVALID_SOCKET (-1)
#define OGS_MAX_SDU_LEN 8192
#define OGS_PFCP_VERSION 1
#define OGS_PFCP_VERSION_NOT_SUPPORTED_RESPONSE_TYPE 0
#define OGS_OK 0
#define OGS_LOG_ERROR 1

typedef int ogs_socket_t;
typedef uint16_t ogs_pfcp_type_t;

struct ogs_sockaddr_t {
    sa_family_t sa_family;
    char sa_data[14];
};
typedef struct ogs_sockaddr_t ogs_sockaddr_t;

struct ogs_pkbuf_t {
    void *data;
    size_t len;
};
typedef struct ogs_pkbuf_t ogs_pkbuf_t;

struct ogs_pfcp_header_t {
    uint8_t version;
    uint8_t flags;
    ogs_pfcp_type_t type;
    uint16_t length;
    uint32_t sqn_only;
};
typedef struct ogs_pfcp_header_t ogs_pfcp_header_t;

struct ogs_pfcp_node_t {
    void *sock;
};
typedef struct ogs_pfcp_node_t ogs_pfcp_node_t;

struct ogs_pfcp_self_t {
    struct {
        void *pfcp_peer_list;
    };
};
typedef struct ogs_pfcp_self_t ogs_pfcp_self_t;

struct ogs_app_t {
    struct ogs_queue_t *queue;
};
typedef struct ogs_app_t ogs_app_t;

struct ogs_queue_t {
    void *dummy;
};
typedef struct ogs_queue_t ogs_queue_t;

struct sgwc_event_t {
    ogs_pfcp_node_t *pfcp_node;
    ogs_pkbuf_t *pkbuf;
};
typedef struct sgwc_event_t sgwc_event_t;

enum sgwc_event_e {
    SGWC_EVT_SXA_MESSAGE
};

extern int ogs_socket_errno;
extern ogs_pfcp_self_t *ogs_pfcp_self(void);
extern ogs_app_t *ogs_app(void);
extern ogs_pkbuf_t *ogs_pkbuf_alloc(void *, int);
extern void ogs_pkbuf_put(ogs_pkbuf_t *, int);
extern void ogs_pkbuf_trim(ogs_pkbuf_t *, int);
extern void ogs_pkbuf_free(ogs_pkbuf_t *);
extern ssize_t ogs_recvfrom(int, void *, size_t, int, ogs_sockaddr_t *);
extern int ogs_sendto(int, const void *, size_t, int, const ogs_sockaddr_t *);
extern void ogs_assert(int);
extern void ogs_error(const char *, ...);
extern void ogs_log_message(int, int, const char *);
extern sgwc_event_t *sgwc_event_new(enum sgwc_event_e);
extern void sgwc_event_free(sgwc_event_t *);
extern ogs_pfcp_node_t *ogs_pfcp_node_find(void *, ogs_sockaddr_t *);
extern ogs_pfcp_node_t *ogs_pfcp_node_add(void *, ogs_sockaddr_t *);
extern void pfcp_node_fsm_init(ogs_pfcp_node_t *, bool);
extern int ogs_queue_push(ogs_queue_t *, sgwc_event_t *);
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <endian.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef int ogs_socket_t;
#define INVALID_SOCKET (-1)

typedef struct {
    void *data;
    size_t len;
} ogs_pkbuf_t;

typedef struct {
    uint8_t version;
    uint8_t type;
    uint8_t flags;
    uint32_t teid;
} ogs_gtp_header_t;

typedef struct {
    uint8_t type;
    uint8_t pdu_type;
    uint8_t qos_flow_identifier;
} ogs_gtp_extension_header_t;

typedef struct {
    struct {
        bool error_indication_report;
        bool downlink_data_report;
    } type;
    struct {
        uint16_t pdr_id;
        uint8_t qfi;
    } downlink_data;
} ogs_pfcp_user_plane_report_t;

typedef struct ogs_pfcp_pdr_s {
    void *sess;
    uint16_t id;
    uint8_t src_if;
    uint8_t qfi;
    struct {
        uint32_t teid;
    } f_teid;
    struct {
        void *head;
    } rule_list;
    struct ogs_pfcp_pdr_s *next;
} ogs_pfcp_pdr_t;

typedef struct {
    void *sess;
} ogs_pfcp_far_t;

typedef struct {
    struct {
        int type;
    } obj;
    struct {
        ogs_pfcp_pdr_t *head;
    } pdr_list;
} ogs_pfcp_sess_t;

typedef struct {
    int type;
    union {
        ogs_pfcp_pdr_t pdr;
        ogs_pfcp_sess_t sess;
    };
} ogs_pfcp_object_t;

typedef struct sockaddr ogs_sockaddr_t;

typedef struct {
    int dummy;
} sgwu_sess_t;

#define OGS_ADDRSTRLEN INET6_ADDRSTRLEN
#define OGS_MAX_PKT_LEN 65535
#define OGS_GTP_VERSION_1 1
#define OGS_GTPU_MSGTYPE_ECHO_REQ 1
#define OGS_GTPU_MSGTYPE_END_MARKER 254
#define OGS_GTPU_MSGTYPE_ERR_IND 26
#define OGS_GTPU_MSGTYPE_GPDU 255
#define OGS_GTPV1U_HEADER_LEN 8
#define OGS_GTP_EXTENSION_HEADER_TYPE_PDU_SESSION_CONTAINER 0x85
#define OGS_GTP_EXTENSION_HEADER_PDU_TYPE_UL_PDU_SESSION_INFORMATION 0
#define OGS_GTPU_FLAGS_E 0x04
#define OGS_PFCP_INTERFACE_ACCESS 0
#define OGS_PFCP_INTERFACE_CP_FUNCTION 1
#define OGS_PFCP_OBJ_PDR_TYPE 0
#define OGS_PFCP_OBJ_SESS_TYPE 1
#define OGS_OK 0
#define OGS_LOG_ERROR 1
#define OGS_LOG_DEBUG 2

#define ogs_assert(expr) ((void)0)
#define ogs_expect(expr) ((void)0)
#define ogs_fatal(fmt, ...) ((void)0)
#define ogs_assert_if_reached() ((void)0)
#define ogs_log_message(level, err, msg) ((void)0)
#define ogs_error(fmt, ...) ((void)0)
#define ogs_debug(fmt, ...) ((void)0)
#define ogs_log_hexdump(level, data, len) ((void)0)
#define SGWU_SESS(ptr) ((sgwu_sess_t*)(ptr))
#define ogs_list_for_each(list, item) for((item) = (list)->head; (item); (item) = (item)->next)
#define ogs_list_first(list) ((list)->head)

static inline void *ogs_pfcp_pdr_rule_find_by_packet(ogs_pfcp_pdr_t *pdr, ogs_pkbuf_t *pkbuf) {
    return NULL;
}

extern ogs_pkbuf_t *packet_pool;
extern ogs_pkbuf_t *ogs_pkbuf_alloc(void *pool, size_t size);
extern void ogs_pkbuf_put(ogs_pkbuf_t *pkbuf, size_t size);
extern void ogs_pkbuf_trim(ogs_pkbuf_t *pkbuf, size_t size);
extern int ogs_pkbuf_pull(ogs_pkbuf_t *pkbuf, size_t size);
extern void ogs_pkbuf_free(ogs_pkbuf_t *pkbuf);
extern ssize_t ogs_recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr);
extern ssize_t ogs_sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr);
extern char *OGS_ADDR(const ogs_sockaddr_t *addr, char *buf);
extern int ogs_gtpu_header_len(ogs_pkbuf_t *pkbuf);
extern ogs_pkbuf_t *ogs_gtp_handle_echo_req(ogs_pkbuf_t *pkbuf);
extern ogs_pfcp_far_t *ogs_pfcp_far_find_by_error_indication(ogs_pkbuf_t *pkbuf);
extern bool ogs_pfcp_up_handle_error_indication(ogs_pfcp_far_t *far, ogs_pfcp_user_plane_report_t *report);
extern ogs_pfcp_object_t *ogs_pfcp_object_find_by_teid(uint32_t teid);
extern bool ogs_pfcp_up_handle_pdr(ogs_pfcp_pdr_t *pdr, ogs_pkbuf_t *pkbuf, ogs_pfcp_user_plane_report_t *report);
extern int sgwu_pfcp_send_session_report_request(sgwu_sess_t *sess, ogs_pfcp_user_plane_report_t *report);
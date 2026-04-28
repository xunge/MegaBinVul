#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <endian.h>
#include <unistd.h>
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
    uint32_t len;
};
typedef struct ogs_pkbuf_s ogs_pkbuf_t;

struct ogs_gtp_header_s {
    uint8_t flags;
    uint8_t type;
    uint16_t length;
    uint32_t teid;
    uint8_t version;
};
typedef struct ogs_gtp_header_s ogs_gtp_header_t;

struct ogs_gtp_extension_header_s {
    uint8_t type;
    uint8_t length;
    uint8_t pdu_type;
    uint8_t qos_flow_identifier;
    uint8_t next_type;
};
typedef struct ogs_gtp_extension_header_s ogs_gtp_extension_header_t;

struct ogs_pfcp_user_plane_report_s {
    struct {
        bool error_indication_report;
        bool downlink_data_report;
    } type;
    struct {
        uint16_t pdr_id;
        uint8_t qfi;
    } downlink_data;
};
typedef struct ogs_pfcp_user_plane_report_s ogs_pfcp_user_plane_report_t;

struct ogs_pfcp_far_s {
    struct ogs_pfcp_sess_s *sess;
};
typedef struct ogs_pfcp_far_s ogs_pfcp_far_t;

struct ogs_pfcp_rule_s {
    struct ogs_pfcp_rule_s *next;
};
typedef struct ogs_pfcp_rule_s ogs_pfcp_rule_t;

struct ogs_pfcp_pdr_s {
    uint16_t id;
    uint8_t qfi;
    uint8_t src_if;
    struct {
        uint32_t teid;
    } f_teid;
    struct ogs_pfcp_sess_s *sess;
    struct {
        ogs_pfcp_rule_t *first;
    } rule_list;
    struct ogs_pfcp_pdr_s *next;
};
typedef struct ogs_pfcp_pdr_s ogs_pfcp_pdr_t;

struct ogs_pfcp_sess_s {
    struct {
        ogs_pfcp_pdr_t *first;
    } pdr_list;
    struct {
        uint8_t type;
    } obj;
};
typedef struct ogs_pfcp_sess_s ogs_pfcp_sess_t;

struct ogs_pfcp_object_s {
    uint8_t type;
    union {
        ogs_pfcp_pdr_t pdr;
        ogs_pfcp_sess_t sess;
    };
};
typedef struct ogs_pfcp_object_s ogs_pfcp_object_t;

typedef struct sgwu_sess_s sgwu_sess_t;

#define OGS_ADDRSTRLEN 64
#define OGS_MAX_PKT_LEN 8192
#define OGS_GTP_VERSION_1 1
#define OGS_GTPU_MSGTYPE_ECHO_REQ 1
#define OGS_GTPU_MSGTYPE_END_MARKER 254
#define OGS_GTPU_MSGTYPE_ERR_IND 26
#define OGS_GTPU_MSGTYPE_GPDU 255
#define OGS_GTPV1U_HEADER_LEN 8
#define OGS_GTP_EXTENSION_HEADER_TYPE_PDU_SESSION_CONTAINER 0x85
#define OGS_GTP_EXTENSION_HEADER_PDU_TYPE_UL_PDU_SESSION_INFORMATION 0
#define OGS_PFCP_INTERFACE_ACCESS 0
#define OGS_PFCP_INTERFACE_CP_FUNCTION 1
#define OGS_PFCP_OBJ_PDR_TYPE 1
#define OGS_PFCP_OBJ_SESS_TYPE 2
#define OGS_OK 0
#define OGS_LOG_ERROR 1
#define OGS_GTPU_FLAGS_E 0x04

extern int ogs_socket_errno;
extern void *packet_pool;

#define OGS_ADDR(addr, buf) inet_ntop(AF_INET, &((struct sockaddr_in*)addr)->sin_addr, buf, OGS_ADDRSTRLEN)
#define SGWU_SESS(sess) ((sgwu_sess_t *)(sess))
#define ogs_list_for_each(list, item) for((item) = (list)->first; (item); (item) = (item)->next)
#define ogs_list_first(list) ((list)->first)

void ogs_assert(bool condition);
ogs_pkbuf_t *ogs_pkbuf_alloc(void *pool, uint32_t size);
void ogs_pkbuf_put(ogs_pkbuf_t *pkbuf, uint32_t size);
ssize_t ogs_recvfrom(ogs_socket_t fd, void *buf, size_t len, int flags, ogs_sockaddr_t *from);
void ogs_log_message(int level, int errnum, const char *format, ...);
void ogs_pkbuf_trim(ogs_pkbuf_t *pkbuf, uint32_t size);
void ogs_error(const char *format, ...);
void ogs_log_hexdump(int level, const void *data, uint32_t len);
void ogs_debug(const char *format, ...);
ogs_pkbuf_t *ogs_gtp_handle_echo_req(ogs_pkbuf_t *pkbuf);
void ogs_expect(void *ptr);
ssize_t ogs_sendto(ogs_socket_t fd, const void *buf, size_t len, int flags, const ogs_sockaddr_t *to);
void ogs_pkbuf_free(ogs_pkbuf_t *pkbuf);
int ogs_gtpu_header_len(ogs_pkbuf_t *pkbuf);
ogs_pkbuf_t *ogs_pkbuf_pull(ogs_pkbuf_t *pkbuf, uint32_t size);
ogs_pfcp_far_t *ogs_pfcp_far_find_by_error_indication(ogs_pkbuf_t *pkbuf);
bool ogs_pfcp_up_handle_error_indication(ogs_pfcp_far_t *far, ogs_pfcp_user_plane_report_t *report);
int sgwu_pfcp_send_session_report_request(sgwu_sess_t *sess, ogs_pfcp_user_plane_report_t *report);
void ogs_fatal(const char *format, ...);
void ogs_assert_if_reached();
ogs_pfcp_object_t *ogs_pfcp_object_find_by_teid(uint32_t teid);
bool ogs_pfcp_up_handle_pdr(ogs_pfcp_pdr_t *pdr, ogs_pkbuf_t *pkbuf, ogs_pfcp_user_plane_report_t *report);
ogs_pfcp_rule_t *ogs_pfcp_pdr_rule_find_by_packet(ogs_pfcp_pdr_t *pdr, ogs_pkbuf_t *pkbuf);
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef struct ogs_sbi_stream_s ogs_sbi_stream_t;
typedef struct ogs_sbi_message_s {
    struct {
        struct {
            char *component[4];
        } resource;
    } h;
    struct OpenAPI_n1_n2_message_transfer_req_data_s *N1N2MessageTransferReqData;
    struct OpenAPI_n1_n2_message_transfer_rsp_data_s *N1N2MessageTransferRspData;
    struct {
        char *location;
    } http;
} ogs_sbi_message_t;

typedef struct ogs_sbi_response_s ogs_sbi_response_t;
typedef struct ogs_sbi_server_s ogs_sbi_server_t;
typedef struct ogs_sbi_header_s {
    struct {
        char *name;
    } service;
    struct {
        char *version;
    } api;
    struct {
        char *component[4];
    } resource;
} ogs_sbi_header_t;
typedef struct ogs_sbi_client_s ogs_sbi_client_t;
typedef struct ogs_sockaddr_s ogs_sockaddr_t;
typedef struct ogs_pkbuf_s ogs_pkbuf_t;

typedef struct amf_ue_s {
    char *supi;
    struct ran_ue_s *ran_ue;
} amf_ue_t;

typedef struct amf_sess_s {
    uint8_t psi;
    char *sm_context_ref;
    ogs_pkbuf_t *pdu_session_establishment_accept;
    struct {
        ogs_sbi_client_t *client;
    } paging;
} amf_sess_t;

typedef struct ran_ue_s {
    bool initial_context_setup_request_sent;
} ran_ue_t;

typedef enum {
    OGS_NAS_PDU_SESSION_IDENTITY_UNASSIGNED,
} ogs_nas_pdu_session_identity_t;

typedef enum {
    OGS_SBI_HTTP_STATUS_OK,
    OGS_SBI_HTTP_STATUS_ACCEPTED,
} ogs_sbi_http_status_e;

typedef enum {
    OGS_ERROR,
    OGS_OK,
} ogs_error_e;

typedef enum {
    OGS_NAS_PAYLOAD_CONTAINER_N1_SM_INFORMATION,
    OGS_NAS_5GS_PDU_SESSION_MODIFICATION_COMMAND
} ogs_nas_payload_container_type_e;

typedef enum {
    OpenAPI_n1_n2_message_transfer_cause_N1_N2_TRANSFER_INITIATED,
    OpenAPI_n1_n2_message_transfer_cause_ATTEMPTING_TO_REACH_UE,
    OpenAPI_n1_n2_message_transfer_cause_N1_MSG_NOT_TRANSFERRED,
} OpenAPI_n1_n2_message_transfer_cause_e;

typedef enum {
    OpenAPI_ngap_ie_type_NULL,
    OpenAPI_ngap_ie_type_PDU_RES_SETUP_REQ,
    OpenAPI_ngap_ie_type_PDU_RES_MOD_REQ,
    OpenAPI_ngap_ie_type_PDU_RES_REL_CMD,
} OpenAPI_ngap_ie_type_e;

typedef struct OpenAPI_ref_to_binary_data_s {
    char *content_id;
} OpenAPI_ref_to_binary_data_t;

typedef struct OpenAPI_n1_message_container_s {
    OpenAPI_ref_to_binary_data_t *n1_message_content;
} OpenAPI_n1_message_container_t;

typedef struct OpenAPI_n2_info_content_s {
    OpenAPI_ngap_ie_type_e ngap_ie_type;
    OpenAPI_ref_to_binary_data_t *ngap_data;
} OpenAPI_n2_info_content_t;

typedef struct OpenAPI_n2_sm_information_s {
    OpenAPI_n2_info_content_t *n2_info_content;
} OpenAPI_n2_sm_information_t;

typedef struct OpenAPI_n2_info_container_s {
    OpenAPI_n2_sm_information_t *sm_info;
} OpenAPI_n2_info_container_t;

typedef struct OpenAPI_n1_n2_message_transfer_req_data_s {
    bool is_pdu_session_id;
    uint8_t pdu_session_id;
    bool is_skip_ind;
    bool skip_ind;
    char *n1n2_failure_txf_notif_uri;
    OpenAPI_n1_message_container_t *n1_message_container;
    OpenAPI_n2_info_container_t *n2_info_container;
} OpenAPI_n1_n2_message_transfer_req_data_t;

typedef struct OpenAPI_n1_n2_message_transfer_rsp_data_s {
    OpenAPI_n1_n2_message_transfer_cause_e cause;
} OpenAPI_n1_n2_message_transfer_rsp_data_t;

#define ogs_assert(expr)
#define ogs_error(fmt, ...)
#define ogs_fatal(fmt, ...)
#define ogs_assert_if_reached()

#define CM_IDLE(ue) (0)
#define CM_CONNECTED(ue) (1)
#define SESSION_CONTEXT_IN_SMF(sess) (0)

#define AMF_SESS_STORE_PAGING_INFO(sess, loc, uri)
#define AMF_SESS_STORE_N2_TRANSFER(sess, type, buf)
#define AMF_SESS_STORE_5GSM_MESSAGE(sess, cmd, n1buf, n2buf)

#define OGS_SETUP_SBI_CLIENT(paging, client)

#define OGS_SBI_SERVICE_NAME_NAMF_COMM "namf-comm"
#define OGS_SBI_API_V1 "v1"
#define OGS_SBI_RESOURCE_NAME_UE_CONTEXTS "ue-contexts"
#define OGS_SBI_RESOURCE_NAME_N1_N2_MESSAGES "n1-n2-messages"

amf_ue_t *amf_ue_find_by_supi(char *supi);
amf_sess_t *amf_sess_find_by_psi(amf_ue_t *amf_ue, uint8_t psi);
ogs_pkbuf_t *ogs_sbi_find_part_by_content_id(ogs_sbi_message_t *recvmsg, char *content_id);
ogs_pkbuf_t *ogs_pkbuf_copy(ogs_pkbuf_t *pkbuf);
void ogs_pkbuf_free(ogs_pkbuf_t *pkbuf);
ogs_pkbuf_t *gmm_build_dl_nas_transport(amf_sess_t *sess, int type, ogs_pkbuf_t *n1buf, int dummy1, int dummy2);
ogs_pkbuf_t *ngap_sess_build_pdu_session_resource_setup_request(amf_sess_t *sess, ogs_pkbuf_t *gmmbuf, ogs_pkbuf_t *n2buf);
ogs_pkbuf_t *ngap_sess_build_initial_context_setup_request(amf_sess_t *sess, ogs_pkbuf_t *gmmbuf, ogs_pkbuf_t *n2buf);
int nas_5gs_send_to_gnb(amf_ue_t *amf_ue, ogs_pkbuf_t *ngapbuf);
ogs_sockaddr_t *ogs_sbi_getaddr_from_uri(char *uri);
ogs_sbi_client_t *ogs_sbi_client_find(ogs_sockaddr_t *addr);
ogs_sbi_client_t *ogs_sbi_client_add(ogs_sockaddr_t *addr);
void ogs_freeaddrinfo(ogs_sockaddr_t *addr);
ogs_sbi_server_t *ogs_sbi_server_from_stream(ogs_sbi_stream_t *stream);
char *ogs_sbi_server_uri(ogs_sbi_server_t *server, ogs_sbi_header_t *header);
int ngap_send_paging(amf_ue_t *amf_ue);
int ngap_send_pdu_resource_setup_request(amf_sess_t *sess, ogs_pkbuf_t *n2buf);
ogs_pkbuf_t *ngap_build_pdu_session_resource_modify_request(amf_sess_t *sess, ogs_pkbuf_t *gmmbuf, ogs_pkbuf_t *n2buf);
ogs_pkbuf_t *ngap_build_pdu_session_resource_release_command(amf_sess_t *sess, void *null, ogs_pkbuf_t *n2buf);
ogs_sbi_response_t *ogs_sbi_build_response(ogs_sbi_message_t *sendmsg, int status);
bool ogs_sbi_server_send_response(ogs_sbi_stream_t *stream, ogs_sbi_response_t *response);
void ogs_free(void *ptr);
ran_ue_t *ran_ue_cycle(ran_ue_t *ran_ue);
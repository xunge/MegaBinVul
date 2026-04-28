#include <stddef.h>
#include <stdint.h>

typedef struct ogs_fsm_s {
    int dummy;
} ogs_fsm_t;

typedef struct amf_event_s {
    struct {
        int id;
        int timer_id;
        struct {
            void *message;
        } sbi;
    } h;
    struct {
        void *message;
        int type;
        int code;
    } nas;
    struct {
        int code;
    } ngap;
    void *sess;
    void *amf_ue;
} amf_event_t;

typedef int ogs_nas_5gmm_cause_t;

typedef struct amf_ue_s {
    char *suci;
    char *supi;
    struct {
        int retry_count;
    } t3560;
    ogs_fsm_t sm;
} amf_ue_t;

typedef struct amf_sess_s {
    amf_ue_t *amf_ue;
} amf_sess_t;

typedef struct ogs_nas_security_header_type_s {
    int type;
} ogs_nas_security_header_type_t;

typedef struct ogs_nas_5gs_message_s {
    struct {
        struct {
            int message_type;
        } h;
        struct {
            int gmm_cause;
        } gmm_status;
        void *authentication_response;
        struct {
            int gmm_cause;
            struct {
                int length;
                char auts[14];
            } authentication_failure_parameter;
        } authentication_failure;
        void *registration_request;
        void *deregistration_request_from_ue;
    } gmm;
} ogs_nas_5gs_message_t;

typedef struct ogs_nas_5gs_authentication_failure_s {
    int gmm_cause;
    struct {
        int length;
        char auts[14];
    } authentication_failure_parameter;
} ogs_nas_5gs_authentication_failure_t;

typedef struct ogs_nas_authentication_failure_parameter_s {
    int length;
    char auts[14];
} ogs_nas_authentication_failure_parameter_t;

typedef struct ogs_sbi_message_s {
    struct {
        char *name;
        char *method;
        char *component[2];
    } h;
    int res_status;
} ogs_sbi_message_t;

typedef struct amf_timer_cfg_s {
    int max_count;
} amf_timer_cfg_t;

#define OGS_OK 0
#define OGS_ERROR -1
#define OGS_AUTS_LEN 14
#define OGS_FSM_ENTRY_SIG 1
#define OGS_FSM_EXIT_SIG 2
#define AMF_EVENT_5GMM_MESSAGE 3
#define AMF_EVENT_5GMM_TIMER 4
#define OGS_EVENT_SBI_CLIENT 5
#define OGS_SBI_HTTP_METHOD_POST "POST"
#define OGS_SBI_HTTP_METHOD_PUT "PUT"
#define OGS_SBI_HTTP_STATUS_CREATED 201
#define OGS_SBI_HTTP_STATUS_OK 200
#define OGS_SBI_HTTP_STATUS_NOT_FOUND 404
#define OGS_SBI_HTTP_STATUS_NO_CONTENT 204
#define OGS_SBI_SERVICE_NAME_NAUSF_AUTH "nausf-auth"
#define OGS_SBI_SERVICE_NAME_NUDM_UECM "nudm-uecm"
#define OGS_SBI_RESOURCE_NAME_UE_AUTHENTICATIONS "ue-authentications"
#define OGS_SBI_RESOURCE_NAME_REGISTRATIONS "registrations"
#define OGS_SBI_SERVICE_TYPE_NAUSF_AUTH 1
#define OGS_NAS_5GS_AUTHENTICATION_RESPONSE 1
#define OGS_NAS_5GS_AUTHENTICATION_FAILURE 2
#define OGS_NAS_5GS_REGISTRATION_REQUEST 3
#define OGS_NAS_5GS_5GMM_STATUS 4
#define OGS_NAS_5GS_DEREGISTRATION_REQUEST_FROM_UE 5
#define OGS_5GMM_CAUSE_MAC_FAILURE 1
#define OGS_5GMM_CAUSE_NON_5G_AUTHENTICATION_UNACCEPTABLE 2
#define OGS_5GMM_CAUSE_NGKSI_ALREADY_IN_USE 3
#define OGS_5GMM_CAUSE_SYNCH_FAILURE 4
#define OGS_5GMM_CAUSE_REQUEST_ACCEPTED 5
#define AMF_TIMER_T3560 1
#define AMF_METR_CTR_AMF_AUTH_FAIL 1

#define ogs_assert(expr) ((void)0)
#define ogs_expect(expr) ((void)0)
#define ogs_debug(fmt, ...) ((void)0)
#define ogs_warn(fmt, ...) ((void)0)
#define ogs_error(fmt, ...) ((void)0)
#define ogs_assert_if_reached() ((void)0)

#define SWITCH(x) 
#define CASE(x) 
#define DEFAULT 
#define END 

#define CLEAR_AMF_UE_TIMER(timer) ((void)0)
#define OGS_FSM_TRAN(state, next_state) ((void)0)

extern void amf_sm_debug(amf_event_t *e);
extern int gmm_handle_authentication_response(amf_ue_t *amf_ue, void *resp);
extern int nas_5gs_send_authentication_reject(amf_ue_t *amf_ue);
extern int amf_ue_sbi_discover_and_send(int type, void *data, void (*build)(void), amf_ue_t *amf_ue, int flags, void *param);
extern int nas_5gs_send_gmm_reject_from_sbi(amf_ue_t *amf_ue, int status);
extern int amf_nausf_auth_handle_authenticate(amf_ue_t *amf_ue, ogs_sbi_message_t *message);
extern int amf_nausf_auth_handle_authenticate_confirmation(amf_ue_t *amf_ue, ogs_sbi_message_t *message);
extern int nas_5gs_send_authentication_request(amf_ue_t *amf_ue);
extern ogs_nas_5gmm_cause_t gmm_handle_registration_request(amf_ue_t *amf_ue, ogs_nas_security_header_type_t h, int code, void *req);
extern int nas_5gs_send_registration_reject(amf_ue_t *amf_ue, ogs_nas_5gmm_cause_t cause);
extern void gmm_handle_deregistration_request(amf_ue_t *amf_ue, void *req);
extern const char *amf_event_get_name(amf_event_t *e);
extern const char *amf_timer_get_name(int timer_id);
extern amf_timer_cfg_t *amf_timer_cfg(int timer_id);
extern void amf_nausf_auth_build_authenticate(void);
extern void amf_metrics_inst_by_cause_add(int cause, int metric, int value);

extern ogs_fsm_t gmm_state_exception;
extern ogs_fsm_t gmm_state_de_registered;
extern ogs_fsm_t gmm_state_security_mode;
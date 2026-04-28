#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define BD_ADDR_LEN 6
typedef uint8_t BD_ADDR[BD_ADDR_LEN];
typedef uint8_t UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;

#define PIN_CODE_LEN 16
#define BTM_PAIR_STATE_WAIT_LOCAL_PIN 0
#define BTM_PAIR_STATE_IDLE 1
#define BTM_PAIR_STATE_WAIT_AUTH_COMPLETE 2
#define BTM_PAIR_STATE_WAIT_PIN_REQ 3

#define BTM_PAIR_FLAGS_PEER_STARTED_DD 0x01
#define BTM_PAIR_FLAGS_WE_STARTED_DD 0x02
#define BTM_PAIR_FLAGS_DISC_WHEN_DONE 0x04
#define BTM_PAIR_FLAGS_REJECTED_CONNECT 0x08

#define BTM_ILLEGAL_VALUE 1
#define BTM_SUCCESS 0
#define BTM_CMD_STARTED 1

#define BTM_SEC_NONE 0
#define BTM_SEC_LINK_KEY_AUTHED 0x01
#define BTM_SEC_INVALID_HANDLE 0xFFFF

#define BTM_SM4_CONN_PEND 0x01

#define HCI_ERR_HOST_REJECT_SECURITY 0x01
#define HCI_ERR_AUTH_FAILURE 0x05
#define HCI_SUCCESS 0x00

#define TRUE true
#define FALSE false

typedef struct {
    UINT8 pairing_state;
    UINT8 pairing_flags;
    BD_ADDR pairing_bda;
    UINT8 pin_code_len;
    UINT8 pin_code[PIN_CODE_LEN];
    UINT8 pin_code_len_saved;
    UINT8 acl_disc_reason;
    bool security_mode_changed;
    struct {
        void (*p_auth_complete_callback)(BD_ADDR, UINT8*, UINT8*, UINT8);
    } api;
} tBTM_CB;

typedef struct {
    BD_ADDR bd_addr;
    UINT8 dev_class[3];
    UINT8 sec_bd_name[248];
    UINT16 hci_handle;
    UINT8 sec_flags;
    UINT8 security_required;
    UINT8 trusted_mask[8];
    UINT8 sm4;
} tBTM_SEC_DEV_REC;

extern tBTM_CB btm_cb;

extern const char *btm_pair_state_descr(UINT8 state);
extern tBTM_SEC_DEV_REC *btm_find_dev(BD_ADDR bd_addr);
extern void btm_sec_change_pairing_state(UINT8 state);
extern UINT8 btm_sec_dd_create_conn(tBTM_SEC_DEV_REC *p_dev_rec);
extern void btsnd_hcic_pin_code_neg_reply(BD_ADDR bd_addr);
extern void btsnd_hcic_pin_code_req_reply(BD_ADDR bd_addr, UINT8 pin_len, UINT8 *p_pin);
extern void btsnd_hcic_write_auth_enable(bool enable);
extern void BTM_TRACE_API(const char *fmt, ...);
extern void BTM_TRACE_WARNING(const char *fmt, ...);
extern void BTM_TRACE_ERROR(const char *fmt, ...);
extern void BTM_TRACE_EVENT(const char *fmt, ...);

#define BTM_SEC_COPY_TRUSTED_DEVICE(src, dst) memcpy(dst, src, sizeof(UINT32[2]))
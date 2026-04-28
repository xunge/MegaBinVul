#include <stdint.h>
#include <string.h>

#define UINT8 uint8_t
#define BD_ADDR_LEN 6
#define DEV_CLASS_LEN 3
#define PIN_CODE_LEN 16
#define HCI_PAGE_SCAN_REP_MODE_R1 0x01
#define HCI_MANDATARY_PAGE_SCAN_MODE 0x00
#define HCI_PIN_TYPE_FIXED 0x00

typedef uint8_t PIN_CODE[PIN_CODE_LEN];

typedef enum {
    BTM_PAIR_STATE_IDLE,
    BTM_PAIR_STATE_WAIT_AUTH_COMPLETE,
    BTM_PAIR_STATE_WAIT_PIN_REQ,
    BTM_PAIR_STATE_WAIT_LOCAL_PIN
} tBTM_PAIRING_STATE;

typedef enum {
    BTM_SM4_KNOWN,
    BTM_SM4_UNKNOWN
} tBTM_SM4;

typedef struct {
    uint8_t pin_type;
    uint8_t pin_code_len;
    PIN_CODE pin_code;
} tBTM_CFG;

typedef struct {
    void (*p_pin_callback)(UINT8 *p_bda, uint8_t *dev_class, uint8_t *sec_bd_name);
} tBTM_API;

typedef struct {
    uint8_t bd_addr[BD_ADDR_LEN];
    uint8_t dev_class[DEV_CLASS_LEN];
    uint8_t sec_bd_name[248];
    uint32_t trusted_mask;
    uint8_t sec_flags;
    uint8_t sm4;
    uint8_t is_originator;
} tBTM_SEC_DEV_REC;

typedef struct {
    tBTM_PAIRING_STATE pairing_state;
    uint8_t pairing_bda[BD_ADDR_LEN];
    uint8_t pin_code_len;
    uint8_t pin_code_len_saved;
    PIN_CODE pin_code;
    uint8_t pairing_flags;
    uint8_t connecting_bda[BD_ADDR_LEN];
    uint8_t connecting_dc[DEV_CLASS_LEN];
    tBTM_CFG cfg;
    uint8_t pairing_disabled;
    tBTM_API api;
} tBTM_CB;

extern tBTM_CB btm_cb;

#define BTM_TRACE_EVENT(...)
#define BTM_TRACE_WARNING(...)
#define BTM_TRACE_ERROR(...)
#define BTM_PAIR_FLAGS_PEER_STARTED_DD 0x01
#define BTM_PAIR_FLAGS_PIN_REQD 0x02
#define BTM_COD_MAJOR_CLASS_MASK 0x1F
#define BTM_COD_MAJOR_PERIPHERAL 0x05
#define BTM_COD_MINOR_KEYBOARD 0x40
#define BTM_SEC_NAME_KNOWN 0x01
#define BTM_SEC_CLR_TRUSTED_DEVICE(mask) ((mask) = 0)

extern tBTM_SEC_DEV_REC *btm_find_or_alloc_dev(UINT8 *p_bda);
extern void btsnd_hcic_pin_code_neg_reply(UINT8 *p_bda);
extern void btsnd_hcic_pin_code_req_reply(UINT8 *p_bda, uint8_t len, PIN_CODE pin_code);
extern void btm_sec_change_pairing_state(tBTM_PAIRING_STATE state);
extern const char *btm_pair_state_descr(tBTM_PAIRING_STATE state);
extern uint8_t btsnd_hcic_rmt_name_req(uint8_t *bd_addr, uint8_t page_scan_rep_mode, uint8_t page_scan_mode, uint16_t clock_offset);
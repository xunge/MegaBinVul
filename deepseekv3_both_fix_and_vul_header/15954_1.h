#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define TRUE true
#define FALSE false
#define BT_DEVICE_TYPE_BREDR 0x00
#define BT_BOND_STATE_BONDING 0x01
#define BT_STATUS_SUCCESS 0x00
#define BTM_AUTH_BONDS 0x01
#define COD_HID_POINTING 0x00
#define COD_UNCLASSIFIED 0x00
#define BD_NAME_LEN 248
#define BT_SSP_VARIANT_CONSENT 0x00
#define BT_SSP_VARIANT_PASSKEY_CONFIRMATION 0x01
#define BOND_TYPE_TEMPORARY 0
#define BOND_TYPE_PERSISTENT 1

typedef uint8_t UINT8;
typedef uint32_t UINT32;
typedef bool BOOLEAN;

typedef struct {
    uint8_t address[6];
} bt_bdaddr_t;

typedef struct {
    char name[BD_NAME_LEN];
} bt_bdname_t;

typedef struct {
    UINT8 bd_addr[6];
    char bd_name[BD_NAME_LEN];
    UINT8 dev_class[3];
    BOOLEAN just_works;
    UINT8 loc_auth_req;
    UINT8 rmt_auth_req;
    UINT8 loc_io_caps;
    UINT8 rmt_io_caps;
    UINT32 num_val;
} tBTA_DM_SP_CFM_REQ;

typedef struct {
    UINT32 state;
    UINT32 bond_type;
    BOOLEAN is_temp;
    BOOLEAN is_ssp;
    UINT32 sdp_attempts;
} pairing_cb_t;

typedef struct {
    void (*ssp_request_cb)(bt_bdaddr_t*, bt_bdname_t*, UINT32, UINT32, UINT32);
} bt_hal_cbacks_t;

extern pairing_cb_t pairing_cb;
extern bt_hal_cbacks_t *bt_hal_cbacks;

void bdcpy(uint8_t *dest, const uint8_t *src);
void BTIF_TRACE_DEBUG(const char *fmt, ...);
void BTIF_TRACE_EVENT(const char *fmt, ...);
void ALOGD(const char *fmt, ...);
void btif_update_remote_properties(uint8_t *bd_addr, char *bd_name, uint8_t *dev_class, uint8_t dev_type);
void bond_state_changed(uint32_t status, bt_bdaddr_t *bd_addr, uint32_t state);
BOOLEAN check_cod(bt_bdaddr_t *bd_addr, uint32_t cod);
void btif_dm_ssp_reply(bt_bdaddr_t *bd_addr, uint32_t variant, BOOLEAN accept, uint32_t passkey);
uint32_t devclass2uint(uint8_t *dev_class);
#define HAL_CBACK(p_cb, event, ...) \
    do { \
        if ((p_cb) && (p_cb)->event) { \
            (p_cb)->event(__VA_ARGS__); \
        } \
    } while (0)
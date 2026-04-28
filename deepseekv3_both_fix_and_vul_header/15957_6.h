#include <stdint.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define BOOLEAN bool
#define ASSERTC(cond, msg, ret) if (!(cond)) { return; }

#define HCI_LKEY_TYPE_DEBUG_COMB 0
#define HCI_LKEY_TYPE_AUTH_COMB 1
#define HCI_LKEY_TYPE_CHANGED_COMB 2
#define BOND_TYPE_PERSISTENT 0
#define BOND_TYPE_TEMPORARY 1
#define COD_HID_MAJOR 0
#define MAX_UUID_SIZE 16
#define UUID_HUMAN_INTERFACE_DEVICE "00001124-0000-1000-8000-00805F9B34FB"
#define COD_AV_HEADSETS 0
#define COD_AV_HANDSFREE 0
#define COD_AV_HEADPHONES 0
#define COD_AV_PORTABLE_AUDIO 0
#define COD_AV_HIFI_AUDIO 0
#define COD_HID_POINTING 0

#define HCI_ERR_PAGE_TIMEOUT 0x04
#define HCI_ERR_CONNECTION_TOUT 0x08
#define HCI_ERR_PAIRING_NOT_ALLOWED 0x18
#define HCI_ERR_LMP_RESPONSE_TIMEOUT 0x22
#define HCI_ERR_AUTH_FAILURE 0x05
#define HCI_ERR_KEY_MISSING 0x06
#define HCI_ERR_HOST_REJECT_SECURITY 0x07
#define HCI_ERR_ENCRY_MODE_NOT_ACCEPTABLE 0x25
#define HCI_ERR_UNIT_KEY_USED 0x26
#define HCI_ERR_PAIRING_WITH_UNIT_KEY_NOT_SUPPORTED 0x29
#define HCI_ERR_INSUFFCIENT_SECURITY 0x2F
#define HCI_ERR_PEER_USER 0x2A
#define HCI_ERR_UNSPECIFIED 0x1F

typedef enum {
    BT_STATUS_SUCCESS = 0,
    BT_STATUS_FAIL,
    BT_STATUS_RMT_DEV_DOWN,
    BT_STATUS_AUTH_REJECTED,
    BT_STATUS_AUTH_FAILURE
} bt_status_t;

typedef enum {
    BT_BOND_STATE_NONE = 0,
    BT_BOND_STATE_BONDED
} bt_bond_state_t;

typedef enum {
    BT_PROPERTY_UUIDS = 0
} bt_property_type_t;

typedef enum {
    BTA_TRANSPORT_UNKNOWN = 0
} tBTA_TRANSPORT;

typedef struct {
    uint8_t address[6];
} bt_bdaddr_t;

typedef struct {
    uint8_t uu[MAX_UUID_SIZE];
} bt_uuid_t;

typedef struct {
    bt_property_type_t type;
    void *val;
    int len;
} bt_property_t;

typedef struct {
    uint8_t bd_addr[6];
    BOOLEAN success;
    BOOLEAN key_present;
    uint8_t key_type;
    uint8_t key[16];
    uint8_t fail_reason;
} tBTA_DM_AUTH_CMPL;

typedef struct {
    int bond_type;
    int pin_code_len;
    BOOLEAN is_local_initiated;
    BOOLEAN is_temp;
    int timeout_retries;
    int sdp_attempts;
    int autopair_attempts;
} pairing_cb_t;

typedef struct {
    void (*remote_device_properties_cb)(bt_status_t status, bt_bdaddr_t *bd_addr, int num_props, bt_property_t *props);
} bt_hal_callbacks_t;

extern pairing_cb_t pairing_cb;
extern BOOLEAN btif_dm_inquiry_in_progress;
extern bt_hal_callbacks_t *bt_hal_cbacks;

void bdcpy(uint8_t *dest, const uint8_t *src);
void bond_state_changed(bt_status_t status, bt_bdaddr_t *bd_addr, bt_bond_state_t state);
BOOLEAN check_sdp_bl(bt_bdaddr_t *bd_addr);
BOOLEAN check_cod_hid(bt_bdaddr_t *bd_addr, uint8_t cod);
BOOLEAN check_cod(bt_bdaddr_t *bd_addr, uint8_t cod);
BOOLEAN blacklistPairingRetries(uint8_t *addr);
bt_status_t btif_storage_add_bonded_device(bt_bdaddr_t *bd_addr, uint8_t *key, uint8_t key_type, int pin_len);
void btif_storage_remove_bonded_device(bt_bdaddr_t *bd_addr);
void btif_storage_add_device_to_autopair_blacklist(bt_bdaddr_t *bd_addr);
void btif_dm_cb_create_bond(bt_bdaddr_t *bd_addr, tBTA_TRANSPORT transport);
void btif_dm_cancel_discovery(void);
void btif_dm_get_remote_services(bt_bdaddr_t *bd_addr);
void string_to_uuid(const char *str, bt_uuid_t *uuid);
void HAL_CBACK(bt_hal_callbacks_t *cb, void (*func)(bt_status_t, bt_bdaddr_t*, int, bt_property_t*), bt_status_t status, bt_bdaddr_t *bd_addr, int num_props, bt_property_t *props);

#define BTIF_TRACE_DEBUG(...)
#define BTIF_TRACE_WARNING(...)
#define ALOGW(...)

static const char *remote_device_properties_cb = "remote_device_properties_cb";
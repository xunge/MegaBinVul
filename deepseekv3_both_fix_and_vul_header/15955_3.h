#include <stdint.h>
#include <string.h>

#define BTIF_TRACE_DEBUG(fmt, ...)
#define BD_NAME_LEN 248
#define BT_DEVICE_TYPE_BLE 2
#define BT_BOND_STATE_BONDING 1
#define BT_STATUS_SUCCESS 0
#define BOND_TYPE_PERSISTENT 1
#define COD_UNCLASSIFIED 0
#define BT_SSP_VARIANT_CONSENT 0
#define TRUE 1
#define FALSE 0

typedef uint8_t UINT8;
typedef uint32_t UINT32;

typedef struct {
    UINT8 address[6];
} bt_bdaddr_t;

typedef struct {
    char name[BD_NAME_LEN];
} bt_bdname_t;

typedef struct {
    int state;
    int bond_type;
    int is_le_only;
    int is_ssp;
    int is_temp;
} pairing_cb_t;

typedef struct {
    UINT8 bd_addr[6];
    char bd_name[BD_NAME_LEN];
} tBTA_DM_BLE_SEC_REQ;

typedef struct {
    void (*ssp_request_cb)(bt_bdaddr_t *, bt_bdname_t *, UINT32, int, int);
} bt_hal_cbacks_t;

extern pairing_cb_t pairing_cb;
extern bt_hal_cbacks_t *bt_hal_cbacks;

void bdcpy(UINT8 *dest, const UINT8 *src);
void btif_update_remote_properties(UINT8 *bd_addr, char *bd_name, void *arg, int device_type);
void bond_state_changed(int status, bt_bdaddr_t *bd_addr, int state);
void HAL_CBACK(bt_hal_cbacks_t *cbacks, void (*cb)(bt_bdaddr_t *, bt_bdname_t *, UINT32, int, int), ...);

#define ssp_request_cb bt_hal_cbacks->ssp_request_cb
#include <stdint.h>
#include <stddef.h>

#define PIN_CODE_LEN 16
#define BLE_INCLUDED TRUE

typedef unsigned char UINT8;
typedef unsigned int UINT32;

typedef enum {
    BT_STATUS_SUCCESS,
    BT_STATUS_FAIL
} bt_status_t;

typedef struct {
    uint8_t address[6];
} bt_bdaddr_t;

typedef struct {
    uint8_t pin[PIN_CODE_LEN];
} bt_pin_code_t;

typedef uint8_t BD_ADDR[6];

typedef struct {
    uint8_t is_le_only;
    uint8_t pin_code_len;
} pairing_cb_t;

extern pairing_cb_t pairing_cb;

#define BTIF_TRACE_EVENT(fmt, ...)
#define BTIF_TRACE_DEBUG(fmt, ...)

void bdcpy(BD_ADDR dest, const uint8_t *src);
void BTA_DmBlePasskeyReply(BD_ADDR bd_addr, uint8_t accept, UINT32 passkey);
void BTA_DmPinReply(UINT8 *bd_addr, uint8_t accept, uint8_t pin_len, uint8_t *pin_code);
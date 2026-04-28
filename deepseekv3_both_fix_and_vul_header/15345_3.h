#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct {
    uint8_t address[6];
} RawAddress;

typedef struct {
    void (*Run)(uint8_t status, RawAddress addr);
} SyncTransferCb;

#define BT_TRANSPORT_LE 0
#define BTM_UNKNOWN_ADDR 0
#define BTM_MODE_UNSUPPORTED 0
#define BTM_ILLEGAL_VALUE 0
#define MAX_SYNC_TRANSACTION 0

struct tACL_CONN {
    uint8_t peer_le_features[1];
};

struct tBTM_BLE_PERIODIC_SYNC_TRANSFER {
    bool in_use;
    uint16_t conn_handle;
    RawAddress addr;
    SyncTransferCb cb;
};

struct btm_ble_pa_sync_cb_t {
    tBTM_BLE_PERIODIC_SYNC_TRANSFER sync_transfer[MAX_SYNC_TRANSACTION];
} btm_ble_pa_sync_cb;

uint16_t BTM_GetHCIConnHandle(RawAddress addr, uint8_t transport);
tACL_CONN* btm_acl_for_bda(RawAddress addr, uint8_t transport);
bool HCI_LE_PERIODIC_ADVERTISING_SYNC_TRANSFER_RECIPIENT(const uint8_t* features);
int btm_ble_get_free_sync_transfer_index();
void btm_ble_periodic_syc_transfer_cmd_cmpl(uint8_t status);

class BleScanningManager {
public:
    static bool IsInitialized();
    static BleScanningManager* Get();
    void PeriodicAdvSetInfoTransfer(RawAddress addr, uint16_t service_data, uint8_t adv_handle, void (*callback)(uint8_t));
};

#define LOG_DEBUG(fmt, ...) 
#define LOG_ERROR(fmt, ...) 
#define BTM_TRACE_ERROR(fmt) 

namespace base {
    template <typename T>
    static T Bind(T func) {
        return func;
    }
}
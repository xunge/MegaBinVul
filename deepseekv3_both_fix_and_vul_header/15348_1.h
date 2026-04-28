#include <stdint.h>
#include <stddef.h>

#define LOG_DEBUG(format, ...)
#define LOG_ERROR(format, ...)

#define MAX_SYNC_TRANSACTION 0
#define PERIODIC_SYNC_IDLE 0

typedef struct RawAddress {
    static const RawAddress kEmpty;
} RawAddress;

typedef struct sync_node_t {
    uint8_t sid;
    RawAddress address;
} sync_node_t;

typedef struct {
    void (*Run)(int, int, uint8_t, int, RawAddress, int, int);
} SyncStartCallback;

typedef struct tBTM_BLE_PERIODIC_SYNC {
    uint8_t sid;
    RawAddress remote_bda;
    uint16_t sync_handle;
    bool in_use;
    int sync_state;
    SyncStartCallback sync_start_cb;
} tBTM_BLE_PERIODIC_SYNC;

typedef struct {
    tBTM_BLE_PERIODIC_SYNC p_sync[MAX_SYNC_TRANSACTION];
} btm_ble_pa_sync_cb_t;

extern btm_ble_pa_sync_cb_t btm_ble_pa_sync_cb;
extern void* sync_queue;

class BleScanningManager {
public:
    static bool IsInitialized();
    static BleScanningManager* Get();
    void PeriodicScanCancelStart();
};

void* list_front(void* queue);
int btm_ble_get_psync_index(uint8_t adv_sid, RawAddress address);
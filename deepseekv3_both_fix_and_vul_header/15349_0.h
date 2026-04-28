#include <stdint.h>
#include <stdbool.h>

#define MAX_SYNC_TRANSACTION 10
#define BTM_NO_RESOURCES 0
#define BLE_ADDR_RANDOM 1

typedef struct {
    uint8_t bd_addr[6];
} RawAddress;

typedef struct {
    void (*Run)(int, int, uint8_t, int, RawAddress, int, int);
} StartSyncCb;

typedef struct {
    void (*Run)(int, RawAddress, uint8_t, int, int, int);
} SyncReportCb;

typedef struct {
    void (*Run)(int, RawAddress, uint8_t);
} SyncLostCb;

typedef struct {
    bool in_use;
    RawAddress remote_bda;
    uint8_t sid;
    StartSyncCb sync_start_cb;
    SyncReportCb sync_report_cb;
    SyncLostCb sync_lost_cb;
} tBTM_BLE_PERIODIC_SYNC;

typedef struct {
    tBTM_BLE_PERIODIC_SYNC p_sync[MAX_SYNC_TRANSACTION];
} tBTM_BLE_PA_SYNC_CB;

extern tBTM_BLE_PA_SYNC_CB btm_ble_pa_sync_cb;

int btm_ble_get_free_psync_index(void);
void btm_queue_start_sync_req(uint8_t adv_sid, RawAddress address, uint16_t skip, uint16_t timeout);
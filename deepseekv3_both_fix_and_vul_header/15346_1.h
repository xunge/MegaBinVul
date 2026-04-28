#include <stdint.h>
#include <stddef.h>

#define MAX_SYNC_TRANSACTION 10
#define SYNC_TIMEOUT 1000
#define BLE_ADDR_TYPE_ID_BIT 0x02

typedef struct {
    uint8_t bd_addr[6];
} RawAddress;

typedef uint8_t tBLE_ADDR_TYPE;
enum {
    BLE_ADDR_RANDOM = 0x01
};

typedef struct {
    tBLE_ADDR_TYPE ble_addr_type;
} tBLE_INQ_RESULTS;

typedef struct {
    tBLE_INQ_RESULTS results;
} tINQ_INFO;

typedef struct {
    tINQ_INFO inq_info;
} tINQ_DB_ENT;

typedef enum {
    PERIODIC_SYNC_PENDING
} tBTM_BLE_SYNC_STATE;

typedef struct {
    tBTM_BLE_SYNC_STATE sync_state;
} tBTM_BLE_PERIODIC_SYNC;

typedef struct {
    tBTM_BLE_PERIODIC_SYNC p_sync[MAX_SYNC_TRANSACTION];
} tBTM_BLE_PA_SYNC_CB;

extern tBTM_BLE_PA_SYNC_CB btm_ble_pa_sync_cb;
extern tINQ_DB_ENT* btm_inq_db_find(RawAddress addr);
extern void btm_random_pseudo_to_identity_addr(RawAddress* addr, tBLE_ADDR_TYPE* address_type);
extern int btm_ble_get_psync_index(uint8_t sid, RawAddress addr);
extern void LOG_ERROR(const char* msg);
extern void alarm_set(void* alarm, uint32_t timeout, void (*callback)(void*), void* data);
extern void btm_ble_start_sync_timeout(void* data);

class BleScanningManager {
public:
    static bool IsInitialized();
    static BleScanningManager* Get();
    void PeriodicScanStart(uint8_t options, uint8_t sid, tBLE_ADDR_TYPE address_type, RawAddress addr, uint16_t skip, uint16_t timeout, uint8_t cte_type);
};

extern void* sync_timeout_alarm;
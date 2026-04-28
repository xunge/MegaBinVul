#include <stdint.h>
#include <string.h>

typedef enum {
    BT_STATUS_SUCCESS = 0,
    BT_STATUS_FAIL
} bt_status_t;

typedef enum {
    BT_BOND_STATE_NONE,
    BT_BOND_STATE_BONDING
} bt_bond_state_t;

typedef enum {
    BOND_TYPE_TEMPORARY
} bond_type_t;

typedef struct {
    uint8_t address[6];
} bt_bdaddr_t;

typedef struct {
    bt_bond_state_t state;
    bond_type_t bond_type;
    uint8_t bd_addr[6];
    int is_temp;
} pairing_cb_t;

typedef struct {
    void (*bond_state_changed_cb)(bt_status_t, bt_bdaddr_t*, bt_bond_state_t);
} bt_hal_cbacks_t;

extern pairing_cb_t pairing_cb;
extern bt_hal_cbacks_t* bt_hal_cbacks;

#define BTIF_TRACE_DEBUG(fmt, ...)
#define HAL_CBACK(p_cbacks, cb_name, ...) \
    do { \
        if ((p_cbacks) != NULL && (p_cbacks)->cb_name != NULL) { \
            (p_cbacks)->cb_name(__VA_ARGS__); \
        } \
    } while (0)

static inline void bdcpy(uint8_t* dest, const uint8_t* src) {
    memcpy(dest, src, 6);
}
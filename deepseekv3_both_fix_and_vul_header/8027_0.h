#include <stdbool.h>

typedef struct {
    unsigned char address[6];
} bt_bdaddr_t;

#define BT_STATUS_SUCCESS 0
#define BT_STATUS_NOT_READY 1

bool is_restricted_mode(void);
bool btif_storage_is_restricted_device(const bt_bdaddr_t *bd_addr);
bool interface_ready(void);
int btif_dm_remove_bond(const bt_bdaddr_t *bd_addr);

#define FALSE 0
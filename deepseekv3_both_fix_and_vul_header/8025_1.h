#include <stdint.h>
#include <stddef.h>

typedef enum {
    BT_STATUS_SUCCESS,
    BT_STATUS_FAIL
} bt_status_t;

typedef uint8_t bt_bdaddr_t[6];
typedef uint8_t LINK_KEY[16];
typedef char bdstr_t[18];

int btif_config_set_int(const char *section, const char *key, int value);
int btif_config_set_bin(const char *section, const char *key, const void *value, int size);
void btif_config_flush(void);
void bdaddr_to_string(const bt_bdaddr_t *addr, char *string, size_t size);
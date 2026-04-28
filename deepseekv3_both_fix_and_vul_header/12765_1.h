#include <stddef.h>
#include <stdint.h>

struct gatt_db_attribute;
struct bt_att;
struct btd_gatt_database;

struct device_state {
    uint8_t cli_feat[8];
};

#define DBG(fmt, ...)

#define BT_ATT_ERROR_UNLIKELY 0
#define BT_ATT_ERROR_INVALID_OFFSET 0

static struct device_state *get_device_state(struct btd_gatt_database *database, struct bt_att *att)
{
    return NULL;
}

void gatt_db_attribute_read_result(struct gatt_db_attribute *attrib, unsigned int id, uint8_t ecode, const uint8_t *value, size_t len);
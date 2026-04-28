#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct property property;

struct pos_buf {
    uint8_t *curpos;
    uint8_t *endpos;
};

typedef enum {
    PROP_TYPE_INT,
    PROP_TYPE_STRING,
    PROP_TYPE_BINARY,
    PROP_TYPE_BOOL
} property_type_enum;

extern int read_variable_int(uint8_t *buf, size_t len, uint32_t *value, uint8_t *bytes);
extern void read_byte(struct pos_buf *buf, uint8_t *byte);
extern property *property_alloc(void);
extern property_type_enum property_get_value_type(uint8_t prop_id);
extern property *property_parse(struct pos_buf *buf, property *prop, uint8_t prop_id, property_type_enum type, bool copy_value);
extern void property_append(property *list, property *prop);
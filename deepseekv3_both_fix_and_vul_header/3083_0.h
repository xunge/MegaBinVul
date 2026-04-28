#include <stddef.h>
#include <stdint.h>
#include <arpa/inet.h>

struct vendor_attribute {
    uint32_t vendor_value;
    uint8_t attrib_type;
    uint16_t attrib_len;
    uint8_t attrib_data[];
};
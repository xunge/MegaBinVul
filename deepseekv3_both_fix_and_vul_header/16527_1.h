#include <stdint.h>
#include <stddef.h>

#define DHCP_PADDING 0
#define DHCP_END 255
#define DHCP_OPTION_OVERLOAD 52
#define FILE_FIELD 1
#define SNAME_FIELD 2
#define OPT_CODE 0
#define OPT_LEN 1
#define OPT_DATA 2

struct dhcp_packet {
    uint8_t options[312];
    uint8_t file[128];
    uint8_t sname[64];
};
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define DEX_HEADER_DEXMAGIC_V38 "dex\n038\x00"
#define DEX_HEADER_DEXMAGIC_V37 "dex\n037\x00"
#define DEX_HEADER_DEXMAGIC_V35 "dex\n035\x00"

#define always_assert_log(cond, fmt, ...) if (!(cond)) {}
#define not_reached_log(fmt, ...) {}
#define FALLTHROUGH_INTENDED

struct dex_header {
    char magic[8];
    uint32_t file_size;
    uint32_t string_ids_off;
    uint32_t string_ids_size;
    uint32_t type_ids_off;
    uint32_t type_ids_size;
    uint32_t proto_ids_off;
    uint32_t proto_ids_size;
    uint32_t field_ids_off;
    uint32_t field_ids_size;
    uint32_t method_ids_off;
    uint32_t method_ids_size;
    uint32_t class_defs_off;
    uint32_t class_defs_size;
};

struct dex_string_id {};
struct dex_type_id {};
struct dex_proto_id {};
struct dex_field_id {};
struct dex_method_id {};
struct dex_class_def {};
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MF_UL_MAX_DUMP_SIZE 1024
static const uint32_t nfc_mifare_ultralight_data_format_version = 1;

typedef struct {
    uint8_t signature[32];
    uint8_t version;
    uint32_t counter[3];
    uint8_t tearing[3];
    uint16_t data_size;
    uint16_t data_read;
    uint8_t data[MF_UL_MAX_DUMP_SIZE];
} MfUltralightData;

typedef struct {
    MfUltralightData mf_ul_data;
} NfcDeviceData;

typedef struct {
    NfcDeviceData dev_data;
} NfcDevice;

typedef struct {
    char* ptr;
} string_t;

typedef struct FlipperFormat FlipperFormat;

extern bool flipper_format_read_uint32(FlipperFormat* file, const char* key, uint32_t* data, uint16_t count);
extern bool flipper_format_read_hex(FlipperFormat* file, const char* key, uint8_t* data, uint16_t count);
extern bool flipper_format_rewind(FlipperFormat* file);
extern void string_init(string_t str);
extern void string_clear(string_t str);
extern void string_printf(string_t str, const char* format, ...);
extern const char* string_get_cstr(string_t str);
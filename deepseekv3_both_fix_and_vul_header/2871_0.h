#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct ok_mo_decoder ok_mo_decoder;
typedef struct ok_mo ok_mo;
typedef struct ok_mo_string ok_mo_string;

struct ok_mo_string {
    char *key;
    char *value;
    uint32_t num_plural_variants;
};

struct ok_mo {
    uint32_t num_strings;
    ok_mo_string *strings;
};

struct ok_mo_decoder {
    ok_mo *mo;
    uint8_t *key_offset_buffer;
    uint8_t *value_offset_buffer;
};

static uint32_t read32(const uint8_t *data, bool little_endian);
static uint16_t read16(const uint8_t *data, bool little_endian);
static bool ok_read(ok_mo_decoder *decoder, uint8_t *buffer, size_t length);
static bool ok_seek(ok_mo_decoder *decoder, long offset);
static void ok_mo_error(ok_mo *mo, const char *message);
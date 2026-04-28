#include <stdlib.h>

typedef struct cJSON {
    char *valuestring;
    int type;
} cJSON;

#define cJSON_String 4

static unsigned parse_hex4(const char *str) {
    unsigned h = 0;
    const char *hex = str;
    if (!hex) return 0;
    for (; *hex; hex++) {
        h <<= 4;
        if (*hex >= '0' && *hex <= '9') h += *hex - '0';
        else if (*hex >= 'A' && *hex <= 'F') h += *hex - 'A' + 10;
        else if (*hex >= 'a' && *hex <= 'f') h += *hex - 'a' + 10;
        else return 0;
    }
    return h;
}

static void *cJSON_malloc(size_t size) {
    return malloc(size);
}

static const unsigned char firstByteMark[7] = { 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC };
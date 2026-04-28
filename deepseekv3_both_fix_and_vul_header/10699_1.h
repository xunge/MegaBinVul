#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct ColorEntry {
    const char *name;
    uint32_t rgb_color;
} ColorEntry;

static int color_table_compare(const void *a, const void *b) {
    const char *name = a;
    const ColorEntry *entry = b;
    return strcmp(name, entry->name);
}

static int hex_char_to_number(char c) {
    c = tolower(c);
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return 10 + c - 'a';
    return 0;
}

static const ColorEntry color_table[] = {
    {"red", 0xFF0000FF},
    {"green", 0xFF00FF00},
    {"blue", 0xFFFF0000},
    /* Add more color entries as needed */
};

#define FF_ARRAY_ELEMS(arr) (sizeof(arr) / sizeof((arr)[0]))
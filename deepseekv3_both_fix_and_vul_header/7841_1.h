#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

typedef enum {
    MOBI_SUCCESS,
    MOBI_INIT_FAILED,
    MOBI_DATA_CORRUPT,
    MOBI_MALLOC_FAILED,
    MOBI_NOTSET
} MOBI_RET;

typedef struct {
    size_t entries_count;
    size_t total_entries_count;
    size_t ligt_entries_count;
    struct {
        char *label;
        struct {
            uint8_t tagid;
            uint32_t *tagvalues;
            uint32_t tagvalues_count;
        } *tags;
        size_t tags_count;
    } *entries;
} MOBIIndx;

typedef struct {
    size_t *offsets;
} MOBIIdxt;

typedef struct {
    size_t control_byte_count;
    size_t tags_count;
    struct {
        uint8_t control_byte;
        uint8_t bitmask;
        uint8_t tag;
        uint8_t values_count;
    } *tags;
} MOBITagx;

typedef struct {
    uint8_t ordt2;
} MOBIOrdt;

typedef struct {
    unsigned char *data;
    size_t offset;
    size_t maxlen;
    MOBI_RET error;
} MOBIBuffer;

typedef struct {
    uint8_t tagid;
    uint32_t *tagvalues;
    uint32_t tagvalues_count;
} MOBIIndexTag;

#define INDX_LABEL_SIZEMAX 255
#define INDX_TAGVALUES_MAX 32

static void debug_print(const char *format, ...);
static size_t mobi_buffer_get8(MOBIBuffer *buf);
static size_t mobi_getstring_ordt(const MOBIOrdt *ordt, MOBIBuffer *buf, unsigned char *text, size_t length);
static size_t mobi_indx_get_label(unsigned char *text, MOBIBuffer *buf, size_t length, size_t ligt_entries_count);
static void mobi_buffer_seek(MOBIBuffer *buf, int offset);
static uint32_t mobi_buffer_get_varlen(MOBIBuffer *buf, size_t *len);
static int mobi_bitcount(uint8_t n);
static void mobi_buffer_setpos(MOBIBuffer *buf, size_t pos);
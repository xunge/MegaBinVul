#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define R_STRING_SCAN_BUFFER_SIZE 1024
#define R_STRING_TYPE_DETECT 0
#define R_STRING_TYPE_ASCII 1
#define R_STRING_TYPE_WIDE 2
#define R_STRING_TYPE_WIDE32 3
#define R_STRING_TYPE_UTF8 4
#define PFMT64x "llx"
#define IS_PRINTABLE(c) (isprint((unsigned char)(c)))

typedef uint64_t ut64;
typedef uint8_t ut8;
typedef uint32_t ut32;

typedef struct r_list_t RList;
typedef struct r_bin_string_t RBinString;
typedef ut32 RRune;

struct r_bin_string_t {
    int type;
    int length;
    int size;
    int ordinal;
    ut64 paddr;
    ut64 vaddr;
    char *string;
};

static int r_utf8_decode(const ut8 *ptr, int ptrlen, RRune *ch);
static int r_utf16le_decode(const ut8 *ptr, int ptrlen, RRune *ch);
static int r_utf32le_decode(const ut8 *ptr, int ptrlen, RRune *ch);
static int r_utf8_encode(ut8 *ptr, RRune ch);
static int r_isprint(RRune ch);
static char *r_str_ndup(const char *ptr, int len);
static void r_list_append(RList *list, void *item);

#define R_NEW0(type) ((type *)calloc(1, sizeof(type)))
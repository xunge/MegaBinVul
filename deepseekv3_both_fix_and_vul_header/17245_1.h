#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

typedef uint64_t ut64;
typedef uint32_t ut32;
typedef uint8_t ut8;

#define R_STRING_SCAN_BUFFER_SIZE 1024
#define R_STRING_TYPE_DETECT 0
#define R_STRING_TYPE_ASCII 1
#define R_STRING_TYPE_WIDE 2
#define R_STRING_TYPE_WIDE32 3
#define R_STRING_TYPE_UTF8 4

#define IS_PRINTABLE(c) (c >= 0x20 && c <= 0x7e)

typedef struct RList RList;
typedef struct RBinFile RBinFile;
typedef struct RBinString RBinString;
typedef ut32 RRune;

struct RBinFile {
    void *buf;
};

struct RBinString {
    int type;
    int length;
    int size;
    int ordinal;
    ut64 paddr;
    ut64 vaddr;
    char *string;
};

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define R_NEW0(type) ((type*)calloc(1, sizeof(type)))

int r_buf_read_at(void *buf, ut64 addr, ut8 *data, ut64 size);
int r_utf8_decode(const ut8 *ptr, int ptrlen, RRune *ch);
int r_utf16le_decode(const ut8 *ptr, int ptrlen, RRune *ch);
int r_utf32le_decode(const ut8 *ptr, int ptrlen, RRune *ch);
int r_utf8_encode(ut8 *ptr, RRune ch);
bool r_isprint(RRune ch);
char *r_str_ndup(const char *ptr, int len);
void r_list_append(RList *list, void *data);
void r_bin_string_free(RBinString *bs);
void print_string(RBinString *bs, RBinFile *bf);
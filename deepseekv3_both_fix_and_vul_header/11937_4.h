#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 20
#define MAX_SYMBOL_LENGTH 15
#define HUFFMAN_TABLE_SIZE 326
#define MAINCODE_SIZE 299
#define OFFSETCODE_SIZE 60
#define LOWOFFSETCODE_SIZE 17
#define LENGTHCODE_SIZE 28
#define DICTIONARY_MAX_SIZE 0x400000
#define ARCHIVE_ERRNO_FILE_FORMAT 1
#define ARCHIVE_FATAL 1
#define ARCHIVE_OK 0
#define ENOMEM 12

struct huffman_code {
    void *tree;
    void *table;
};

struct rar_br {
    unsigned cache;
    unsigned cache_avail;
    const unsigned char *next_in;
};

struct archive_read;
struct archive {
    int errno;
};

struct bytein {
    struct archive_read *a;
    int (*Read)(void *);
};

struct range_dec {
    void *Stream;
};

struct ppmd7_context {
    unsigned InitEsc;
};

struct lzss {
    unsigned char *window;
    unsigned mask;
};

struct rar {
    struct rar_br br;
    unsigned char lengthtable[HUFFMAN_TABLE_SIZE];
    int is_ppmd_block;
    unsigned dictionary_size;
    unsigned char ppmd_escape;
    struct ppmd7_context ppmd7_context;
    int ppmd_valid;
    struct lzss lzss;
    unsigned unp_size;
    int valid;
    int start_new_table;
    struct huffman_code maincode;
    struct huffman_code offsetcode;
    struct huffman_code lowoffsetcode;
    struct huffman_code lengthcode;
    struct bytein bytein;
    struct range_dec range_dec;
};

struct archive_read {
    struct archive archive;
    struct {
        void *data;
    } *format;
};

struct archive_ppmd7_functions {
    void (*Ppmd7_Free)(struct ppmd7_context *);
    int (*Ppmd7_Alloc)(struct ppmd7_context *, unsigned);
    void (*Ppmd7_Construct)(struct ppmd7_context *);
    void (*Ppmd7_Init)(struct ppmd7_context *, unsigned);
    void (*PpmdRAR_RangeDec_CreateVTable)(struct range_dec *);
    int (*PpmdRAR_RangeDec_Init)(struct range_dec *);
};

extern const struct archive_ppmd7_functions __archive_ppmd7_functions;

static void free_codes(struct archive_read *a) {}
static void rar_br_consume_unalined_bits(struct rar_br *br) {}
static int rar_br_read_ahead(struct archive_read *a, struct rar_br *br, int bits) { return 0; }
static unsigned int rar_br_bits(struct rar_br *br, int bits) { return 0; }
static void rar_br_consume(struct rar_br *br, int bits) {}
static void archive_set_error(struct archive *a, int code, const char *msg) {}
static int create_code(struct archive_read *a, struct huffman_code *code,
                     unsigned char *lengths, int numsymbols, int maxlength) { return 0; }
static int read_next_symbol(struct archive_read *a, struct huffman_code *code) { return 0; }
static int ppmd_read(void *p) { return 0; }
static unsigned int rar_fls(unsigned int word) { return 0; }
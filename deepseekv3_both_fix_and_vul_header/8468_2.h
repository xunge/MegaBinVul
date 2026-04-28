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
#define ARCHIVE_OK 0
#define ARCHIVE_FATAL 1
#define ARCHIVE_ERRNO_FILE_FORMAT -1
#define ENOMEM 12

struct huffman_code {
    void *tree;
    void *table;
};

struct rar_br {
    unsigned int cache;
    unsigned int cache_avail;
    const unsigned char *next_in;
};

struct archive_ppmd7 {
    int InitEsc;
};

struct archive_ppmd7_range_dec {
    void *Stream;
};

struct archive_ppmd7_stream_reader {
    int dummy;
};

struct archive_ppmd7_functions {
    void (*Ppmd7_Free)(struct archive_ppmd7*, struct archive_ppmd7_stream_reader*);
    void (*PpmdRAR_RangeDec_CreateVTable)(struct archive_ppmd7_range_dec*);
    void (*Ppmd7_Construct)(struct archive_ppmd7*);
    int (*Ppmd7_Alloc)(struct archive_ppmd7*, unsigned int, struct archive_ppmd7_stream_reader*);
    int (*PpmdRAR_RangeDec_Init)(struct archive_ppmd7_range_dec*);
    void (*Ppmd7_Init)(struct archive_ppmd7*, unsigned int);
};

struct archive {
    int archive;
};

struct archive_format {
    void *data;
};

struct archive_read {
    struct archive archive;
    struct archive_format *format;
};

struct rar {
    struct rar_br br;
    unsigned char lengthtable[HUFFMAN_TABLE_SIZE];
    struct huffman_code maincode;
    struct huffman_code offsetcode;
    struct huffman_code lowoffsetcode;
    struct huffman_code lengthcode;
    unsigned int dictionary_size;
    int is_ppmd_block;
    int ppmd_valid;
    unsigned char ppmd_escape;
    struct archive_ppmd7 ppmd7_context;
    struct archive_ppmd7_range_dec range_dec;
    struct {
        void *a;
        int (*Read)(void*);
    } bytein;
    struct {
        unsigned char *window;
        unsigned int mask;
    } lzss;
    int valid;
    int start_new_table;
    size_t unp_size;
};

extern struct archive_ppmd7_functions __archive_ppmd7_functions;
extern struct archive_ppmd7_stream_reader g_szalloc;

static void archive_set_error(struct archive *a, int code, const char *msg) {}
static void free_codes(struct archive_read *a) {}
static int create_code(struct archive_read *a, struct huffman_code *code, 
                      unsigned char *lengths, int numsymbols, int maxlength) { return 0; }
static int read_next_symbol(struct archive_read *a, struct huffman_code *code) { return 0; }
static int rar_br_read_ahead(struct archive_read *a, struct rar_br *br, int bits) { return 0; }
static unsigned int rar_br_bits(struct rar_br *br, int bits) { return 0; }
static void rar_br_consume(struct rar_br *br, int bits) {}
static void rar_br_consume_unalined_bits(struct rar_br *br) {}
static unsigned int rar_fls(unsigned int word) { return 0; }
static int ppmd_read(void *p) { return 0; }
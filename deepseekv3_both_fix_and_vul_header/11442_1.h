#include <assert.h>
#include <string.h>

typedef unsigned char u8;

#define SC_MAX_APDU_BUFFER_SIZE 256
#define SC_MAX_PATH_SIZE 260

#define SC_ERROR_INVALID_ARGUMENTS 1
#define SC_ERROR_UNKNOWN_DATA_RECEIVED 2
#define SC_ERROR_OUT_OF_MEMORY 3

#define SC_LOG_DEBUG_VERBOSE 0
#define SC_LOG_DEBUG_NORMAL 1

#define SC_APDU_CASE_1 0
#define SC_APDU_CASE_2_SHORT 1
#define SC_APDU_CASE_3_SHORT 2
#define SC_APDU_CASE_4_SHORT 3

#define SC_FILE_TYPE_WORKING_EF 0
#define SC_FILE_TYPE_DF 1

#define SC_PATH_TYPE_FILE_ID 0
#define SC_PATH_TYPE_FROM_CURRENT 1
#define SC_PATH_TYPE_DF_NAME 2
#define SC_PATH_TYPE_PATH 3
#define SC_PATH_TYPE_PARENT 4

#define SC_FILE_MAGIC 0x46494C45

struct sc_context {
    void *unused;
};
struct sc_card {
    struct sc_context *ctx;
};
struct sc_path {
    unsigned char *value;
    size_t len;
    int type;
};
struct sc_file {
    struct sc_path path;
    size_t size;
    int shareable;
    int ef_structure;
    int type;
    unsigned int id;
    unsigned char name[256];
    size_t namelen;
    unsigned char *sec_attr;
    size_t sec_attr_len;
    unsigned int magic;
};
struct sc_apdu {
    int cse;
    int p1;
    int p2;
    int lc;
    unsigned char *data;
    size_t datalen;
    unsigned char *resp;
    size_t resplen;
    int le;
    int sw1;
    int sw2;
};

typedef struct sc_context sc_context_t;
typedef struct sc_card sc_card_t;
typedef struct sc_path sc_path_t;
typedef struct sc_file sc_file_t;
typedef struct sc_apdu sc_apdu_t;

static inline void SC_FUNC_RETURN(sc_context_t *ctx, int level, int ret) {}
static inline void SC_TEST_RET(sc_context_t *ctx, int level, int ret, const char *msg) {}
static inline void sc_debug(sc_context_t *ctx, int level, const char *fmt, ...) {}

static inline sc_file_t *sc_file_new(void) { return 0; }
static inline void sc_file_set_sec_attr(sc_file_t *file, const u8 *data, size_t len) {}
static inline void sc_file_set_prop_attr(sc_file_t *file, const u8 *data, size_t len) {}
static inline void parse_sec_attr(sc_card_t *card, sc_file_t *file, const u8 *data, size_t len) {}

static inline void sc_format_apdu(sc_card_t *card, sc_apdu_t *apdu, int cse, int ins, int p1, int p2) {}
static inline int sc_transmit_apdu(sc_card_t *card, sc_apdu_t *apdu) { return 0; }
static inline int sc_check_sw(sc_card_t *card, int sw1, int sw2) { return 0; }
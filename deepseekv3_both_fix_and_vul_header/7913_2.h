#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MIN_IDB_SIZE 20
#define MAX_BLOCK_SIZE 1048576
#define WTAP_MAX_PACKET_SIZE 65535
#define G_MAXUINT64 UINT64_MAX

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef unsigned int guint;
typedef char gchar;

typedef FILE FILE_T;

typedef enum {
    WTAP_ERR_BAD_FILE,
    ENOMEM
} wtap_err;

typedef enum {
    WTAP_BLOCK_IF_DESCR
} wtap_block_type_t;

typedef enum {
    WTAP_ENCAP_UNKNOWN,
    WTAP_ENCAP_PER_PACKET
} wtap_encap_type;

typedef enum {
    WTAP_TSPREC_UNKNOWN,
    WTAP_TSPREC_PER_PACKET,
    WTAP_TSPREC_SEC,
    WTAP_TSPREC_DSEC,
    WTAP_TSPREC_CSEC,
    WTAP_TSPREC_MSEC,
    WTAP_TSPREC_USEC,
    WTAP_TSPREC_NSEC
} wtap_tsprec_type;

typedef struct {
    guint16 linktype;
    guint32 snaplen;
} pcapng_interface_description_block_t;

typedef struct {
    guint32 block_total_length;
} pcapng_block_header_t;

typedef struct {
    gboolean byte_swapped;
    guint8 if_fcslen;
} pcapng_t;

typedef struct {
    void* block;
} wtapng_block_t;

typedef struct {
    wtap_encap_type wtap_encap;
    guint16 link_type;
    guint32 snap_len;
    guint64 time_units_per_second;
    wtap_tsprec_type tsprecision;
} wtapng_if_descr_mandatory_t;

typedef struct {
    guint16 option_code;
    guint16 option_length;
} pcapng_option_header_t;

typedef struct {
    char* if_filter_str;
    guint8* if_filter_bpf_bytes;
    guint16 bpf_filter_len;
} wtapng_if_descr_filter_t;

typedef struct {
    wtap_encap_type file_encap;
    wtap_tsprec_type file_tsprec;
} wtap;

#define OPT_EOFOPT 0
#define OPT_COMMENT 1
#define OPT_IDB_NAME 2
#define OPT_IDB_DESCR 3
#define OPT_IDB_SPEED 4
#define OPT_IDB_TSRESOL 5
#define OPT_IDB_FILTER 6
#define OPT_IDB_OS 12
#define OPT_IDB_FCSLEN 13
#define OPT_IDB_IP4ADDR 14
#define OPT_IDB_IP6ADDR 15
#define OPT_IDB_MACADDR 16
#define OPT_IDB_EUIADDR 17
#define OPT_IDB_TZONE 18
#define OPT_IDB_TSOFFSET 19

#define GUINT16_SWAP_LE_BE(val) (val)
#define GUINT32_SWAP_LE_BE(val) (val)
#define GUINT64_SWAP_LE_BE(val) (val)
#define G_GINT64_MODIFIER "ll"

static inline char* g_strdup_printf(const char* format, ...) { return NULL; }
static inline char* g_strndup(const char* str, size_t n) { return NULL; }
static inline void* g_try_malloc(size_t n) { return malloc(n); }
static inline void g_free(void* p) { free(p); }
static inline void* wtap_block_create(wtap_block_type_t type) { return NULL; }
static inline void* wtap_block_get_mandatory_data(void* block) { return NULL; }
static inline void wtap_block_add_string_option(void* block, guint16 code, const void* data, guint16 length) {}
static inline void wtap_block_add_uint8_option(void* block, guint16 code, guint8 value) {}
static inline void wtap_block_add_uint64_option(void* block, guint16 code, guint64 value) {}
static inline void wtap_block_add_custom_option(void* block, guint16 code, const void* data, guint16 length) {}
static inline wtap_encap_type wtap_pcap_encap_to_wtap_encap(guint16 linktype) { return WTAP_ENCAP_UNKNOWN; }
static inline const char* wtap_encap_string(wtap_encap_type encap) { return ""; }
static inline gboolean wtap_read_bytes(FILE_T fh, void* buf, size_t count, int* err, gchar** err_info) { return FALSE; }
static inline void pcapng_debug(const char* format, ...) {}
static inline int pcapng_read_option(FILE_T fh, pcapng_t* pn, pcapng_option_header_t* oh, guint8* content, guint buf_len, guint to_read, int* err, gchar** err_info, const char* context) { return 0; }
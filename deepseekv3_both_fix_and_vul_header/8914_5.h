#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MIN_IDB_SIZE 20
#define MAX_BLOCK_SIZE 65536
#define WTAP_MAX_PACKET_SIZE 65535

#define WTAP_ERR_BAD_FILE 0
#define WTAP_ENCAP_UNKNOWN 0
#define WTAP_ENCAP_PER_PACKET 0
#define WTAP_TSPREC_UNKNOWN 0
#define WTAP_TSPREC_PER_PACKET 0
#define WTAP_TSPREC_SEC 0
#define WTAP_TSPREC_DSEC 0
#define WTAP_TSPREC_CSEC 0
#define WTAP_TSPREC_MSEC 0
#define WTAP_TSPREC_USEC 0
#define WTAP_TSPREC_NSEC 0
#define ENOMEM 12

#define OPT_EOFOPT 0
#define OPT_COMMENT 1
#define OPT_IDB_NAME 2
#define OPT_IDB_DESCR 3
#define OPT_IDB_SPEED 4
#define OPT_IDB_TSRESOL 5
#define OPT_IDB_FILTER 6
#define OPT_IDB_OS 7
#define OPT_IDB_FCSLEN 8
#define OPT_IDB_IP4ADDR 9
#define OPT_IDB_IP6ADDR 10
#define OPT_IDB_MACADDR 11
#define OPT_IDB_EUIADDR 12
#define OPT_IDB_TZONE 13
#define OPT_IDB_TSOFFSET 14

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef unsigned int guint;
typedef char gchar;

typedef FILE* FILE_T;

typedef struct pcapng_block_header_t {
    guint32 block_type;
    guint32 block_total_length;
} pcapng_block_header_t;

typedef struct pcapng_t {
    gboolean byte_swapped;
    int if_fcslen;
} pcapng_t;

typedef struct pcapng_interface_description_block_t {
    guint16 linktype;
    guint16 reserved;
    guint32 snaplen;
} pcapng_interface_description_block_t;

typedef struct pcapng_option_header_t {
    guint16 option_code;
    guint16 option_length;
} pcapng_option_header_t;

typedef struct wtapng_if_descr_t {
    int link_type;
    guint32 snap_len;
    int wtap_encap;
    guint64 time_units_per_second;
    int tsprecision;
    char* opt_comment;
    char* if_name;
    char* if_description;
    guint64 if_speed;
    guint8 if_tsresol;
    char* if_filter_str;
    guint16 bpf_filter_len;
    char* if_filter_bpf_bytes;
    char* if_os;
    int if_fcslen;
} wtapng_if_descr_t;

typedef struct wtapng_block_data_t {
    wtapng_if_descr_t if_descr;
} wtapng_block_data_t;

typedef struct wtapng_block_t {
    wtapng_block_data_t data;
} wtapng_block_t;

typedef struct wtap {
    int file_encap;
    int file_tsprec;
} wtap;

#define GUINT16_SWAP_LE_BE(x) (x)
#define GUINT32_SWAP_LE_BE(x) (x)
#define GUINT64_SWAP_LE_BE(x) (x)
#define G_GINT64_MODIFIER "l"
#define G_MAXUINT64 UINT64_MAX

static char* g_strdup_printf(const char* format, ...) { return NULL; }
static char* g_strndup(const char* str, size_t n) { return NULL; }
static void* g_try_malloc(size_t n) { return malloc(n); }
static void* g_malloc(size_t n) { return malloc(n); }
static void g_free(void* p) { free(p); }

static int wtap_pcap_encap_to_wtap_encap(int encap) { return 0; }
static const char* wtap_encap_string(int encap) { return ""; }
static gboolean wtap_read_bytes(FILE_T fh, void* buf, size_t size, int* err, gchar** err_info) { return TRUE; }
static int pcapng_read_option(FILE_T fh, pcapng_t* pn, pcapng_option_header_t* oh, guint8* option_content, guint opt_cont_buf_len, guint to_read, int* err, gchar** err_info) { return 0; }
static void pcapng_debug0(const char* fmt, ...) {}
static void pcapng_debug1(const char* fmt, ...) {}
static void pcapng_debug2(const char* fmt, ...) {}
static void pcapng_debug3(const char* fmt, ...) {}
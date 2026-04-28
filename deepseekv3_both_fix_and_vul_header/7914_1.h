#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MIN_ISB_SIZE 28
#define MAX_BLOCK_SIZE 0x1000000
#define MIN_BLOCK_SIZE 12
#define WTAP_ERR_BAD_FILE 0
#define ENOMEM 12

#define OPT_EOFOPT 0
#define OPT_COMMENT 1
#define OPT_ISB_STARTTIME 2
#define OPT_ISB_ENDTIME 3
#define OPT_ISB_IFRECV 4
#define OPT_ISB_IFDROP 5
#define OPT_ISB_FILTERACCEPT 6
#define OPT_ISB_OSDROP 7
#define OPT_ISB_USRDELIV 8

#define WTAP_BLOCK_IF_STATS 1

#define FALSE 0
#define TRUE 1

typedef int gboolean;
typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef uint64_t guint64;
typedef unsigned int guint;
typedef char gchar;

typedef struct {
    guint32 block_total_length;
} pcapng_block_header_t;

typedef struct {
    guint32 interface_id;
    guint32 timestamp_high;
    guint32 timestamp_low;
} pcapng_interface_statistics_block_t;

typedef struct {
    guint16 option_code;
    guint16 option_length;
} pcapng_option_header_t;

typedef struct {
    void* block;
} wtapng_block_t;

typedef struct {
    guint32 interface_id;
    guint32 ts_high;
    guint32 ts_low;
} wtapng_if_stats_mandatory_t;

typedef struct {
    gboolean byte_swapped;
} pcapng_t;

typedef FILE FILE_T;

#define GUINT32_SWAP_LE_BE(val) __builtin_bswap32(val)
#define GUINT64_SWAP_LE_BE(val) __builtin_bswap64(val)
#define G_GINT64_MODIFIER "ll"
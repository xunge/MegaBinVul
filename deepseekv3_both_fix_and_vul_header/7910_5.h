#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    PCAPNG_BLOCK_OK,
    PCAPNG_BLOCK_ERROR,
    PCAPNG_BLOCK_NOT_SHB
} block_return_val;

typedef struct wtap wtap;
typedef FILE FILE_T;

typedef struct pcapng_t {
    int byte_swapped;
    int shb_read;
} pcapng_t;

typedef struct wtapng_block_t {
    void* block;
    uint32_t type;
} wtapng_block_t;

typedef struct pcapng_block_header_t {
    uint32_t block_type;
    uint32_t block_total_length;
} pcapng_block_header_t;

#define BLOCK_TYPE_SHB 0x0A0D0D0A
#define BLOCK_TYPE_IDB 0x00000001
#define BLOCK_TYPE_PB 0x00000002
#define BLOCK_TYPE_SPB 0x00000003
#define BLOCK_TYPE_EPB 0x00000006
#define BLOCK_TYPE_NRB 0x00000004
#define BLOCK_TYPE_ISB 0x00000005
#define BLOCK_TYPE_SYSDIG_EVENT 0x00000201

#define MAX_BLOCK_SIZE (16*1024*1024)

#define WTAP_ERR_SHORT_READ (-1)
#define WTAP_ERR_BAD_FILE (-2)

static inline uint32_t GUINT32_SWAP_LE_BE(uint32_t val) {
    return (val << 24) | ((val << 8) & 0x00ff0000) | 
           ((val >> 8) & 0x0000ff00) | (val >> 24);
}

typedef char gchar;
typedef uint32_t guint32;
#define FALSE 0
#define TRUE 1

int wtap_read_bytes_or_eof(FILE_T fh, void *buf, unsigned int count, int *err, gchar **err_info);
int wtap_read_bytes(FILE_T fh, void *buf, unsigned int count, int *err, gchar **err_info);
int pcapng_read_section_header_block(FILE_T fh, pcapng_block_header_t *bh, pcapng_t *pn, wtapng_block_t *wblock, int *err, gchar **err_info);
int pcapng_read_if_descr_block(wtap *wth, FILE_T fh, pcapng_block_header_t *bh, pcapng_t *pn, wtapng_block_t *wblock, int *err, gchar **err_info);
int pcapng_read_packet_block(FILE_T fh, pcapng_block_header_t *bh, pcapng_t *pn, wtapng_block_t *wblock, int *err, gchar **err_info, int enhanced);
int pcapng_read_simple_packet_block(FILE_T fh, pcapng_block_header_t *bh, pcapng_t *pn, wtapng_block_t *wblock, int *err, gchar **err_info);
int pcapng_read_name_resolution_block(FILE_T fh, pcapng_block_header_t *bh, pcapng_t *pn, wtapng_block_t *wblock, int *err, gchar **err_info);
int pcapng_read_interface_statistics_block(FILE_T fh, pcapng_block_header_t *bh, pcapng_t *pn, wtapng_block_t *wblock, int *err, gchar **err_info);
int pcapng_read_sysdig_event_block(FILE_T fh, pcapng_block_header_t *bh, pcapng_t *pn, wtapng_block_t *wblock, int *err, gchar **err_info);
int pcapng_read_unknown_block(FILE_T fh, pcapng_block_header_t *bh, pcapng_t *pn, wtapng_block_t *wblock, int *err, gchar **err_info);

char* g_strdup_printf(const char* format, ...);
#define pcapng_debug(...)
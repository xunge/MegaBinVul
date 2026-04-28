#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MIN_SPB_SIZE 16
#define MAX_BLOCK_SIZE 0xFFFFFFFF
#define WTAP_MAX_PACKET_SIZE 65535

#define FALSE 0
#define TRUE 1
typedef int gboolean;
typedef char gchar;
typedef uint32_t guint32;

#define WTAP_ERR_BAD_FILE 0
#define WTAP_HAS_CAP_LEN 0
#define WTAP_HAS_INTERFACE_ID 0
#define REC_TYPE_PACKET 0
#define WTAP_FILE_TYPE_SUBTYPE_PCAPNG 0

typedef struct {
    guint32 block_total_length;
} pcapng_block_header_t;

typedef struct {
    int wtap_encap;
    guint32 snap_len;
    int tsprecision;
} interface_info_t;

typedef struct {
    struct {
        int len;
        interface_info_t* data;
    } *interfaces;
    gboolean byte_swapped;
    int if_fcslen;
} pcapng_t;

typedef struct {
    guint32 packet_len;
} pcapng_simple_packet_block_t;

typedef struct {
    guint32 packet_len;
    guint32 cap_len;
} wtapng_simple_packet_t;

typedef union wtap_pseudo_header {
    struct {
        int dummy;
    } phdr;
    size_t size;
} wtap_pseudo_header_t;

typedef struct {
    int rec_type;
    int presence_flags;
    int interface_id;
    int pkt_encap;
    int pkt_tsprec;
    struct {
        int secs;
        int nsecs;
    } ts;
    char *opt_comment;
    int drop_count;
    int pack_flags;
    int caplen;
    int len;
    wtap_pseudo_header_t pseudo_header;
} packet_header_t;

typedef struct {
    packet_header_t *packet_header;
    void *frame_buffer;
} wtapng_block_t;

typedef FILE FILE_T;

char* g_strdup(const char *str);
char* g_strdup_printf(const char *format, ...);
#define g_array_index(array, type, index) (((type*)((array)->data))[index])
#define GUINT32_SWAP_LE_BE(val) __builtin_bswap32(val)

int pcap_get_phdr_size(int encap, wtap_pseudo_header_t *phdr);
int pcap_process_pseudo_header(FILE_T fh, int subtype, int encap, int caplen, gboolean bytes_swapped, packet_header_t *phdr, int *err, gchar **err_info);
void pcap_read_post_process(int subtype, int encap, packet_header_t *phdr, void *data, gboolean bytes_swapped, int fcslen);
gboolean wtap_read_bytes(FILE_T fh, void *buf, int size, int *err, gchar **err_info);
gboolean wtap_read_packet_bytes(FILE_T fh, void *buf, int size, int *err, gchar **err_info);
gboolean file_skip(FILE_T fh, int size, int *err);
void pcapng_debug(const char *fmt, ...);
void* ws_buffer_start_ptr(void *buf);
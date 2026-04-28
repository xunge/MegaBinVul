#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>

#define BT_SHB 0x0A0D0D0A
#define BYTE_ORDER_MAGIC 0x1A2B3C4D
#define PCAP_ERRBUF_SIZE 256
#define INITIAL_MAX_BLOCKSIZE 65536
#define PCAP_NG_VERSION_MAJOR 1
#define PCAP_NG_VERSION_MINOR 0
#define BT_SHB_INSANE_MAX (256*1024*1024)
#define BT_IDB 0x00000001
#define BT_EPB 0x00000006
#define BT_SPB 0x00000007
#define BT_PB 0x00000002

#define SWAPLONG(x) \
    ((((x) & 0xff000000) >> 24) | \
     (((x) & 0x00ff0000) >> 8)  | \
     (((x) & 0x0000ff00) << 8)  | \
     (((x) & 0x000000ff) << 24))
#define SWAPSHORT(x) \
    ((((x) & 0xff00) >> 8) | \
     (((x) & 0x00ff) << 8))

typedef unsigned int bpf_u_int32;
typedef uint64_t bpf_u_int64;
typedef unsigned short u_short;
typedef unsigned char u_char;
typedef unsigned int u_int;

struct block_header {
    bpf_u_int32 block_type;
    bpf_u_int32 total_length;
};

struct section_header_block {
    bpf_u_int32 byte_order_magic;
    u_short major_version;
    u_short minor_version;
    bpf_u_int64 section_length;
};

struct block_trailer {
    bpf_u_int32 total_length;
};

struct interface_description_block {
    u_short linktype;
    u_short reserved;
    bpf_u_int32 snaplen;
};

struct block_cursor {
    u_char *data;
    size_t data_remaining;
    bpf_u_int32 block_type;
};

struct pcap_ng_sf {
    bpf_u_int32 user_tsresol;
    bpf_u_int32 max_blocksize;
    void *ifaces;
};

struct pcap_opt {
    int tstamp_precision;
};

struct pcap {
    int swapped;
    void *priv;
    struct pcap_opt opt;
    size_t bufsize;
    u_char *buffer;
    int version_major;
    int version_minor;
    int tzoff;
    int linktype;
    int snapshot;
    int linktype_ext;
    void (*next_packet_op)(struct pcap *);
    void (*cleanup_op)(struct pcap *);
};

typedef struct pcap pcap_t;

enum {
    PCAP_TSTAMP_PRECISION_MICRO,
    PCAP_TSTAMP_PRECISION_NANO
};

#define PRIsize "zu"

void pcap_fmt_errmsg_for_errno(char *, int, int, const char *);
int pcap_snprintf(char *, size_t, const char *, ...);
pcap_t *pcap_open_offline_common(char *, size_t);
int read_bytes(FILE *, u_char *, size_t, int, char *);
int read_block(FILE *, pcap_t *, struct block_cursor *, char *);
struct interface_description_block *get_from_block_data(struct block_cursor *, size_t, char *);
int add_interface(pcap_t *, struct block_cursor *, char *);
int linktype_to_dlt(int);
int pcap_adjust_snapshot(int, int);
int max_snaplen_for_dlt(int);
#define MAX_BLOCKSIZE_FOR_SNAPLEN(x) ((x) + 4096)
void pcap_ng_next_packet(pcap_t *);
void pcap_ng_cleanup(pcap_t *);
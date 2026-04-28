#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>

#define BT_SHB 0x0A0D0D0A
#define BYTE_ORDER_MAGIC 0x1A2B3C4D
#define PCAP_ERRBUF_SIZE 256
#define PCAP_NG_VERSION_MAJOR 1
#define PCAP_NG_VERSION_MINOR 0
#define INITIAL_MAX_BLOCKSIZE (64*1024*1024)
#define BT_IDB 0x00000001
#define BT_EPB 0x00000006
#define BT_SPB 0x00000007
#define BT_PB 0x00000002
#define PCAP_TSTAMP_PRECISION_MICRO 0
#define PCAP_TSTAMP_PRECISION_NANO 1
#define BT_SHB_INSANE_MAX (256*1024*1024)

typedef uint32_t bpf_u_int32;
typedef uint16_t u_short;
typedef uint8_t u_char;
typedef unsigned int u_int;
typedef uint64_t bpf_u_int64;

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

struct pcap_ng_sf {
    u_int user_tsresol;
    u_int max_blocksize;
    void *ifaces;
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

struct pcap_pkthdr;

struct pcap_opt {
    int tstamp_precision;
};

struct pcap {
    int swapped;
    int version_major;
    int version_minor;
    int tzoff;
    int linktype;
    int snapshot;
    int linktype_ext;
    size_t bufsize;
    u_char *buffer;
    struct pcap_opt opt;
    void *priv;
    int (*next_packet_op)(struct pcap *, struct pcap_pkthdr *, u_char **);
    void (*cleanup_op)(struct pcap *);
};

typedef struct pcap pcap_t;

#define SWAPLONG(x) \
    ((((x) & 0xff000000) >> 24) | \
     (((x) & 0x00ff0000) >> 8)  | \
     (((x) & 0x0000ff00) << 8)  | \
     (((x) & 0x000000ff) << 24))
#define SWAPSHORT(x) \
    ((((x) & 0xff00) >> 8) | \
     (((x) & 0x00ff) << 8))

extern int read_bytes(FILE *, u_char *, size_t, int, char *);
extern int read_block(FILE *, pcap_t *, struct block_cursor *, char *);
extern void *get_from_block_data(struct block_cursor *, size_t, char *);
extern int add_interface(pcap_t *, struct block_cursor *, char *);
extern int linktype_to_dlt(int);
extern int pcap_adjust_snapshot(int, int);
extern int max_snaplen_for_dlt(int);
extern int MAX_BLOCKSIZE_FOR_SNAPLEN(int);
extern void pcap_fmt_errmsg_for_errno(char *, int, int, const char *);
extern int pcap_snprintf(char *, size_t, const char *, ...);
extern pcap_t *pcap_open_offline_common(char *, size_t);
extern int pcap_ng_next_packet(pcap_t *, struct pcap_pkthdr *, u_char **);
extern void pcap_ng_cleanup(pcap_t *);

#define PRIsize "zu"
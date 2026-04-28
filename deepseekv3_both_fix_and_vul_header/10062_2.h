#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <inttypes.h>

#define TCPDUMP_MAGIC 0xa1b2c3d4
#define KUZNETZOV_TCPDUMP_MAGIC 0xa1b2cd34
#define FMESQUITA_TCPDUMP_MAGIC 0xa1b2cf4d
#define NAVTEL_TCPDUMP_MAGIC 0xa12b3c4d
#define NSEC_TCPDUMP_MAGIC 0xa1b23c4d

#define SWAPLONG(x) ((((x)&0xff)<<24) | (((x)&0xff00)<<8) | (((x)&0xff0000)>>8) | (((x)>>24)&0xff))
#define SWAPSHORT(x) ((((x)&0xff)<<8) | (((x)&0xff00)>>8))

struct pcap_file_header {
    uint32_t magic;
    uint16_t version_major;
    uint16_t version_minor;
    int32_t thiszone;
    uint32_t sigfigs;
    uint32_t snaplen;
    uint32_t linktype;
};

struct pcap_pkthdr {
    struct {
        int32_t tv_sec;
        int32_t tv_usec;
    } ts;
    uint32_t caplen;
    uint32_t len;
};

struct pcap_sf_patched_pkthdr {
    struct {
        int32_t tv_sec;
        int32_t tv_usec;
    } ts;
    uint32_t caplen;
    uint32_t len;
    uint32_t index;
    uint16_t protocol;
    uint8_t pkt_type;
    uint8_t pkt_hasdata;
};

static const char *is_swapped = "swapped";
static const char *is_not_swapped = "not swapped";

static struct {
    int dummy;
} tcpcapinfoOptions;

static int optionProcess(void *opts, int argc, char **argv) {
    return 0;
}

static int HAVE_OPT(int opt) {
    return 0;
}

static int OPT_VALUE_DBUG = 0;

extern int debug;
extern void dbgx(int, const char *, ...);
extern void dbg(int, const char *, ...);
extern void errx(int, const char *, ...);
extern uint16_t do_checksum_math(u_int16_t *, int32_t);
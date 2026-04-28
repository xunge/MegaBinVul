#include <stdio.h>
#include <stdint.h>

#define NETSCREEN_LINE_LENGTH 1024
#define NETSCREEN_MAX_INT_NAME_LENGTH 64

typedef int gboolean;
typedef char gchar;
typedef int64_t gint64;

typedef struct wtap wtap;
typedef struct wtap_pkthdr {
    int pkt_encap;
} wtap_pkthdr;

struct wtap {
    FILE *fh;
    wtap_pkthdr phdr;
    int file_encap;
    void *frame_buffer;
};

static gint64 netscreen_seek_next_packet(wtap *wth, int *err, gchar **err_info, char *line);
static int parse_netscreen_rec_hdr(wtap_pkthdr *phdr, char *line, char *cap_int, gboolean *cap_dir, char *cap_dst, int *err, gchar **err_info);
static gboolean parse_netscreen_hex_dump(FILE *fh, int pkt_len, char *cap_int, char *cap_dst, wtap_pkthdr *phdr, void *frame_buffer, int *err, gchar **err_info);

#define WTAP_ENCAP_UNKNOWN 0
#define WTAP_ENCAP_PER_PACKET 1
#define FALSE 0
#define TRUE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

#define TOSHIBA_LINE_LENGTH 256
#define TOSHIBA_MAX_PACKET_LEN 65535
#define WTAP_MAX_PACKET_SIZE 65535

#define FALSE 0
#define TRUE 1
#define REC_TYPE_PACKET 0

typedef int gboolean;
typedef char gchar;
typedef uint8_t guint8;
typedef unsigned int guint;

enum wtap_encap {
    WTAP_ENCAP_ETHERNET,
    WTAP_ENCAP_ISDN
};

#define WTAP_HAS_TS 0x01
#define WTAP_HAS_CAP_LEN 0x02

enum wtap_err {
    WTAP_ERR_SHORT_READ,
    WTAP_ERR_BAD_FILE
};

typedef struct {
    int fcs_len;
} eth_pseudo_header;

typedef struct {
    gboolean uton;
    guint8 channel;
} isdn_pseudo_header;

union wtap_pseudo_header {
    eth_pseudo_header eth;
    isdn_pseudo_header isdn;
};

struct wtap_pkthdr {
    int rec_type;
    int presence_flags;
    struct {
        int secs;
        int nsecs;
    } ts;
    int caplen;
    int len;
    int pkt_encap;
    union wtap_pseudo_header pseudo_header;
};

typedef FILE* FILE_T;

typedef struct {
    guint8 *data;
    size_t allocated;
    size_t length;
} Buffer;

static char* file_gets(char *s, int size, FILE_T stream) {
    return fgets(s, size, stream);
}

static int file_error(FILE_T fh, gchar **err_info) {
    *err_info = strdup("File error");
    return ferror(fh);
}

static gboolean parse_single_hex_dump_line(char *line, guint8 *pd, int offset) {
    return TRUE;
}

#define ws_buffer_start_ptr(buf) ((buf)->data)
#define ws_buffer_assure_space(buf, size) \
    do { \
        if ((size) > (buf)->allocated) { \
            (buf)->data = realloc((buf)->data, (size)); \
            (buf)->allocated = (size); \
        } \
    } while (0)

#define g_strdup strdup
#define g_strdup_printf sprintf
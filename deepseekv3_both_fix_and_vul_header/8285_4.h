#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

#define COSINE_MAX_IF_NAME_LEN 128
#define COSINE_LINE_LENGTH 256
#define WTAP_MAX_PACKET_SIZE 65535
#define WTAP_ERR_BAD_FILE 1
#define WTAP_ERR_SHORT_READ 2
#define WTAP_HAS_TS 0x01
#define WTAP_HAS_CAP_LEN 0x02

typedef int gboolean;
#define FALSE 0
#define TRUE 1
typedef unsigned int guint;
typedef unsigned char guint8;
typedef char gchar;

enum {
    COSINE_ENCAP_TEST,
    COSINE_ENCAP_PPoATM,
    COSINE_ENCAP_PPoFR,
    COSINE_ENCAP_ATM,
    COSINE_ENCAP_FR,
    COSINE_ENCAP_HDLC,
    COSINE_ENCAP_PPP,
    COSINE_ENCAP_ETH,
    COSINE_ENCAP_UNKNOWN
};

enum {
    COSINE_DIR_TX,
    COSINE_DIR_RX
};

typedef enum {
    REC_TYPE_PACKET
} rec_type_t;

typedef struct {
    int encap;
    int direction;
    char if_name[COSINE_MAX_IF_NAME_LEN];
    int pro;
    int off;
    int pri;
    int rm;
    int err;
} cosine_pseudo_header_t;

typedef union wtap_pseudo_header {
    cosine_pseudo_header_t cosine;
} wtap_pseudo_header;

struct wtap_pkthdr {
    rec_type_t rec_type;
    int presence_flags;
    struct {
        time_t secs;
        int nsecs;
    } ts;
    unsigned int len;
    unsigned int caplen;
    wtap_pseudo_header pseudo_header;
};

typedef struct {
    size_t size;
    size_t allocated;
    guint8 *data;
} Buffer;

typedef FILE* FILE_T;

static char* g_strdup(const char* str) {
    return strdup(str);
}

static char* g_strdup_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    int len = vsnprintf(NULL, 0, format, args);
    va_end(args);
    
    char* buf = malloc(len + 1);
    if (buf) {
        va_start(args, format);
        vsnprintf(buf, len + 1, format, args);
        va_end(args);
    }
    return buf;
}

static size_t g_strlcpy(char* dest, const char* src, size_t dest_size) {
    return strlcpy(dest, src, dest_size);
}

static int empty_line(char* line) {
    while (*line) {
        if (!isspace(*line)) {
            return 0;
        }
        line++;
    }
    return 1;
}

static int file_gets(char* line, int length, FILE_T fh) {
    return fgets(line, length, fh) ? 0 : -1;
}

static int file_error(FILE_T fh, gchar** err_info) {
    *err_info = strdup(ferror(fh) ? "File error" : "Unknown error");
    return ferror(fh) ? WTAP_ERR_BAD_FILE : 0;
}

static void ws_buffer_assure_space(Buffer* buf, size_t size) {
    if (buf->allocated < size) {
        buf->data = realloc(buf->data, size);
        buf->allocated = size;
    }
    buf->size = size;
}

static guint8* ws_buffer_start_ptr(Buffer* buf) {
    return buf->data;
}

static int parse_single_hex_dump_line(char* line, guint8* pd, int offset) {
    int n = 0;
    unsigned int byte;
    char* ptr = line;
    
    while (sscanf(ptr, "%2x", &byte) == 1) {
        pd[offset + n] = (guint8)byte;
        n++;
        ptr += 2;
        while (*ptr == ' ') ptr++;
    }
    return n;
}
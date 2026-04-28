#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define NETSCREEN_LINE_LENGTH 1024
#define NETSCREEN_MAX_INT_NAME_LENGTH 64
#define WTAP_ERR_SHORT_READ -1
#define TRUE 1
#define FALSE 0

typedef struct wtap {
    FILE *random_fh;
} wtap;

typedef struct wtap_pkthdr wtap_pkthdr;
typedef struct Buffer Buffer;

typedef int64_t gint64;
typedef int gboolean;
typedef char gchar;

int file_seek(FILE *fh, gint64 offset, int whence, int *err);
char *file_gets(char *buf, int size, FILE *fh);
int file_error(FILE *fh, gchar **err_info);
int parse_netscreen_rec_hdr(wtap_pkthdr *phdr, char *line, char *cap_int, gboolean *cap_dir, char *cap_dst, int *err, gchar **err_info);
gboolean parse_netscreen_hex_dump(FILE *fh, int pkt_len, char *cap_int, char *cap_dst, wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info);
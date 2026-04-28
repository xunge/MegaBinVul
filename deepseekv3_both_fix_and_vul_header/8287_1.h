#include <stdint.h>
#include <stdbool.h>

#define COSINE_LINE_LENGTH 1024
#define FALSE false
typedef int64_t gint64;
typedef bool gboolean;
typedef char gchar;

typedef struct wtap {
    struct {
        int phdr;
    } phdr;
    int fh;
    char *frame_buffer;
} wtap;

static gint64 cosine_seek_next_packet(wtap *wth, int *err, gchar **err_info, char *line);
static int parse_cosine_rec_hdr(int *phdr, char *line, int *err, gchar **err_info);
static gboolean parse_cosine_hex_dump(int fh, int *phdr, int pkt_len, char *frame_buffer, int *err, gchar **err_info);
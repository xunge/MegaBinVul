#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

#define MP2T_SIZE 188
#define TRAILER_LEN_MAX 16
#define MP2T_SYNC_BYTE 0x47
#define SYNC_STEPS 10
#define WTAP_ERR_SHORT_READ -1
#define WTAP_FILE_TYPE_SUBTYPE_MPEG_2_TS 1
#define WTAP_ENCAP_MPEG_2_TS 1
#define WTAP_TSPREC_NSEC 1
#define SEEK_SET 0

typedef uint8_t guint8;
typedef unsigned int guint;
typedef uint64_t guint64;
typedef char gchar;

typedef enum {
    WTAP_OPEN_MINE,
    WTAP_OPEN_NOT_MINE,
    WTAP_OPEN_ERROR
} wtap_open_return_val;

typedef struct wtap {
    int fh;
    int file_type_subtype;
    int file_encap;
    int file_tsprec;
    void (*subtype_read)(struct wtap *wth);
    void (*subtype_seek_read)(struct wtap *wth);
    int snapshot_length;
    void *priv;
} wtap;

typedef struct {
    int start_offset;
    guint8 trailer_len;
    guint64 bitrate;
} mp2t_filetype_t;

extern int file_seek(int fd, off_t offset, int whence, int *err);
extern int wtap_read_bytes(int fh, guint8 *buf, int size, int *err, gchar **err_info);
extern wtap_open_return_val mp2t_bits_per_second(wtap *wth, int first, guint8 trailer_len, guint64 *bitrate, int *err, gchar **err_info);
extern void* g_malloc(size_t size);
extern void mp2t_read(wtap *wth);
extern void mp2t_seek_read(wtap *wth);
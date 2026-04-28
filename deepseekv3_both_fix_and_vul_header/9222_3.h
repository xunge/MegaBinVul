#include <stdint.h>
#include <stdbool.h>

#define MP2T_SIZE 188
#define TRAILER_LEN_MAX 256
#define MP2T_SYNC_BYTE 0x47
#define FALSE false
#define TRUE true

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef bool gboolean;
typedef char gchar;

typedef struct wtap {
    void *fh;
} wtap;

guint64 mp2t_read_pcr(const guint8 *buffer);
guint16 pntoh16(const guint8 *buffer);
bool wtap_read_bytes_or_eof(void *fh, guint8 *buffer, int size, int *err, gchar **err_info);
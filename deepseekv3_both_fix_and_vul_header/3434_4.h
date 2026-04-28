#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <arpa/inet.h>

#define FALSE 0
#define TRUE 1
typedef int gboolean;
typedef int64_t gint64;
typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef uint64_t guint64;
typedef char gchar;

#define PES_VALID(n) (0)
#define MPA_UNMARSHAL(mpa, n) do { } while (0)
#define MPA_VALID(mpa) (0)
#define MPA_BYTES(mpa) (0)
#define MPA_DURATION_NS(mpa) (0)
#define SCRHZ (27000000)
#define WTAP_MAX_PACKET_SIZE (65535)
#define WTAP_HAS_TS (1)
#define WTAP_ERR_SHORT_READ (1)
#define WTAP_ERR_BAD_FILE (2)

struct wtap_nstime {
    time_t secs;
    int nsecs;
};

struct wtap_phdr {
    int presence_flags;
    struct wtap_nstime ts;
    unsigned int caplen;
    unsigned int len;
};

struct wtap {
    void *priv;
    void *fh;
    void *frame_buffer;
    struct wtap_phdr phdr;
};

typedef struct wtap wtap;
typedef struct mpeg_t {
    struct wtap_nstime now;
    time_t t0;
} mpeg_t;

typedef struct mpa {
    int dummy;
} mpa;

static inline uint32_t g_ntohl(uint32_t x) { return ntohl(x); }
static inline uint16_t g_ntohs(uint16_t x) { return ntohs(x); }
#define G_GINT64_CONSTANT(x) (x##LL)

extern int mpeg_read_header(struct wtap *wth, int *err, gchar **err_info, guint32 *n);
extern int mpeg_resync(struct wtap *wth, int *err, gchar **err_info);
extern gint64 file_tell(void *fh);
extern int file_seek(void *fh, gint64 offset, int whence, int *err);
extern int file_read(void *buf, size_t size, void *fh);
extern int file_error(void *fh, gchar **err_info);
extern void buffer_assure_space(void *frame_buffer, size_t size);
extern guint8 *buffer_start_ptr(void *frame_buffer);
extern gboolean mpeg_read_rec_data(void *fh, void *buf, size_t size, int *err, gchar **err_info);
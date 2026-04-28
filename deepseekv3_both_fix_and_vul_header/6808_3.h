#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define MAGIC_SIZE 4
#define NUM_NETMON_ENCAPS 256
#define WORDS_BIGENDIAN 0
#define FALSE 0
#define TRUE 1
#define ENOMEM 12

typedef unsigned int guint32;
typedef unsigned short guint16;
typedef unsigned char guint8;
typedef long long gint64;
typedef char gchar;
typedef int gboolean;

typedef enum {
    WTAP_OPEN_ERROR,
    WTAP_OPEN_NOT_MINE,
    WTAP_OPEN_MINE
} wtap_open_return_val;

typedef enum {
    WTAP_ERR_SHORT_READ,
    WTAP_ERR_UNSUPPORTED,
    WTAP_ERR_BAD_FILE
} wtap_err;

typedef enum {
    WTAP_FILE_TYPE_SUBTYPE_NETMON_1_x,
    WTAP_FILE_TYPE_SUBTYPE_NETMON_2_x
} wtap_file_type_subtype;

typedef enum {
    WTAP_ENCAP_UNKNOWN,
    WTAP_ENCAP_PER_PACKET
} wtap_encap;

typedef enum {
    WTAP_TSPREC_MSEC,
    WTAP_TSPREC_NSEC
} wtap_tsprec;

typedef struct wtap {
    FILE *fh;
    int file_type_subtype;
    void *priv;
    int (*subtype_read)(struct wtap *, int *, gchar **);
    int (*subtype_seek_read)(struct wtap *, int *, gchar **, long long);
    void (*subtype_close)(struct wtap *);
    wtap_encap file_encap;
    int snapshot_length;
    wtap_tsprec file_tsprec;
} wtap;

typedef struct netmon_hdr {
    guint16 ver_major;
    guint16 ver_minor;
    guint16 network;
    guint16 ts_year;
    guint16 ts_month;
    guint16 ts_day;
    guint16 ts_hour;
    guint16 ts_min;
    guint16 ts_sec;
    guint16 ts_msec;
    guint32 frametableoffset;
    guint32 frametablelength;
    guint32 commentdataoffset;
    guint32 commentdatalength;
    guint32 processinfooffset;
    guint32 processinfocount;
} netmon_hdr;

typedef struct netmonrec_comment {
    guint32 numFramePerComment;
    guint32 frameOffset;
    guint32 titleLength;
    guint8 *title;
    guint32 descLength;
    guint8 *description;
} netmonrec_comment;

typedef struct netmonrec_comment_header {
    guint32 numFramePerComment;
    guint32 frameOffset;
    guint32 titleLength;
} netmonrec_comment_header;

typedef struct netmonrec_process_info {
    guint32 pathSize;
    guint8 *path;
    guint32 iconSize;
    guint32 pid;
    guint16 localPort;
    guint16 remotePort;
    gboolean isIPv6;
    union {
        guint32 ipv4;
        guint8 ipv6[16];
    } localAddr;
    union {
        guint32 ipv4;
        guint8 ipv6[16];
    } remoteAddr;
} netmonrec_process_info;

typedef struct netmon_t {
    time_t start_secs;
    guint32 start_nsecs;
    guint16 version_major;
    guint16 version_minor;
    guint32 *frame_table;
    guint32 frame_table_size;
    void *comment_table;
    void *process_info_table;
    guint32 current_frame;
} netmon_t;

typedef struct GHashTable GHashTable;

extern const char netmon_1_x_magic[MAGIC_SIZE];
extern const char netmon_2_x_magic[MAGIC_SIZE];
extern int netmon_encap[NUM_NETMON_ENCAPS];
extern int (*netmon_read)(wtap *, int *, gchar **);
extern int (*netmon_seek_read)(wtap *, int *, gchar **, long long);
extern void (*netmon_close)(wtap *);
extern gint64 (*wtap_file_size)(wtap *, int *);
extern int (*wtap_read_bytes)(FILE *, void *, size_t, int *, gchar **);
extern int (*file_seek)(FILE *, long, int, int *);
extern void (*netmonrec_comment_destroy)(void *);
extern void (*netmonrec_process_info_destroy)(void *);

void *g_malloc0(size_t size);
void *g_try_malloc(size_t size);
void g_free(void *ptr);
void *g_malloc(size_t size);
void *g_new(size_t n_structs, size_t struct_size);
void *g_new0(size_t n_structs, size_t struct_size);
char *g_strdup(const char *str);
char *g_strdup_printf(const char *format, ...);
GHashTable *g_hash_table_new_full(unsigned int (*hash_func)(const void *),
                                 int (*key_equal_func)(const void *, const void *),
                                 void (*key_destroy_func)(void *),
                                 void (*value_destroy_func)(void *));
void g_hash_table_destroy(GHashTable *hash_table);
void g_hash_table_insert(GHashTable *hash_table, void *key, void *value);
unsigned int g_direct_hash(const void *v);
int g_direct_equal(const void *v1, const void *v2);
void *GUINT_TO_POINTER(guint32 u);

guint16 pletoh16(const void *p);
guint32 pletoh32(const void *p);

#define g_new(type, count) ((type*)g_malloc(sizeof(type) * (count)))
#define g_new0(type, count) ((type*)g_malloc0(sizeof(type) * (count)))
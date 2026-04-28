#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef unsigned int guint;
typedef unsigned char guint8;
typedef unsigned short guint16;
typedef unsigned int guint32;
typedef int gboolean;
#define FALSE 0
#define TRUE 1
typedef char gchar;
typedef void* gpointer;

typedef struct _pcapng_block_header {
    guint32 block_total_length;
} pcapng_block_header_t;

typedef struct _pcapng_t {
    gboolean byte_swapped;
    void (*add_new_ipv4)(guint32 addr, const char* name);
    void (*add_new_ipv6)(const void* addr, const char* name);
} pcapng_t;

typedef struct _wtapng_block_t {
    void* block;
} wtapng_block_t;

typedef struct _pcapng_name_resolution_block_t {
    guint16 record_type;
    guint16 record_len;
} pcapng_name_resolution_block_t;

typedef struct _Buffer {
    void* data;
    size_t size;
} Buffer;

typedef struct _pcapng_option_header_t {
    guint16 option_code;
    guint16 option_length;
} pcapng_option_header_t;

typedef struct _option_handler {
    gboolean (*hfunc)(gboolean byte_swapped, guint length, guint8* content, int* err, gchar** err_info);
} option_handler;

#define FILE_T FILE*
#define MIN_NRB_SIZE 12
#define MAX_BLOCK_SIZE (256*1024*1024)
#define WTAP_ERR_BAD_FILE 1
#define WTAP_BLOCK_NG_NRB 1
#define INITIAL_NRB_REC_SIZE 80
#define PADDING4(len) ((4 - ((len) % 4)) % 4)
#define GUINT16_SWAP_LE_BE(val) (val)
#define NRES_ENDOFRECORD 0
#define NRES_IP4RECORD 1
#define NRES_IP6RECORD 2
#define OPT_EOFOPT 0
#define OPT_COMMENT 1
#define ENOMEM 12
#define BT_INDEX_NRB 0

static inline char* g_strdup_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    int size = vsnprintf(NULL, 0, format, args) + 1;
    va_end(args);
    
    char* buf = malloc(size);
    if (buf) {
        va_start(args, format);
        vsnprintf(buf, size, format, args);
        va_end(args);
    }
    return buf;
}

static inline void* g_try_malloc(size_t size) {
    return malloc(size);
}

static inline void g_free(void* ptr) {
    free(ptr);
}

static inline char* g_strndup(const char* str, size_t n) {
    char* buf = malloc(n + 1);
    if (buf) {
        strncpy(buf, str, n);
        buf[n] = '\0';
    }
    return buf;
}

gboolean wtap_read_bytes(FILE_T fh, void *buf, size_t count, int *err, gchar **err_info);
gboolean file_skip(FILE_T fh, int len, int *err);
void ws_buffer_init(Buffer *buf, size_t initial_size);
void ws_buffer_free(Buffer *buf);
void ws_buffer_assure_space(Buffer *buf, size_t required_size);
gpointer ws_buffer_start_ptr(Buffer *buf);
int name_resolution_block_find_name_end(char *namep, guint record_len, int *err, gchar **err_info);
wtapng_block_t *wtap_block_create(int block_type);
void wtap_block_add_string_option(wtapng_block_t *block, int option_code, guint8 *content, guint length);
void pcapng_debug(const char *fmt, ...);
gboolean pcapng_read_option(FILE_T fh, pcapng_t *pn, pcapng_option_header_t *oh, guint8 *option_content, guint opt_cont_buf_len, guint to_read, int *err, gchar **err_info, const char *block_type);
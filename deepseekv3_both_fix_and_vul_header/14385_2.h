#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef int gboolean;
#define TRUE 1
#define FALSE 0

typedef unsigned int guint;
typedef unsigned char guint8;
typedef unsigned short guint16;
typedef char gchar;

typedef struct wtapng_block_t wtapng_block_t;
typedef struct section_info_t {
    gboolean byte_swapped;
} section_info_t;

typedef enum {
    OPT_SECTION_BYTE_ORDER,
    OPT_BIG_ENDIAN, 
    OPT_LITTLE_ENDIAN
} pcapng_opt_byte_order_e;

typedef struct {
    guint16 option_code;
    guint16 option_length;
} pcapng_option_header_t;

#define WTAP_ERR_BAD_FILE 1
#define WTAP_ERR_INTERNAL 2

#define OPT_EOFOPT 0
#define OPT_COMMENT 1
#define OPT_CUSTOM_STR_COPY 2
#define OPT_CUSTOM_BIN_COPY 3
#define OPT_CUSTOM_STR_NO_COPY 4
#define OPT_CUSTOM_BIN_NO_COPY 5

#define ROUND_TO_4BYTE(len) (((len) + 3) & ~3)

#define GUINT16_SWAP_LE_BE(val) ((guint16)(((guint16)(val) << 8) | ((guint16)(val) >> 8)))
#define GUINT16_FROM_BE(val) (val)
#define GUINT16_FROM_LE(val) GUINT16_SWAP_LE_BE(val)

#define ws_debug(...)

typedef FILE* FILE_T;

static inline void* g_try_malloc(size_t size) { return malloc(size); }
static inline void g_free(void* ptr) { free(ptr); }
static inline char* g_strdup_printf(const char* format, ...) { return strdup(""); }

gboolean wtap_read_bytes(FILE_T fh, void *buf, unsigned size, int *err, gchar **err_info);
gboolean pcapng_process_string_option(wtapng_block_t *wblock, guint16 option_code, guint16 option_length, const guint8 *option_ptr);
gboolean pcapng_process_custom_option(wtapng_block_t *wblock, const section_info_t *section_info, guint16 option_code, guint16 option_length, const guint8 *option_ptr, pcapng_opt_byte_order_e byte_order, int *err, gchar **err_info);
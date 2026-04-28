#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef bool gboolean;
typedef uint8_t guint8;
typedef uint32_t guint32;
typedef char gchar;

#define FALSE false
#define TRUE true

typedef struct {
    guint32 id;
    gboolean is_fd;
    guint8 flags;
    struct {
        guint8 length;
        guint8 data[64];
    } data;
    struct nstime {
        int64_t sec;
        int32_t usec;
    } ts;
} msg_t;

typedef struct {
    guint32 can_id;
    guint8 can_dlc;
    guint8 data[8];
} can_frame_t;

typedef struct {
    guint32 can_id;
    guint8 flags;
    guint8 len;
    guint8 data[64];
} canfd_frame_t;

typedef struct {
    int rec_type;
    void* block;
    int presence_flags;
    struct nstime ts;
    int tsprec;
    struct {
        struct {
            guint32 caplen;
            guint32 len;
        } packet_header;
    } rec_header;
} wtap_rec;

typedef struct Buffer Buffer;

#define CAN_MAX_DLEN 8
#define CANFD_MAX_DLEN 64
#define EXP_PDU_TAG_DISSECTOR_NAME 0x00
#define WTAP_ERR_BAD_FILE 0
#define WTAP_BLOCK_PACKET 0
#define WTAP_HAS_TS 0
#define WTAP_TSPREC_USEC 0
#define REC_TYPE_PACKET 0

static void ws_buffer_clean(Buffer* buf) {}
static void wtap_buffer_append_epdu_tag(Buffer* buf, int tag, const guint8* data, size_t len) {}
static void wtap_buffer_append_epdu_end(Buffer* buf) {}
static void ws_buffer_append(Buffer* buf, const guint8* data, size_t len) {}
static size_t ws_buffer_length(Buffer* buf) { return 0; }
static void* wtap_block_create(int block_type) { return NULL; }
static char* ws_strdup_printf(const char* format, ...) { return NULL; }
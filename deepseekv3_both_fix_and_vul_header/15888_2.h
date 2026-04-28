#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct block_t {
    uint8_t *p_buffer;
    int64_t i_dts;
    int64_t i_pts;
    uint32_t i_flags;
} block_t;

typedef struct picture_t {
    struct {
        int i_chroma;
    } format;
    bool b_progressive;
    bool b_top_field_first;
    int64_t date;
} picture_t;

typedef struct encoder_t {
    struct {
        int i_codec;
        struct {
            int i_frame_rate;
            int i_frame_rate_base;
        } video;
    } fmt_in;
    struct {
        void *p_extra;
        int i_extra;
    } fmt_out;
    struct encoder_sys_t *p_sys;
} encoder_t;

typedef struct encoder_sys_t {
    bool started;
    bool b_eos_pulled;
    bool b_eos_signalled;
    bool b_auto_field_coding;
    void *p_schro;
    struct SchroVideoFormat *p_format;
    int64_t i_pts_offset;
    int64_t i_field_time;
    uint32_t i_input_picnum;
    void *p_dts_fifo;
} encoder_sys_t;

typedef struct SchroFrame SchroFrame;
typedef struct SchroBuffer {
    uint8_t *data;
    uint32_t length;
} SchroBuffer;
typedef struct SchroVideoFormat {
    bool interlaced;
    bool top_field_first;
} SchroVideoFormat;

typedef struct date_t {
    int64_t date;
} date_t;

typedef enum SchroStateEnum {
    SCHRO_STATE_NEED_FRAME,
    SCHRO_STATE_AGAIN,
    SCHRO_STATE_END_OF_STREAM,
    SCHRO_STATE_HAVE_BUFFER
} SchroStateEnum;

enum {
    SCHRO_SIGNAL_RANGE_8BIT_VIDEO
};

#define BLOCK_FLAG_TYPE_I (1 << 0)

static void schro_encoder_end_of_stream(void *encoder);
static void schro_encoder_setting_set_double(void *encoder, const char *setting, double value);
static double schro_encoder_setting_get_double(void *encoder, const char *setting);
static void schro_encoder_set_video_format(void *encoder, SchroVideoFormat *format);
static void schro_encoder_start(void *encoder);
static SchroStateEnum schro_encoder_wait(void *encoder);
static SchroBuffer *schro_encoder_pull(void *encoder, int *presentation_frame);
static void schro_encoder_push_frame(void *encoder, SchroFrame *frame);
static void schro_buffer_unref(SchroBuffer *buffer);
static void schro_video_format_set_std_signal_range(SchroVideoFormat *format, int range);

static void vlc_fourcc_to_char(int fourcc, char *buf);
static void msg_Warn(encoder_t *enc, const char *fmt, ...);
static void msg_Err(encoder_t *enc, const char *fmt, ...);
static bool SetEncChromaFormat(encoder_t *enc, int chroma);

static void date_Init(date_t *date, int frame_rate, int frame_rate_base);
static void date_Increment(date_t *date, int inc);
static int64_t date_Get(date_t *date);
static void date_Set(date_t *date, int64_t value);

static void picture_Hold(picture_t *pic);
static SchroFrame *CreateSchroFrameFromInputPic(encoder_t *p_enc, picture_t *p_pic);
static void StorePicturePTS(encoder_t *enc, uint32_t picnum, int64_t pts);
static int64_t GetPicturePTS(encoder_t *enc, uint32_t picnum);
static bool ReadDiracPictureNumber(uint32_t *picnum, block_t *block);

static block_t *block_Alloc(size_t size);
static void block_FifoPut(void *fifo, block_t *block);
static block_t *block_FifoGet(void *fifo);
static void block_Release(block_t *block);
static void block_ChainAppend(block_t **chain, block_t *block);

static uint32_t GetDWBE(const uint8_t *p);
static void SetDWBE(uint8_t *p, uint32_t value);
#include <stdint.h>
#include <string.h>

#define MAX_NB_ARGS 16
#define FONT_WIDTH 8
#define AVPALETTE_SIZE (256 * 4)

enum {
    STATE_NORMAL,
    STATE_ESCAPE,
    STATE_CODE,
    STATE_MUSIC_PREAMBLE
};

enum AVLogLevel {
    AV_LOG_WARNING
};

enum AVPictureType {
    AV_PICTURE_TYPE_I
};

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int pict_type;
    int palette_has_changed;
} AVFrame;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVCodecContext {
    void *priv_data;
    int height;
    int width;
    int frame_number;
} AVCodecContext;

typedef struct AnsiContext {
    int state;
    int x;
    int first_frame;
    int nb_args;
    int args[MAX_NB_ARGS];
    AVFrame *frame;
} AnsiContext;

#define FFMAX(a, b) ((a) > (b) ? (a) : (b))

int ff_reget_buffer(AVCodecContext *avctx, AVFrame *frame);
void set_palette(uint32_t *palette);
void erase_screen(AVCodecContext *avctx);
void draw_char(AVCodecContext *avctx, char c);
void hscroll(AVCodecContext *avctx);
int execute_code(AVCodecContext *avctx, char code);
int av_frame_ref(void *dst, AVFrame *src);
void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
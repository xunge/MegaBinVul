#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVDictionary AVDictionary;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int format;
    AVDictionary *metadata;
} AVFrame;

typedef struct AVPixFmtDescriptor {
    int nb_components;
    int log2_chroma_w;
    int log2_chroma_h;
} AVPixFmtDescriptor;

typedef struct H264Context {
    int pixel_shift;
    int chroma_x_shift;
    int chroma_y_shift;
} H264Context;

typedef struct Picture {
    AVFrame f;
    int crop;
    int crop_left;
    int crop_top;
} Picture;

const AVPixFmtDescriptor *av_pix_fmt_desc_get(int format);
int av_frame_ref(AVFrame *dst, const AVFrame *src);
void av_dict_set(AVDictionary **pm, const char *key, const char *value, int flags);
const char *ff_h264_sei_stereo_mode(H264Context *h);
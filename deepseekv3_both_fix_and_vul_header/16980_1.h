#include <stdint.h>
#include <string.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
#define FDNULL (-1)

typedef struct {
    int is_video;
    int have_mpeg2;
    int h;
    int w;
    double frame_rate;
    int bit_rate;
    int par;
    int m_stream_id;
    int m_fd;
    u64 ticks_per_frame;
    int channels;
    int freq;
    int samples_per_frame;
    int bitrate;
    int layer;
    int m_substream_id;
} mpeg2ps_stream_t;

typedef struct {
    int brcode;
    int sample_rate;
    struct {
        int channels;
    } streams[1];
} GF_AC3Config;

int MPEG12_ParseSeqHdr(u8 *buffer, u32 buflen, int *have_mpeg2, int *h, int *w, double *frame_rate, int *bit_rate, int *par);
u32 GF_4CC(u32 a, u32 b, u32 c, u32 d);
int gf_mp3_num_channels(u32 hdr);
int gf_mp3_sampling_rate(u32 hdr);
int gf_mp3_window_size(u32 hdr);
int gf_mp3_bit_rate(u32 hdr);
int gf_mp3_layer(u32 hdr);
void gf_ac3_parser(u8 *buffer, u32 buflen, u32 *pos, GF_AC3Config *hdr, int flags);
int gf_ac3_get_bitrate(int brcode);
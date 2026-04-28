#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int offset;
    int len;
    uint8_t* data;
} BT_HDR;

typedef struct {
    void* opus_handle;
    int16_t* decode_buf;
    void (*decode_callback)(uint8_t* data, size_t len);
} a2dp_opus_decoder_cb_t;

#define A2DP_OPUS_CODEC_DEFAULT_SAMPLERATE 48000
#define A2DP_OPUS_DECODE_BUFFER_LENGTH 960
#define OPUS_OK 0
#define LOG_ERROR(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

extern a2dp_opus_decoder_cb_t a2dp_opus_decoder_cb;

uint32_t opus_packet_get_nb_channels(const unsigned char* data);
uint32_t opus_packet_get_nb_frames(const unsigned char* data, int32_t len);
uint32_t opus_packet_get_samples_per_frame(const unsigned char* data, uint32_t rate);
uint32_t opus_packet_get_nb_samples(const unsigned char* data, int32_t len, uint32_t rate);
int32_t opus_decode(void* st, const unsigned char* data, int32_t len, int16_t* pcm, int32_t frame_size, int decode_fec);
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

struct audio_stream_common {
    int (*get_format)(struct audio_stream_common*);
};

struct audio_stream_in {
    struct audio_stream_common common;
};

struct audio_buffer_t {
    size_t frameCount;
    int16_t *s16;
};

struct effect_itfe {
    void (*process)(struct effect_itfe*, struct audio_buffer_t*, struct audio_buffer_t*);
};

struct preprocessor {
    struct effect_itfe *effect_itfe;
};

struct stream_in {
    struct audio_stream_in audio;
    size_t num_preprocessors;
    struct preprocessor *preprocessors;
    struct {
        size_t channels;
    } config;
    size_t main_channels;
    size_t proc_buf_frames;
    size_t proc_buf_size;
    void *proc_buf_in;
    void *proc_buf_out;
};

#define ALOG_ASSERT(cond, ...) \
    do { \
        if (!(cond)) { \
            fprintf(stderr, "ASSERT: " __VA_ARGS__); \
            abort(); \
        } \
    } while (0)
#define ALOGW(msg) fprintf(stderr, "WARNING: %s\n", msg)
#define ALOGE(msg, ...) fprintf(stderr, "ERROR: " msg, ##__VA_ARGS__)

size_t audio_bytes_per_sample(int format);
size_t audio_channel_count_from_in_mask(size_t mask);
ssize_t read_frames(struct stream_in *in, void *buffer, ssize_t frames);
int in_get_format(struct stream_in *in);
size_t adjust_channels(void *src, size_t src_channels, void *dst, size_t dst_channels, size_t bytes_per_sample, size_t size);
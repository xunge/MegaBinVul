#include <stdint.h>
#include <limits.h>
#include <stddef.h>

#define EINVAL 22
#define SND_AUDIOCODEC_MAX 255

struct snd_compr_params {
    struct {
        size_t fragment_size;
        size_t fragments;
    } buffer;
    struct {
        int id;
        int ch_in;
        int ch_out;
    } codec;
};
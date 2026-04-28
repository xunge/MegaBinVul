#include <stdint.h>
#include <stdbool.h>

#define HD_SYNC_WORLD 0x872807

class BitStreamReader {
public:
    void setBuffer(uint8_t* buffer, uint8_t* end);
    uint32_t getBits(int n);
    void skipBits(int n);
    bool getBit();
};

struct MLPHeaderInfo {
    enum SubType {
        stUnknown,
        stMLP,
        stTRUEHD
    };
    SubType subType;
    int stream_type;
    int group1_bits;
    int group2_bits;
    int group1_samplerate;
    int group2_samplerate;
    int channels_mlp;
    int channels_thd_stream1;
    int channels_thd_stream2;
    int channels;
    int access_unit_size;
    int access_unit_size_pow2;
    int64_t frame_duration_nano;
    bool is_vbr;
    int peak_bitrate;
    int num_substreams;
};

class AC3Codec {
public:
    MLPHeaderInfo mh;
    bool decodeDtsHdFrame(uint8_t* buffer, uint8_t* end);
};

extern const int mlp_quants[];
extern const int mlp_channels[];
extern int mlp_samplerate(int ratebits);
extern int truehd_channels(int channels);
#include <assert.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>

typedef int64_t AFframecount;

struct AFtrack {
    struct {
        int channelCount;
    } f;
    AFframecount nextfframe;
    AFframecount fpos_next_frame;
};

struct AFchunk {
    void *buffer;
    AFframecount frameCount;
};

class BlockCodec {
protected:
    AFchunk *m_inChunk;
    AFchunk *m_outChunk;
    int m_framesPerPacket;
    int m_bytesPerPacket;
    AFtrack *m_track;

    virtual ssize_t read(void *buffer, size_t count) = 0;
    virtual int decodeBlock(const uint8_t *input, int16_t *output) = 0;
    virtual AFframecount tell() = 0;
    virtual void reportReadError(AFframecount framesRead, AFframecount framesToRead) = 0;
public:
    void runPull();
};
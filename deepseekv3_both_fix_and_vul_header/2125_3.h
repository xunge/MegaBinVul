#include <cstdint>

using uint = unsigned int;

class ByteVector {
public:
    ByteVector mid(int, int);
    uint32_t toUInt(bool);
    int16_t toShort(bool);
};

namespace APE {
    class File {
    public:
        enum SeekType { Current };
        void seek(int, SeekType);
        ByteVector readBlock(int);
    };

    class Properties {
    public:
        void analyzeCurrent();
    private:
        struct Data {
            File* file;
            int16_t channels;
            uint32_t sampleRate;
            int16_t bitsPerSample;
            uint32_t length;
            uint32_t streamLength;
            uint32_t bitrate;
        } *d;
    };
}
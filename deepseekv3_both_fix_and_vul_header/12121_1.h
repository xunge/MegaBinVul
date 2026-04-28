#include <vector>
#include <cstdint>

#define RLE4_COMPRESSION 2

class BmpInput {
public:
    struct DIBHeader {
        uint32_t compression;
    };
    struct ImageSpec {
        int width;
        int height;
        size_t image_pixels() const;
        void attribute(const char*, const char*);
    };

    bool ioread(void* buf, size_t size);
    void errorfmt(const char* fmt, ...);
    bool read_rle_image();

    DIBHeader m_dib_header;
    ImageSpec m_spec;
    std::vector<uint8_t> m_uncompressed;

    static int round_to_multiple(int value, int multiple);
};
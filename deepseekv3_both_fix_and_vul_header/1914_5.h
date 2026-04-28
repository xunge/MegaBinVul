#include <vector>
#include <csetjmp>
#include <cstdint>
#include <cstdio>
#include <string>

using String = std::string;

struct JpegInput;

struct FileInformation {
    std::vector<unsigned> sizes;
    unsigned tensorElements;
    std::vector<float> pixelSize;
    String colorSpace;
};

FileInformation GetJPEGInfo(JpegInput const& jpeg);

struct JpegInput {
    struct jpeg_decompress_struct {
        int num_components;
        int out_color_space;
    } cinfo_;
    struct jpeg_error_mgr {
    } jerr_;
    FILE* file_;
    
    JpegInput(String const& filename);
    JpegInput(String const& filename, jmp_buf& setjmp_buffer);
    ~JpegInput();
    jpeg_decompress_struct& cinfo();
    jpeg_decompress_struct* cinfoptr();
};

struct Image {
    void* Origin();
    std::vector<int32_t> Strides();
    int32_t TensorStride();
    void ReForge(std::vector<unsigned> const& sizes, unsigned tensorElements, int dataType, int option);
    void SetPixelSize(std::vector<float> const& pixelSize);
    void SetColorSpace(String const& colorSpace);
};

typedef unsigned char JSAMPLE;
typedef uint8_t uint8;
typedef int32_t sint;
typedef unsigned uint;

enum {
    JCS_RGB,
    JCS_GRAYSCALE
};

enum {
    DT_UINT8
};

namespace Option {
    enum AcceptDataTypeChange {
        DONT_ALLOW
    };
}

void jpeg_start_decompress(JpegInput::jpeg_decompress_struct*);
void jpeg_read_scanlines(JpegInput::jpeg_decompress_struct*, JSAMPLE**, int);
void jpeg_finish_decompress(JpegInput::jpeg_decompress_struct*);

extern jmp_buf setjmp_buffer;

#define DIP__DECLARE_JPEG_EXIT(msg)

namespace dip {
    typedef uint8_t uint8;
    typedef unsigned uint;
}
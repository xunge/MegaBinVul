#include <vector>
#include <string>
#include <cstdio>
#include <cstddef>
#include <cstdarg>

struct ico_palette_entry {
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char reserved;
};

#define OIIO_DASSERT(expr) ((void)0)

struct ImageSpec {
    size_t scanline_bytes() { return width * 4; }
    size_t image_bytes() { return width * height * 4; }
    int width;
    int height;
};

class ICOInput {
public:
    bool readimg();
    
private:
    void* m_png;
    void* m_info;
    ImageSpec m_spec;
    std::vector<unsigned char> m_buf;
    int m_palette_size;
    int m_bpp;
    FILE* m_file;

    bool fread_wrapper(void* ptr, size_t size, size_t count) {
        return fread(ptr, size, count, m_file) == count;
    }
};

namespace PNG_pvt {
    std::string read_into_buffer(void* png, void* info, ImageSpec& spec, std::vector<unsigned char>& buf);
}

void errorf(const char* format, ...);
void errorfmt(const char* format, ...);

#define fread(ptr, size, count) fread(ptr, size, count, m_file)
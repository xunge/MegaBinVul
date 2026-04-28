#include <stdexcept>
#include <cstdarg>

class PixelBuffer {
protected:
    int width_;
    int height_;
public:
    void setSize(int width, int height);
};

namespace rfb {
    class Exception : public std::runtime_error {
    public:
        Exception(const char* format, ...);
    };
}

extern int maxPixelBufferWidth;
extern int maxPixelBufferHeight;
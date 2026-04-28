#include <stdexcept>

namespace rdr {
  typedef unsigned char U8;
}

namespace rfb {
  class Exception : public std::runtime_error {
  public:
    Exception(const char* format, ...);
  };
}

class ModifiablePixelBuffer {
public:
  void setSize(int width, int height);
};

class FullFramePixelBuffer : public ModifiablePixelBuffer {
public:
  void setBuffer(int width, int height, rdr::U8* data_, int stride_);
protected:
  int maxPixelBufferWidth;
  int maxPixelBufferHeight;
  int maxPixelBufferStride;
  int stride;
  rdr::U8* data;
};
#include <cstddef>

struct FramebufferModel {
    ~FramebufferModel();
    unsigned char* m_pixelBuffer;
};
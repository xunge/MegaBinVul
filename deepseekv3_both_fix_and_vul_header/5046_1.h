#include <iostream>
#include <string>
#include <cstring>

typedef struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
} GUID;

struct ImageBuffer {
    bool isSizeSet() const { return false; }
    class Bitmap {
    public:
        void Save(const wchar_t*, const GUID*, void*) {}
    } bitmap_;
    Bitmap& bitmap() { return bitmap_; }
    
    class PixFmt {
    public:
        int width() const { return 0; }
        int height() const { return 0; }
        int stride() const { return 0; }
        const char* row_ptr(int) const { return nullptr; }
    } pixfmt_;
    PixFmt& pixfmt() { return pixfmt_; }
};

class XMLDocument {
public:
    void load(const char*) {}
};

class XMLElement {};

namespace svgpp {
    struct exception_base : public std::exception {
        const char* what() const noexcept { return ""; }
    };
    namespace tag {
        namespace error_info {
            struct xml_element {};
        }
    }
}

namespace boost {
    template<class Tag, class T>
    struct error_info {};
    
    template<class Tag, class T>
    const T* get_error_info(const error_info<Tag, T>&) { return nullptr; }
}

#if defined(RENDERER_GDIPLUS)
namespace Gdiplus {
    struct GdiplusStartupInput {};
    void GdiplusStartup(ULONG_PTR*, GdiplusStartupInput*, void*) {}
    void GdiplusShutdown(ULONG_PTR) {}
}
#endif

#if defined(RENDERER_AGG)
extern "C" {
    int stbi_write_png(const char*, int, int, int, const char*, int);
}
#endif

#if defined(RENDERER_SKIA)
namespace SkImageEncoder {
    enum Type { kPNG_Type };
    bool EncodeFile(const char*, const void*, Type, int) { return false; }
}
#define __SK_FORCE_IMAGE_DECODER_LINKING
#endif

void renderDocument(XMLDocument&, ImageBuffer&) {}
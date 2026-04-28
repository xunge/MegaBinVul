#include <stddef.h>

namespace MagickCore {
    struct Image {
        struct Image *next;
        struct Image *previous;
    };
    
    struct ExceptionInfo {
        int severity;
    };
    
    enum {
        UndefinedException,
        ImageWarning
    };

    void DestroyExceptionInfo(ExceptionInfo*);
}

namespace Magick {
    class Image {
    public:
        void read(MagickCore::Image *image, MagickCore::ExceptionInfo *exceptionInfo);
    };
}

void DestroyImageList(MagickCore::Image*);
void replaceImage(MagickCore::Image*);
int quiet();
void throwExceptionExplicit(int, const char*);

#define ThrowImageException
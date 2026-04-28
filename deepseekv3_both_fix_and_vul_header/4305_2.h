#include <limits>
#include <cstddef>
#include <cassert>

class ImageDocumentParser {
public:
    class Document* document();
    bool isDetached();
    void appendBytes(const char* data, size_t length);
};

class Document {
public:
    class LocalFrame* frame();
    class CachedImage* cachedImage();
    void imageUpdated();
    class URL url();
};

class LocalFrame {
public:
    class Settings* settings();
    class FrameLoader& loader();
};

class Settings {
public:
    bool imagesEnabled();
};

class FrameLoader {
public:
    class Client* client();
};

class Client {
public:
    bool allowImage(bool, const class URL&);
};

class CachedImage {
public:
    void appendData(const char*, size_t);
};

class URL {};

#define RELEASE_ASSERT(x) assert(x)
#include <string>
#include <cstdint>
#include <string_view>
#include <cassert>

#define DCHECK_EQ(a, b) assert((a) == (b))

struct SkBitmap {
    enum Config {
        kARGB_8888_Config
    };
    Config config() const;
    void* getPixels() const;
};

class SkAutoLockPixels {
public:
    explicit SkAutoLockPixels(const SkBitmap&);
};

struct WebImage {
    bool isNull() const;
    const SkBitmap& getSkBitmap() const;
    struct Size {
        int width;
        int height;
    };
    Size size() const;
};

struct WebURL {
    bool isEmpty() const;
    std::string spec() const;
};

struct WebString {
};

class ScopedClipboardWriterGlue {
public:
    explicit ScopedClipboardWriterGlue(void* client);
    void WriteBitmapFromPixels(void* pixels, const WebImage::Size& size);
    void WriteBookmark(const WebString& title, const std::string& url);
    void WriteHTML(const std::u16string& markup, const std::string& src_url);
};

class WebClipboardImpl {
    void* client_;
public:
    void writeImage(const WebImage& image, const WebURL& url, const WebString& title);
};

std::string URLToImageMarkup(const WebURL& url, const WebString& title);

namespace base {
    inline std::u16string UTF8ToUTF16(std::string_view utf8) {
        return std::u16string(utf8.begin(), utf8.end());
    }
}
#include <cstdint>
#include <cstddef>

struct PreviewId {};

class Image {
public:
    const class ExifData& exifData() const;
    class Io& io() const;
};

class ExifData {
public:
    class const_iterator {
    public:
        const_iterator();
        bool operator!=(const const_iterator&) const;
        long toLong() const;
        size_t count() const;
        const_iterator* operator->();
    };
    const_iterator findKey(const class ExifKey&) const;
    const_iterator end() const;
};

class ExifKey {
public:
    ExifKey(const char*);
};

class Io {
public:
    long size() const;
};

struct Param {
    const char* offsetKey_;
    const char* sizeKey_;
    const char* baseOffsetKey_;
};
extern Param param_[];

namespace Safe {
    uint32_t add(uint32_t, uint32_t);
}

class Loader {
public:
    Loader(PreviewId id, const Image& image);
protected:
    Image image_;
};

class LoaderExifJpeg : public Loader {
public:
    LoaderExifJpeg(PreviewId id, const Image& image, int parIdx);
private:
    uint32_t offset_;
    uint32_t size_;
    bool valid_;
};
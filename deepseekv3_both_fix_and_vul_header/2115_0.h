#include <cstddef>
#include <memory>
#include <new>
#include <limits>

namespace boost {
    typedef int int32_t;
}

enum ImageType {
};

enum ImageLocation {
};

class GnashImage {
public:
    typedef unsigned char value_type;
    
    GnashImage(size_t width, size_t height, ImageType type, ImageLocation location);
    
    size_t channels() const;
    size_t size() const;
    bool checkValidSize(size_t width, size_t height, size_t channels) const;
    
private:
    ImageType _type;
    ImageLocation _location;
    size_t _width;
    size_t _height;
    std::unique_ptr<value_type[]> _data;
};
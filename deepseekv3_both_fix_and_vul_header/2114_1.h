#include <cassert>
#include <cstddef>
#include <iterator>

enum ImageType {};
enum ImageLocation {};

class GnashImage {
public:
    using iterator = unsigned char*;
    
    GnashImage(iterator data, size_t width, size_t height,
               ImageType type, ImageLocation location);
    
    size_t channels() const;
    static bool checkValidSize(size_t width, size_t height, size_t channels);

private:
    ImageType _type;
    ImageLocation _location;
    size_t _width;
    size_t _height;
    iterator _data;
};
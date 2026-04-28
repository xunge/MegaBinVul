#include <stdint.h>
#include <string.h>

namespace pp {

class Point {
public:
    Point(int x, int y) : x_(x), y_(y) {}
    int x() const { return x_; }
    int y() const { return y_; }
private:
    int x_;
    int y_;
};

class Size {
public:
    Size(int width, int height) : width_(width), height_(height) {}
    int width() const { return width_; }
    int height() const { return height_; }
private:
    int width_;
    int height_;
};

class Rect {
public:
    Rect(const Point& point, const Size& size) : point_(point), size_(size) {}
    bool IsEmpty() const { return size_.width() <= 0 || size_.height() <= 0; }
    int x() const { return point_.x(); }
    int y() const { return point_.y(); }
    int width() const { return size_.width(); }
    int height() const { return size_.height(); }
    Point point() const { return point_; }
    Size size() const { return size_; }
private:
    Point point_;
    Size size_;
};

class ImageData {
public:
    const uint32_t* GetAddr32(const Point& point) const { return nullptr; }
    uint32_t* GetAddr32(const Point& point) { return nullptr; }
    int stride() const { return 0; }
};

}  // namespace pp

namespace base {

template <typename T>
class CheckedNumeric {
public:
    CheckedNumeric(T value) : value_(value) {}
    T ValueOrDie() const { return value_; }
    CheckedNumeric& operator*=(T value) { value_ *= value; return *this; }
private:
    T value_;
};

}  // namespace base

#define DCHECK(condition) ((void)0)

bool ImageDataContainsRect(const pp::ImageData& image, const pp::Rect& rect) { return false; }

typedef uint32_t uint32;
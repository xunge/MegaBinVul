#include <list>
#include <cassert>

namespace pp {

class Size {
public:
    Size();
    Size(int width, int height);
    int width() const;
    int height() const;
};

class Point {
public:
    Point();
    Point(int x, int y);
    Point operator-(const Point& point) const;
    int x() const;
    int y() const;
};

class Rect {
public:
    Rect();
    Rect(const Size& size);
    Rect(const Point& point, const Size& size);
    Rect Intersect(const Rect& rect) const;
    bool IsEmpty() const;
    void Offset(int x, int y);
    int x() const;
    int y() const;
    int width() const;
    int height() const;
    Point point() const;
    Size size() const;
};

class ImageData {
public:
    ImageData(void* instance, int format, const Size& size, bool init_to_zero);
    bool is_null() const;
    const Size& size() const;
    int format() const;
};

}  // namespace pp

class Control {
public:
    void* GetInstance();
    Control* owner();
    const pp::Rect& rect() const;
    void MoveTo(const pp::Point& point, bool invalidate);
    void Paint(pp::ImageData* image_data, const pp::Rect& rect);
    void CopyImage(const pp::ImageData& src, const pp::Rect& src_rect,
                  pp::ImageData* dest, const pp::Rect& dest_rect, bool blend);
    void PaintMultipleRects(pp::ImageData* image_data, const std::list<pp::Rect>& rects);
};

#define DCHECK(condition) assert(condition)
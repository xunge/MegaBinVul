#include <stdint.h>
#include <memory>

namespace gfx {
class Size {
 public:
  int width() const;
  int height() const;
  int GetArea() const;
};
}  // namespace gfx

namespace media {
class VideoFrame {
 public:
  enum Plane { kAPlane };
  int stride(Plane plane) const;
  uint8_t* data(Plane plane);
  uint8_t* visible_data(Plane plane);
  const gfx::Size& coded_size() const;
};
}  // namespace media

using VideoFrame = media::VideoFrame;

template <typename T>
class scoped_refptr {
 public:
  T* operator->() const;
  T* get() const;
};